#pragma once

#include "../syntax.tab.h"
#include "../type.hpp"
#include "error.h"
#include "node.h"

#include <symbol_table.hpp>
#include <vector>
#include <unordered_set>

struct Expression
{
    struct Field *field;
    bool isLeftValue;
};

int _int(Node *node)
{
    return strtol(node->text, nullptr, 10);
}

char *id(Node *node)
{
    return node->text;
}

Type *type(Node *node)
{
#ifdef debug
    printf("node_token: %d\n", node->_token);
#endif
    if (node->_token == TYPE)
    {
        if (strcmp(node->text, "int") == 0)
            return new Type(Primitive::INT);
        else if (strcmp(node->text, "float") == 0)
            return new Type(Primitive::FLOAT);
        else if (strcmp(node->text, "char") == 0)
            return new Type(Primitive::CHAR);
    }
    return new Type((Primitive)node->type);
}

Type *_type_exist(Type *type, int lineno)
{
    if (type->category != Category::STRUCT)
        return nullptr;
    auto entry = SYMBOL_TABLE.find(type->structure->name, EntryType::TYPE);
    if (entry == nullptr)
        return nullptr;
    Type *t = entry->type;
    if (t == nullptr)
        semantic_error(lineno, "Type not exist"); //, type->structure->name.c_str());
    return t;
}

Type *specifier(Node *node);
Expression *exp(Node *node);
void comp_st(Node *node, Type *ret_type, std::vector<Field *> params = std::vector<Field *>());

Field *var_dec(Node *node, Type *type)
{
#ifdef debug
    printf("var_dec\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
#endif
    if (node->type == NodeType::VarDec)
        return new Field{node->children[0]->text, type, node->lineno};

    if (node->type == NodeType::VarDecArray)
        return var_dec(node->children[0], new Type(new Array{type, _int(node->children[2])}));

    return nullptr;
}

Field *dec(Node *node, Type *type)
{
#ifdef debug
    printf("dec\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
#endif
    Field *field = var_dec(node->children[0], type);
    if (node->type == NodeType::DecWithAssign)
    {
        Field *e = exp(node->children[2])->field;
        if (!e->type->equals(type))
            semantic_error(ErrorType::SemanticType5, node->lineno, "");
    }
#ifdef debug
    cout << "=====================" << field->name << endl;
#endif
    return field;
}
std::vector<Field *> dec_list(Node *node, Type *type)
{
#ifdef debug
    printf("dec_list\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
#endif
    Field *field = dec(node->children[0], type);
    auto head = std::vector<Field *>{field};
    if (node->type == NodeType::VarDecListMultiple)
    {
        auto tail = dec_list(node->children[2], type);
        head.insert(head.end(), tail.begin(), tail.end());
    }
    return head;
}

std::vector<Field *> def(Node *node)
{
#ifdef debug
    printf("def\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
    printf("%s\n", node->text);
#endif
    Type *type = specifier(node->children[0]);
    if (type == nullptr)
    {
        printf("fatal error");
        exit(-1);
    }
    Type *derived = _type_exist(type, node->lineno);
    if (derived == nullptr)
        return dec_list(node->children[1], type);
    else
        return dec_list(node->children[1], derived);
}

std::vector<Field *> def_list(Node *node, bool insert_now = false)
{
#ifdef debug
    printf("def_list\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
#endif
    auto head = std::vector<Field *>();
    if (node && node->type == NodeType::DefList)
    {
        head = def(node->children[0]);
        if (insert_now)
        {
            for (int i = 0; i < head.size(); i++)
            {
                SYMBOL_TABLE.insert(new SymbolTableEntry(head[i], head[i]->lineno));
            }
        }
        auto tail = def_list(node->children[1], insert_now);
        head.insert(head.end(), tail.begin(), tail.end());
    }
#ifdef debug
    printf("end\n");
#endif
    return head;
}

Type *struct_specifier(Node *node)
{
    Struct *structure = new Struct;
    structure->name = id(node->children[1]);
    structure->fields = std::vector<Field *>();

    if (node->type == NodeType::StructSpecifierWithBody)
    {
        structure->fields = def_list(node->children[3]);

        std::unordered_set<std::string> s;
        std::vector<Field *> res{};
        for (auto f : structure->fields)
        {
            if (s.find(f->name) != s.end())
                semantic_error(f->lineno,
                               "Repeated field name inside structure",
                               f->name.c_str());
            s.insert(f->name);
        }
    }
    return new Type(structure);
}

Type *specifier(Node *node)
{
#ifdef debug
    printf("specifier\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
#endif
    if (node == nullptr)
        return nullptr;
    if (node->type == NodeType::Specifier)
    {
        return type(node->children[0]);
    }
    else if (node->type == NodeType::StructSpecifier)
    {
        return struct_specifier(node->children[0]);
    }
    return nullptr;
}

std::vector<Field *> ext_dec_list(Node *node, Type *type)
{
#ifdef debug
    printf("ext_dec_list\n");
#endif
    // printf("%d
    Field *field = var_dec(node->children[0], type);
    auto head = std::vector<Field *>{field};
    if (node->type == NodeType::ExtDecListMultiple)
    {
        auto tail = ext_dec_list(node->children[2], type);
        head.insert(head.end(), tail.begin(), tail.end());
    }
    return head;
}

std::vector<Field *> args(Node *node)
{
    Field *e = exp(node->children[0])->field;
    auto head = std::vector<Field *>{e};
    if (node->type == NodeType::ArgsMultiple)
    {
        auto tail = args(node->children[2]);
        head.insert(head.end(), tail.begin(), tail.end());
    }
    return head;
}

void stmt(Node *node, Type *ret_type)
{
    auto c = node->children;
    if (node->type == NodeType::StmtExp)
    {
        exp(c[0]);
    }
    if (node->type == NodeType::StmtCompSt)
    {
        comp_st(c[0], ret_type);
    }
    if (node->type == NodeType::StmtReturn)
    {
        Field *ret = exp(c[1])->field;
        if (!ret->type->equals(ret_type))
            semantic_error(ErrorType::SemanticType8, node->lineno, "");
    }
    if (node->type == NodeType::StmtIf)
    {
        exp(c[2]);
        stmt(c[4], ret_type);
    }
    if (node->type == NodeType::StmtIfElse)
    {
        exp(c[2]);
        stmt(c[4], ret_type);
        stmt(c[6], ret_type);
    }
    if (node->type == NodeType::StmtWhile)
    {
        exp(c[2]);
        stmt(c[4], ret_type);
    }
}

void stmt_list(Node *node, Type *ret_type)
{
    if (node && node->type == NodeType::StmtList)
    {
        stmt(node->children[0], ret_type);
        stmt_list(node->children[1], ret_type);
    }
}

void comp_st(Node *node, Type *ret_type, std::vector<Field *> params)
{
#ifdef debug
    printf("comp_st\n");
#endif
    SYMBOL_TABLE.scope_push(ret_type);
    for (auto param : params)
        SYMBOL_TABLE.insert(new SymbolTableEntry(param, node->lineno));
    def_list(node->children[1], true);
    stmt_list(node->children[2], ret_type);

    // SYMBOL_TABLE.print();

    SYMBOL_TABLE.scope_pop();
}

Field *param_dec(Node *node)
{
    Type *type = specifier(node->children[0]);
    return var_dec(node->children[1], type);
}

std::vector<Field *> var_list(Node *node)
{
    Field *field = param_dec(node->children[0]);
    auto head = std::vector<Field *>{field};
    if (node->type == NodeType::VarList)
    {
        auto tail = var_list(node->children[2]);
        head.insert(head.end(), tail.begin(), tail.end());
    }
    return head;
}

Func *fun_dec(Node *node, Type *ret_type)
{
    std::string name = id(node->children[0]);
    auto param_list = std::vector<Field *>();
    if (node->type == NodeType::FunDecArgs)
    {
        param_list = var_list(node->children[2]);
        for (auto param : param_list)
            _type_exist(param->type, param->lineno);
    }
    return new Func{name, param_list, ret_type};
}

void ext_def(Node *node)
{
#ifdef debug
    printf("ext_def\n");
    printf("%d\n", (int)node->type);
#endif
    Type *type = specifier(node->children[0]);
    if (node->type == NodeType::Declare)
    {
        _type_exist(type, node->lineno);
        auto fields = ext_dec_list(node->children[1], type);
        for (auto field : fields)
            SYMBOL_TABLE.insert(new SymbolTableEntry(field, field->lineno));
    }
    else if (node->type == NodeType::StructDef)
    {
        if (type->category == Category::STRUCT)
        {
            SYMBOL_TABLE.insert(new SymbolTableEntry(type, node->lineno));
        }
    }
    else if (node->type == NodeType::FuncDef)
    {
        _type_exist(type, node->lineno);
        Func *func = fun_dec(node->children[1], type);
        SYMBOL_TABLE.insert(new SymbolTableEntry(func, node->lineno));
        comp_st(node->children[2], type, func->params);
    }
}
void ext_def_list(Node *node)
{
#ifdef debug
    printf("ext_def_list\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
#endif
    if (node && node->type == NodeType::ExtDefList)
    {
        ext_def(node->children[0]);
        ext_def_list(node->children[1]);
    }
}

Expression *exp(Node *node)
{
#ifdef debug
    printf("exp\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
#endif
    auto c = node->children;
    auto error_expr = new Expression{
        new Field(new Type(Primitive::NotExpr), node->lineno),
        true};

    if (node->type == NodeType::ExpAssign)
    {
        auto exp1 = exp(c[0]), exp2 = exp(c[2]);
        if (exp1->isLeftValue == false)
            semantic_error(ErrorType::SemanticType6, node->lineno, "");

        auto oprand1 = exp1->field, oprand2 = exp2->field;

        if (!oprand1->type->equals(oprand2->type))
        {
            std::string msg =
                to_str(oprand1->type) + "!=" + to_str(oprand2->type);
            semantic_error(ErrorType::SemanticType5, node->lineno, msg.c_str());
        }
        return new Expression{
            new Field{new Type(*oprand1->type), node->lineno},
            false};
    }
    if (node->type == NodeType::ExpAnd || node->type == NodeType::ExpOr)
    {
        auto exp1 = exp(c[0]), exp2 = exp(c[2]);
        auto oprand1 = exp1->field, oprand2 = exp2->field;
        auto category_1 = oprand1->type->category;
        auto category_2 = oprand2->type->category;
        if (category_1 != Category::PRIMITIVE ||
            category_2 != Category::PRIMITIVE)
        {
            semantic_error(node->lineno,
                           "Only INT type can not be used in boolean operator",
                           "");
            return error_expr;
        }
        auto primitive_1 = oprand1->type->primitive;
        auto primitive_2 = oprand2->type->primitive;
        if (primitive_1 != Primitive::INT ||
            primitive_2 != Primitive::INT)
        {
            semantic_error(node->lineno,
                           "Only INT type can not be used in boolean operator",
                           "");
            return error_expr;
        }
        return new Expression{
            new Field{new Type(*oprand1->type), node->lineno},
            false};
    }
    if (node->type == NodeType::ExpLT ||
        node->type == NodeType::ExpGT ||
        node->type == NodeType::ExpLE ||
        node->type == NodeType::ExpGE ||
        node->type == NodeType::ExpEQ ||
        node->type == NodeType::ExpNE)
    {
        auto exp1 = exp(c[0]), exp2 = exp(c[2]);
        auto oprand1 = exp1->field, oprand2 = exp2->field;
        auto category_1 = oprand1->type->category;
        auto category_2 = oprand2->type->category;
        if (category_1 != Category::PRIMITIVE ||
            category_2 != Category::PRIMITIVE)
        {
            semantic_error(ErrorType::SemanticType7, node->lineno, "");
            return error_expr;
        }
        auto primitive_1 = oprand1->type->primitive;
        auto primitive_2 = oprand2->type->primitive;

        if (primitive_1 == Primitive::CHAR ||
            primitive_2 == Primitive::CHAR)
        {

            if (
                node->type != NodeType::ExpEQ &&
                node->type != NodeType::ExpNE)
            {

                semantic_error(node->lineno,
                               "CHAR type can not be used in arithmetic operator",
                               "");
                return error_expr;
            }
        }
        return new Expression{
            new Field{new Type(*oprand1->type), node->lineno},
            false};
    }
    if (node->type == NodeType::ExpPlus ||
        node->type == NodeType::ExpMinus ||
        node->type == NodeType::ExpMul ||
        node->type == NodeType::ExpDiv)
    {
        auto exp1 = exp(c[0]), exp2 = exp(c[2]);
        auto oprand1 = exp1->field, oprand2 = exp2->field;
        auto category_1 = oprand1->type->category;
        auto category_2 = oprand2->type->category;
        if (category_1 != Category::PRIMITIVE ||
            category_2 != Category::PRIMITIVE)
        {
            semantic_error(ErrorType::SemanticType7, node->lineno, "");
            return error_expr;
        }
        auto primitive_1 = oprand1->type->primitive;
        auto primitive_2 = oprand2->type->primitive;

        if (primitive_1 == Primitive::CHAR ||
            primitive_2 == Primitive::CHAR)
        {
            semantic_error(node->lineno,
                           "CHAR type can not be used in arithmetic operator",
                           "");
            return error_expr;
        }
        return new Expression{
            new Field{new Type(*oprand1->type), node->lineno},
            false};
    }
    if (node->type == NodeType::ExpNegative || node->type == NodeType::ExpNot)
    {
        auto oprand = exp(c[1])->field;
        if (oprand->type->category != Category::PRIMITIVE)
        {
            semantic_error(node->lineno,
                           "Derived type can not be used in negative operator",
                           "");
            return error_expr;
        }
        if (node->type == NodeType::ExpNegative &&
            oprand->type->primitive == Primitive::CHAR)
        {
            semantic_error(node->lineno,
                           "CHAR type can not be used in negative operator",
                           "");
            return error_expr;
        }
        if (node->type == NodeType::ExpNot &&
            oprand->type->primitive != Primitive::INT)
        {
            semantic_error(node->lineno,
                           "Only INT type can be used in not operator",
                           "");
            return error_expr;
        }
        return new Expression{
            new Field{new Type(*oprand->type), node->lineno},
            false};
    }
    if (node->type == NodeType::ExpBracketWrapped)
    {
        auto e = exp(c[1])->field;
        return new Expression{
            new Field{e->name, new Type(*(e->type)), e->lineno},
            false};
    }
    if (node->type == NodeType::ExpArgsFuncCall ||
        node->type == NodeType::ExpFuncCall)
    {
        std::string func_name = id(c[0]);
        auto func_entry = SYMBOL_TABLE.find(func_name, EntryType::FUNC);
        if (func_entry == nullptr)
        {
            if (SYMBOL_TABLE.find(func_name))
                semantic_error(ErrorType::SemanticType11, node->lineno, func_name.c_str());
            else
                semantic_error(ErrorType::SemanticType2, node->lineno, func_name.c_str());
            return error_expr;
        }
        Func *func = func_entry->func;
        std::vector<Field *> arguments{};
        if (node->type == NodeType::ExpArgsFuncCall)
            arguments = args(c[2]);
        if (func->params.size() != arguments.size())
        {

            semantic_error(ErrorType::SemanticType9, node->lineno, func_name.c_str());

            return new Expression{
                new Field{"Exp", new Type(*func->ret), node->lineno},
                false};
        }
        for (int i = 0; i < arguments.size(); i++)
        {
            if (func->params[i]->type->equals(arguments[i]->type))
                continue;
            semantic_error(node->lineno,
                           "Argument type does not match",
                           func_name.c_str());
            return new Expression{
                new Field{"Exp", new Type(*func->ret), node->lineno},
                false};
        }
        return new Expression{
            new Field{new Type(*func->ret), node->lineno},
            false};
    }
    if (node->type == NodeType::ExpArrayIndex)
    {
        Field *field = exp(c[0])->field;
        if (field->type->category != Category::ARRAY)
        {
            semantic_error(ErrorType::SemanticType10, node->lineno, field->name.c_str());
            return error_expr;
        }
        Array *arr = field->type->array;

        Field *idx = exp(c[2])->field;
        if (idx->type->category != Category::PRIMITIVE ||
            idx->type->primitive != Primitive::INT)
        {
            semantic_error(ErrorType::SemanticType12, node->lineno, field->name.c_str());
            return error_expr;
        }
        return new Expression{
            new Field{new Type(*arr->type), node->lineno},
            true};
    }
    if (node->type == NodeType::ExpFiledAccess)
    {
        Field *s = exp(c[0])->field;
        std::string field_name = id(c[2]);
        if (s->type->category != Category::STRUCT)
        {
            semantic_error(ErrorType::SemanticType13, node->lineno, s->name.c_str());
            return error_expr;
        }
        auto fields = s->type->structure->fields;
        for (auto i : fields)
        {
            if (i->name != field_name)
                continue;
            return new Expression{
                new Field{new Type(*(i->type)), i->lineno},
                true};
        }
        semantic_error(ErrorType::SemanticType14, node->lineno, field_name.c_str());
        return error_expr;
    }
    if (node->type == NodeType::ExpId)
    {
        std::string var_name = id(c[0]);
        auto var_entry = SYMBOL_TABLE.find(var_name, EntryType::FIELD);
        if (var_entry == nullptr)
        {
            semantic_error(ErrorType::SemanticType1, node->lineno, var_name.c_str());
            return error_expr;
        }
        return new Expression{
            new Field{new Type(*var_entry->field->type), var_entry->field->lineno},
            true};
    }
    if (node->type == NodeType::ExpInt)
    {
        return new Expression{
            new Field{new Type(Primitive::INT),
                      node->lineno},
            false};
    }
    if (node->type == NodeType::ExpChar)
    {
        return new Expression{
            new Field{new Type(Primitive::CHAR),
                      node->lineno},
            false};
    }
    if (node->type == NodeType::ExpFloat)
    {
        return new Expression{
            new Field{new Type(Primitive::FLOAT),
                      node->lineno},
            false};
    }

    return error_expr;
}

void program(Node *node)
{
#ifdef debug
    printf("program\n");
#endif
    ext_def_list(node->children[0]);
}

void semantic_analysis(Node *root)
{
    program(root);
}
