#pragma once

#include "../syntax.tab.h"
#include "../type.hpp"
#include "error.h"
#include "node.h"
#include "ir.hpp"

#include <symbol_table.hpp>
#include <vector>
#include <unordered_set>
#include "basic.hpp"

struct Expression {
    struct Field *field;
    bool isLeftValue;
};
struct Args;

struct Exp {
    Expression *expression;
    Node *node;

    Args *args;
    Exp *exp1, *exp2;
    string id;
    string tag_name;

    Exp(Node *node);

    IRList generate(std::string place, pair<string, string> lbs = {"", ""});
};

struct Args {

    std::vector<Field *> fields;
    std::vector<std::string> tags;

    Args *nextArgs = nullptr;
    Exp *exp;

    explicit Args(Node *node) {
        tags.clear();
        exp = new Exp(node->children[0]);
        Field *e = exp->expression->field;
        fields = std::vector<Field *>{e};
        if (node->type == NodeType::ArgsMultiple) {
            nextArgs = new Args(node->children[2]);
            auto tail = nextArgs->fields;
            fields.insert(fields.end(), tail.begin(), tail.end());
        }
    }

    IRList generate();
};

Exp::Exp(Node *node) : node(node) {

#ifdef debug
    printf("exp\n");
if (node)
printf("lineno: %d\n", node->lineno);
#endif
    auto c = node->children;
    auto error_expr = new Expression{
            new Field(new Type(Primitive::NotExpr), node->lineno),
            true};

    expression = error_expr;

    if (node->type == NodeType::ExpAssign) {
        exp1 = new Exp(c[0]);
        auto expr1 = exp1->expression;
        exp2 = new Exp(c[2]);
        auto expr2 = exp2->expression;
        if (!expr1->isLeftValue)
            semantic_error(ErrorType::SemanticType6, node->lineno, "");

        auto oprand1 = expr1->field, oprand2 = expr2->field;

        if (!oprand1->type->equals(oprand2->type)) {
            std::string msg =
                    to_str(oprand1->type) + "!=" + to_str(oprand2->type);
            semantic_error(ErrorType::SemanticType5, node->lineno, msg.c_str());
        }
        expression = new Expression{new Field{new Type(*oprand1->type), node->lineno}, false};
    }
    if (node->type == NodeType::ExpAnd || node->type == NodeType::ExpOr) {
        exp1 = new Exp(c[0]);
        exp2 = new Exp(c[2]);
        auto expr1 = exp1->expression, expr2 = exp2->expression;
        auto oprand1 = expr1->field, oprand2 = expr2->field;
        auto category_1 = oprand1->type->category;
        auto category_2 = oprand2->type->category;
        if (category_1 != Category::PRIMITIVE ||
            category_2 != Category::PRIMITIVE) {
            semantic_error(node->lineno,
                           "Only INT type can not be used in boolean operator",
                           "");
            expression = error_expr;
            return;
        }
        auto primitive_1 = oprand1->type->primitive;
        auto primitive_2 = oprand2->type->primitive;
        if (primitive_1 != Primitive::INT ||
            primitive_2 != Primitive::INT) {
            semantic_error(node->lineno,
                           "Only INT type can not be used in boolean operator",
                           "");
            expression = error_expr;
            return;
        }
        expression = new Expression{
                new Field{new Type(*oprand1->type), node->lineno},
                false};
    }
    if (node->type == NodeType::ExpLT ||
        node->type == NodeType::ExpGT ||
        node->type == NodeType::ExpLE ||
        node->type == NodeType::ExpGE ||
        node->type == NodeType::ExpEQ ||
        node->type == NodeType::ExpNE) {

        exp1 = new Exp(c[0]);
        exp2 = new Exp(c[2]);
        auto expr1 = exp1->expression, expr2 = exp2->expression;
        auto oprand1 = expr1->field, oprand2 = expr2->field;
        auto category_1 = oprand1->type->category;
        auto category_2 = oprand2->type->category;
        if (category_1 != Category::PRIMITIVE ||
            category_2 != Category::PRIMITIVE) {
            semantic_error(ErrorType::SemanticType7, node->lineno, "");
            expression = error_expr;
            return;
        }
        auto primitive_1 = oprand1->type->primitive;
        auto primitive_2 = oprand2->type->primitive;

        if (primitive_1 == Primitive::CHAR ||
            primitive_2 == Primitive::CHAR) {

            if (
                    node->type != NodeType::ExpEQ &&
                    node->type != NodeType::ExpNE) {

                semantic_error(node->lineno,
                               "CHAR type can not be used in arithmetic operator",
                               "");
                expression = error_expr;
                return;
            }
        }
        expression = new Expression{
                new Field{new Type(*oprand1->type), node->lineno},
                false};
    }
    if (node->type == NodeType::ExpPlus ||
        node->type == NodeType::ExpMinus ||
        node->type == NodeType::ExpMul ||
        node->type == NodeType::ExpDiv) {
        exp1 = new Exp(c[0]);
        exp2 = new Exp(c[2]);
        auto expr1 = exp1->expression, expr2 = exp2->expression;
        auto oprand1 = expr1->field, oprand2 = expr2->field;
        auto category_1 = oprand1->type->category;
        auto category_2 = oprand2->type->category;
        if (category_1 != Category::PRIMITIVE ||
            category_2 != Category::PRIMITIVE) {
            semantic_error(ErrorType::SemanticType7, node->lineno, "");
            expression = error_expr;
            return;
        }
        auto primitive_1 = oprand1->type->primitive;
        auto primitive_2 = oprand2->type->primitive;

        if (primitive_1 == Primitive::CHAR ||
            primitive_2 == Primitive::CHAR) {
            semantic_error(node->lineno,
                           "CHAR type can not be used in arithmetic operator",
                           "");
            expression = error_expr;
            return;
        }
        expression = new Expression{
                new Field{new Type(*oprand1->type), node->lineno},
                false};
    }
    if (node->type == NodeType::ExpNegative || node->type == NodeType::ExpNot) {
        exp1 = new Exp(c[1]);
        auto oprand = exp1->expression->field;
        if (oprand->type->category != Category::PRIMITIVE) {
            semantic_error(node->lineno,
                           "Derived type can not be used in negative operator",
                           "");
            expression = error_expr;
            return;
        }
        if (node->type == NodeType::ExpNegative &&
            oprand->type->primitive == Primitive::CHAR) {
            semantic_error(node->lineno,
                           "CHAR type can not be used in negative operator",
                           "");
            expression = error_expr;
            return;
        }
        if (node->type == NodeType::ExpNot &&
            oprand->type->primitive != Primitive::INT) {
            semantic_error(node->lineno,
                           "Only INT type can be used in not operator",
                           "");
            expression = error_expr;
            return;
        }
        expression = new Expression{
                new Field{new Type(*oprand->type), node->lineno},
                false};
    }
    if (node->type == NodeType::ExpBracketWrapped) {
        exp1 = new Exp(c[1]);
        auto e = exp1->expression->field;
        expression = new Expression{
                new Field{e->name, new Type(*(e->type)), e->lineno},
                false};
    }
    if (node->type == NodeType::ExpArgsFuncCall ||
        node->type == NodeType::ExpFuncCall) {
        std::string func_name = idOf(c[0]);

        /* Special Care for R/W function */
        if (func_name == "read") {
            /* Args -> Arg -> Exp */
            expression = new Expression{
                    new Field{new Type(Primitive::INT), node->lineno},
                    false};
            return;
        }
        if (func_name == "write") {
            if (node->type == NodeType::ExpFuncCall) {
                semantic_error(node->lineno, "missing arguments");
                return;
            }
            args = new Args(c[2]);
            expression = new Expression{
                    new Field{new Type(Primitive::INT), node->lineno},
                    false};
            return;
        }

        auto func_entry = SYMBOL_TABLE.find(func_name, EntryType::FUNC);
        if (func_entry == nullptr) {
            if (SYMBOL_TABLE.find(func_name))
                semantic_error(ErrorType::SemanticType11, node->lineno, func_name.c_str());
            else
                semantic_error(ErrorType::SemanticType2, node->lineno, func_name.c_str());
            expression = error_expr;
            return;
        }
        Func *func = func_entry->func;
        std::vector<Field *> arguments{};
        if (node->type == NodeType::ExpArgsFuncCall) {
            args = new Args(c[2]);
            arguments = args->fields;
        }
        if (func->params.size() != arguments.size()) {

            semantic_error(ErrorType::SemanticType9, node->lineno, func_name.c_str());

            expression = new Expression{
                    new Field{"Exp", new Type(*func->ret), node->lineno},
                    false};
            return;
        }
        for (int i = 0; i < arguments.size(); i++) {
            if (func->params[i]->type->equals(arguments[i]->type))
                continue;
            semantic_error(node->lineno,
                           "Argument type does not match",
                           func_name.c_str());
            expression = new Expression{
                    new Field{"Exp", new Type(*func->ret), node->lineno},
                    false};
            return;
        }
        expression = new Expression{
                new Field{new Type(*func->ret), node->lineno},
                false};
    }
    if (node->type == NodeType::ExpArrayIndex) {
        exp1 = new Exp(c[0]);
        Field *field = exp1->expression->field;
        if (field->type->category != Category::ARRAY) {
            semantic_error(ErrorType::SemanticType10, node->lineno, field->name.c_str());
            expression = error_expr;
            return;
        }
        Array *arr = field->type->array;

        exp2 = new Exp(c[2]);
        Field *idx = exp2->expression->field;
        if (idx->type->category != Category::PRIMITIVE ||
            idx->type->primitive != Primitive::INT) {
            semantic_error(ErrorType::SemanticType12, node->lineno, field->name.c_str());
            expression = error_expr;
            return;
        }
        id = exp1->id;
        expression = new Expression{
                new Field{new Type(*(arr->type)), node->lineno},
                true};
    }
    if (node->type == NodeType::ExpFieldAccess) {
        exp1 = new Exp(c[0]);
        Field *s = exp1->expression->field;
        std::string field_name = idOf(c[2]);
        if (s->type->category != Category::STRUCT) {
            semantic_error(ErrorType::SemanticType13, node->lineno, s->name.c_str());
            expression = error_expr;
            return;
        }
        auto fields = s->type->structure->fields;
        for (auto i : fields) {
            if (i->name != field_name)
                continue;
            expression = new Expression{
                    new Field{new Type(*(i->type)), i->lineno},
                    true};
            return;
        }
        semantic_error(ErrorType::SemanticType14, node->lineno, field_name.c_str());
        expression = error_expr;
    }
    if (node->type == NodeType::ExpId) {
        id = idOf(c[0]);
        auto var_entry = SYMBOL_TABLE.find(id, EntryType::FIELD);
        if (var_entry == nullptr) {
            semantic_error(ErrorType::SemanticType1, node->lineno, id.c_str());
            expression = error_expr;
            return;
        }
        expression = new Expression{
                new Field{new Type(*var_entry->field->type), var_entry->field->lineno},
                true};
    }
    if (node->type == NodeType::ExpInt) {
        expression = new Expression{
                new Field{new Type(Primitive::INT),
                          node->lineno},
                false};
    }
    if (node->type == NodeType::ExpChar) {
        expression = new Expression{
                new Field{new Type(Primitive::CHAR),
                          node->lineno},
                false};
    }
    if (node->type == NodeType::ExpFloat) {
        expression = new Expression{
                new Field{new Type(Primitive::FLOAT),
                          node->lineno},
                false};
    }
}


struct Def;

struct DefList {
    Def *def = nullptr;
    DefList *nextDefList = nullptr;

    std::vector<Field *> fields;

    Node *node;
    bool insert_now;


    DefList(Node *node, bool insert_now = false);

    IRList generate();
};


struct StmtList;

struct CompSt {
    DefList *defList = nullptr;
    StmtList *stmtList = nullptr;

    Type *ret_type;
    std::vector<Field *> params;
    Node *node;

    CompSt(Node *node, Type *ret_type, std::vector<Field *> params = std::vector<Field *>());

    IRList generate();
};

struct Stmt {
    Exp *exp = nullptr;
    Stmt *stmt1 = nullptr, *stmt2 = nullptr;
    CompSt *compSt = nullptr;

    Node *node;
    Type *ret_type;

    Stmt(Node *node, Type *ret_type) : node(node), ret_type(ret_type) {
        auto c = node->children;
        if (node->type == NodeType::StmtExp) {
            exp = new Exp(c[0]);
        }
        if (node->type == NodeType::StmtCompSt) {
            compSt = new CompSt(c[0], ret_type);
        }
        if (node->type == NodeType::StmtReturn) {
            exp = new Exp(c[1]);
            Field *ret = exp->expression->field;
            if (!ret->type->equals(ret_type))
                semantic_error(ErrorType::SemanticType8, node->lineno, "");
        }
        if (node->type == NodeType::StmtIf) {
            exp = new Exp(c[2]);
            stmt1 = new Stmt(c[4], ret_type);
        }
        if (node->type == NodeType::StmtIfElse) {
            exp = new Exp(c[2]);
            stmt1 = new Stmt(c[4], ret_type);
            stmt2 = new Stmt(c[6], ret_type);
        }
        if (node->type == NodeType::StmtWhile) {
            exp = new Exp(c[2]);
            stmt1 = new Stmt(c[4], ret_type);
        }
    }

    IRList generate();
};


struct StructSpecifier {
    DefList *defList = nullptr;
    Type *type = nullptr;

    explicit StructSpecifier(Node *node) {
        Struct *structure = new Struct;
        string name = idOf(node->children[1]);
        auto entry = SYMBOL_TABLE.find(name, EntryType::TYPE);
        if (entry != nullptr && entry->type->category == Category::STRUCT) {
            type = entry->type;
            return;
        }
        structure->name = name;
        structure->fields = std::vector<Field *>();

        if (node->type == NodeType::StructSpecifierWithBody) {
            defList = new DefList(node->children[3]);
            structure->fields = defList->fields;

            std::unordered_set<std::string> s;
            std::vector<Field *> res{};
            for (auto f : structure->fields) {
                if (s.find(f->name) != s.end())
                    semantic_error(f->lineno,
                                   "Repeated field name inside structure",
                                   f->name.c_str());
                s.insert(f->name);
            }
        }
        type = new Type(structure);
    }

    IRList generate();
};

struct Specifier {
    Type *type = nullptr;
    StructSpecifier *structSpecifier = nullptr;

    explicit Specifier(Node *node) {
#ifdef debug
        printf("specifier\n");
if (node)
printf("lineno: %d\n", node->lineno);
#endif
        if (node == nullptr)
            return;
        if (node->type == NodeType::Specifier) {
            type = typeOf(node->children[0]);
        } else if (node->type == NodeType::StructSpecifier) {
            structSpecifier = new StructSpecifier(node->children[0]);
            type = structSpecifier->type;
        }
    }

    IRList generate();
};


struct VarDec {

    Field *field = nullptr;
    VarDec *nextVarDec = nullptr;

    Node *node;
    Type *type;

    VarDec(Node *node, Type *type) : node(node), type(type) {
#ifdef debug
        printf("var_dec\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
#endif
        if (node->type == NodeType::VarDec)
            field = new Field{node->children[0]->text, type, node->lineno};

        if (node->type == NodeType::VarDecArray) {
            nextVarDec = new VarDec(node->children[0], new Type(new Array{type, _int(node->children[2])}));
            field = nextVarDec->field;
            this->type = field->type;
        }
    }

    IRList generate();
};

struct Dec {

    Field *field = nullptr;

    VarDec *varDec = nullptr;

    Exp *exp = nullptr;

    Node *node = nullptr;
    Type *type = nullptr;

    Dec(Node *node, Type *type);

    IRList generate();
};


struct DecList {
    Dec *dec = nullptr;
    DecList *nextDecList = nullptr;
    std::vector<Field *> fields;
    Node *node;
    Type *type;

    DecList(Node *node, Type *type) : node(node), type(type) {
#ifdef debug
        printf("dec_list\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
#endif
        dec = new Dec(node->children[0], type);
        Field *field = dec->field;
        fields = std::vector<Field *>{field};
        if (node->type == NodeType::VarDecListMultiple) {
            nextDecList = new DecList(node->children[2], type);
            auto nextFields = nextDecList->fields;
            fields.insert(fields.end(), nextFields.begin(), nextFields.end());
        }
    }

    IRList generate();
};

struct Def {
    Specifier *specifier = nullptr;
    DecList *decList = nullptr;

    std::vector<Field *> fields;

    Type *type = nullptr, *derived = nullptr;

    Def(Node *node) {
#ifdef debug
        printf("def\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
    printf("%s\n", node->text);
#endif
        specifier = new Specifier(node->children[0]);
        type = specifier->type;
        if (type == nullptr) {
            printf("fatal error");
            exit(-1);
        }
        derived = _type_exist(type, node->lineno);
        if (derived == nullptr)
            decList = new DecList(node->children[1], type);
        else
            decList = new DecList(node->children[1], derived);
        fields = decList->fields;
    }

    IRList generate();
};

DefList::DefList(Node *node, bool insert_now) : node(node), insert_now(insert_now) {
#ifdef debug
    printf("def_list\n");
if (node)
printf("lineno: %d\n", node->lineno);
#endif
    fields = std::vector<Field *>();
    if (node && node->type == NodeType::DefList) {
        def = new Def(node->children[0]);
        fields = std::vector<Field *>(def->fields);
        if (insert_now) {
            for (auto field: fields) {
                SYMBOL_TABLE.insert(new SymbolTableEntry(field, field->lineno));
            }
        }
        nextDefList = new DefList(node->children[1], insert_now);
        auto nextFields = nextDefList->fields;
        fields.insert(fields.end(), nextFields.begin(), nextFields.end());
//        for (auto field: fields) {
//            cout << field->name << endl;
//        }
//        cout << endl;
    }
}


struct StmtList {
    Stmt *stmt = nullptr;
    StmtList *nextStmtList = nullptr;

    Node *node;
    Type *ret_type;

    StmtList(Node *node, Type *ret_type) : node(node), ret_type(ret_type) {
        if (node && node->type == NodeType::StmtList) {
            stmt = new Stmt(node->children[0], ret_type);
            nextStmtList = new StmtList(node->children[1], ret_type);
        }
    }

    IRList generate();
};


struct ParamDec {
    Specifier *specifier = nullptr;
    VarDec *varDec = nullptr;
    Field *field = nullptr;

    ParamDec(Node *node) {
        specifier = new Specifier(node->children[0]);
        Type *type = specifier->type;
        _type_exist(type, node->lineno);
        varDec = new VarDec(node->children[1], type);
        field = varDec->field;
    }

    IRList generate();
};


Dec::Dec(Node *node, Type *type) : node(node), type(type) {
#ifdef debug
    printf("dec\n");
if (node)
    printf("lineno: %d\n", node->lineno);
#endif
    varDec = new VarDec(node->children[0], type);
    field = varDec->field;
    if (node->type == NodeType::DecWithAssign) {
        exp = new Exp(node->children[2]);
        Field *e = exp->expression->field;
        if (!e->type->equals(type))
            semantic_error(ErrorType::SemanticType5, node->lineno, "");
    }
}

struct VarList {
    std::vector<Field *> fields;
    ParamDec *paramDec = nullptr;
    VarList *varList = nullptr;

    explicit VarList(Node *node) {
        paramDec = new ParamDec(node->children[0]);
        Field *field = paramDec->field;
        fields = std::vector<Field *>{field};
        if (node->type == NodeType::VarList) {
            varList = new VarList(node->children[2]);
            auto tail = varList->fields;
            fields.insert(fields.end(), tail.begin(), tail.end());
        }
    }

    IRList generate();
};

CompSt::CompSt(Node *node, Type *ret_type, std::vector<Field *> params) : node(node), ret_type(ret_type),
                                                                          params(params) {
#ifdef debug
    printf("CompSt\n");
#endif
    SYMBOL_TABLE.scope_push(ret_type);
    for (auto param : params)
        SYMBOL_TABLE.insert(new SymbolTableEntry(param, node->lineno));
//    SYMBOL_TABLE.print();
    defList = new DefList(node->children[1], true);
    stmtList = new StmtList(node->children[2], ret_type);

    SYMBOL_TABLE.scope_pop();
}


struct ExtDecList {

    VarDec *varDec = nullptr;
    ExtDecList *extDecList = nullptr;

    std::vector<Field *> fields;

    ExtDecList(Node *node, Type *type) {
#ifdef debug
        printf("ext_dec_list\n");
#endif
        varDec = new VarDec(node->children[0], type);
        Field *field = varDec->field;
        fields = std::vector<Field *>{field};
        if (node->type == NodeType::ExtDecListMultiple) {
            extDecList = new ExtDecList(node->children[2], type);
            auto tail = extDecList->fields;
            fields.insert(fields.end(), tail.begin(), tail.end());
        }
    }

    IRList generate();
};


struct FunDec {
    Func *func = nullptr;
    VarList *varList = nullptr;
    std::string name;

    FunDec(Node *node, Type *ret_type) {
        name = idOf(node->children[0]);
        auto param_list = std::vector<Field *>();
        if (node->type == NodeType::FunDecArgs) {
            varList = new VarList(node->children[2]);
            param_list = varList->fields;
            for (auto param : param_list) {
                _type_exist(param->type, param->lineno);
            }
        }
        func = new Func{name, param_list, ret_type};
    }

    IRList generate();
};

struct ExtDef {
    CompSt *compSt = nullptr;
    Specifier *specifier = nullptr;
    ExtDecList *extDecList = nullptr;
    FunDec *funDec = nullptr;
    Node *node = nullptr;

    explicit ExtDef(Node *node) {
#ifdef debug
        printf("ext_def\n");
    printf("%d\n", (int)node->type);
#endif
        this->node = node;
        specifier = new Specifier(node->children[0]);
        Type *type = specifier->type;

        if (node->type == NodeType::Declare) {
            _type_exist(type, node->lineno);
            extDecList = new ExtDecList(node->children[1], type);
            auto fields = extDecList->fields;
            for (auto field : fields)
                SYMBOL_TABLE.insert(new SymbolTableEntry(field, field->lineno));
        } else if (node->type == NodeType::StructDef) {
            if (type->category == Category::STRUCT) {
                SYMBOL_TABLE.insert(new SymbolTableEntry(type, node->lineno));
            }
        } else if (node->type == NodeType::FuncDef) {
            _type_exist(type, node->lineno);
            funDec = new FunDec(node->children[1], type);
            Func *func = funDec->func;
            SYMBOL_TABLE.insert(new SymbolTableEntry(func, node->lineno));
            compSt = new CompSt(node->children[2], type, func->params);
        }
    }

    IRList generate();
};


struct ExtDefList {
    ExtDef *extDef = nullptr;
    ExtDefList *extDefList = nullptr;

    explicit ExtDefList(Node *node) {
#ifdef debug
        printf("ext_def_list\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
#endif
        if (node && node->type == NodeType::ExtDefList) {
            extDef = new ExtDef(node->children[0]);
            extDefList = new ExtDefList(node->children[1]);
        }
    }

    IRList generate();
};


struct Program {
    ExtDefList *extDefList = nullptr;
    Node *node = nullptr;

    explicit Program(Node *node) {
#ifdef debug
        printf("program\n");
#endif
        extDefList = new ExtDefList(node->children[0]);
    }

    IRList generate();
};


Program *semantic_analysis(Node *root) {
    return new Program(root);
}
