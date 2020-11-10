#pragma once

#include "../syntax.tab.h"
#include "../type.hpp"
#include "error.h"
#include "node.h"
#include <symbol_table.hpp>
#include <vector>

#define debug

bool _is_equivalent(Type *s1, Type *s2)
{
    if (s1->category != s2->category)
        return false;

    if (s1->category == Category::PRIMITIVE)
        return s1->primitive == s2->primitive;

    if (s1->category == Category::ARRAY)
        return _is_equivalent(s1->array->type, s2->array->type) &&
               s1->array->size == s2->array->size;

    if (s1->category == Category::STRUCT)
    {
        auto fields_1 = s1->structure->fields;
        auto fields_2 = s2->structure->fields;
        if (fields_1.size() != fields_2.size())
            return false;

        int s = fields_1.size();
        for (int i = 0; i < s; i++)
            if (!_is_equivalent(fields_1[i]->type, fields_2[i]->type))
                return false;

        return true;
    }

    return false;
}

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
    if (node->_token == TYPE)
    {
        if (strcmp(node->_token_name, "int") == 0)
            return new Type(Primitive::INT);
        else if (strcmp(node->_token_name, "float") == 0)
            return new Type(Primitive::FLOAT);
        else if (strcmp(node->_token_name, "char") == 0)
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

Field *var_dec(Node *node, Type *type)
{
#ifdef debug
    printf("var_dec\n");
#endif
    if (node->type == NodeType::VarDec)
        return new Field{node->children[0]->text, type, node->lineno};

    if (node->type == NodeType::VarDecArray)
        return var_dec(node->children[0],
                       new Type(new Array{type, _int(node->children[2])}));

    return nullptr;
}

Field *dec(Node *node, Type *type)
{
    Field *field = var_dec(node->children[0], type);
    // if (node->type == 2)
    // {
    //     Field *e = exp(node->children[2]);
    //     if (!_is_equivalent(e->type, type))
    //     {
    //         semantic_error(node->lineno, "Two sides of assignment have inconsistent type"); // "");
    //     }
    // }
    return field;
}
std::vector<Field *> dec_list(Node *node, Type *type)
{
    Field *field = dec(node->children[0], type);
    auto head = std::vector<Field *>{field};
    // if (node->type == 2)
    // {
    //     auto tail = dec_list(node->children[2], type);
    //     head.insert(head.end(), tail.begin(), tail.end());
    // }
    return head;
}

Type *specifier(Node *node);

std::vector<Field *> def(Node *node)
{
    Type *type = specifier(node->children[0]);
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
    printf("%p\n", node);
#endif
    auto head = std::vector<Field *>();
    if (node && node->type == NodeType::DefList)
    {
        head = def(node->children[0]);
        if (insert_now)
        {
            for (int i = 0; i < head.size(); i++)
            {
                SYMBOL_TABLE.insert(new SymbolTableEntry(head[i]));
            }
        }
        auto tail = def_list(node->children[1], insert_now);
        head.insert(head.end(), tail.begin(), tail.end());
    }
    printf("end\n");
    return head;
}

// Type *struct_specifier(Node *node)
// {
//     Struct *structure = new Struct;
//     structure->name = id(node->children[1]);
//     structure->fields = std::vector<Field *>();

//     if (node->type == 1)
//     {
//         structure->fields = def_list(node->children[3]);

//         // ?
//         // std::unordered_set<std::string> s;
//         // std::vector<Field*> res{};
//         // for (auto f : structure->fields) {
//         //     if (s.find(f->name) != s.end()) {
//         //         semantic_error(repeat_f->lineno,
//         //                 "Repeated field name inside structure",
//         //                 repeat_f->name.c_str());
//         //         res.push_back(f);
//         //     }
//         //     SYMBOL_TABLE.insert(f->name);
//         // }
//     }

//     return new Type(structure);
// }
Type *specifier(Node *node)
{
#ifdef debug
    printf("specifier\n");
    printf("%d\n", node->type);
#endif
    if (node == nullptr)
        return nullptr;
    if (node->type == NodeType::Specifier)
    {
        return type(node->children[0]);
    }
    else if (node->type == NodeType::StructSpecifier)
    {
        // return struct_specifier(node->children[0]);
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

void comp_st(Node *node, Type *ret_type, std::vector<Field *> params = std::vector<Field *>())
{
#ifdef debug
    printf("comp_st\n");
#endif
    SYMBOL_TABLE.scope_push(ret_type);
    for (auto param : params)
        SYMBOL_TABLE.insert(new SymbolTableEntry(param));
    def_list(node->children[1], true);
    // stmt_list(node->children[2], ret_type);
    SYMBOL_TABLE.scope_pop();
}

Func *fun_dec(Node *node, Type *ret_type)
{
    std::string name = id(node->children[0]);
    auto param_list = std::vector<Field *>();
    // if (node->type == NodeType::FunDecArgs)
    // {
    //     param_list = var_list(node->children[2]);
    //     for (auto param : param_list)
    //         _type_exist(param->type, param->lineno);
    // }
    return new Func{name, param_list, ret_type};
}

void ext_def(Node *node)
{
#ifdef debug
    printf("ext_def\n");
    printf("%d\n", node->type);
#endif
    Type *type = specifier(node->children[0]);
    if (node->type == NodeType::Declare)
    {
        _type_exist(type, node->lineno);
        printf("lineno: %d\n", node->lineno);
        auto fields = ext_dec_list(node->children[1], type);
        for (auto field : fields)
            SYMBOL_TABLE.insert(new SymbolTableEntry(field));
    }
    else if (node->type == NodeType::StructDef)
    {
        // if (type->category == Category::STRUCT)
        // {
        //     SYMBOL_TABLE.insert(new SymbolTableEntry(type, node->lineno));
        // }
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
    // printf("%d\n", node && node->type);
#endif
    if (node && node->type == NodeType::ExtDefList)
    {
        ext_def(node->children[0]);
        ext_def_list(node->children[1]);
    }
}

Field *exp(Node *node)
{
#ifdef debug
    printf("exp\n");
#endif
    auto c = node->children;
    auto default_exp = new Field{"LValue", new Type(Primitive::NEXP), node->lineno};
    if (node->type == NodeType::ExpAssign)
    {
        auto oprand_1 = exp(c[0]);
        auto oprand_2 = exp(c[2]);
        if (oprand_1->name != "LValue")
        {
            semantic_error(node->lineno,
                           "LHS of assignment is not a LValue", "");
        }
        if (!_is_equivalent(oprand_1->type, oprand_2->type))
        {
            // std::string msg =
            //     to_str(oprand_1->type) + "!=" + to_str(oprand_2->type);
            std::string msg = "?";
            semantic_error(node->lineno,
                           "Two sides of assignment are not of the same type",
                           msg.c_str());
        }
        return new Field{"RValue", new Type(*oprand_1->type),
                         node->lineno};
    }
    return default_exp;
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
