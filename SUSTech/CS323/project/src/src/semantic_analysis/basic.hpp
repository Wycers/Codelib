//
// Created by Wycer on 2020/12/8.
//

#pragma once

#include "node.h"
#include "type.hpp"
#include "symbol_table.hpp"
#include "symbol_table_entry.h"

char *idOf(Node *node) {
    return node->text;
}

int _int(Node *node) {
    return strtol(node->text, nullptr, 10);
}

Type *typeOf(Node *node) {
#ifdef debug
    printf("node_token: %d\n", node->_token);
#endif
    if (node->_token == TYPE) {
        if (strcmp(node->text, "int") == 0)
            return new Type(Primitive::INT);
        else if (strcmp(node->text, "float") == 0)
            return new Type(Primitive::FLOAT);
        else if (strcmp(node->text, "char") == 0)
            return new Type(Primitive::CHAR);
    }
    return new Type((Primitive) node->type);
}


Type *_type_exist(Type *type, int lineno) {
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
