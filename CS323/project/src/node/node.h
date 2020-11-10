#pragma once

#include "../../syntax.tab.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"


enum class NodeType {
    Default = 0,


    Declare = 1,
    StructDef = 2,
    FuncDef = 3,

    Specifier = 4,
    StructSpecifier = 5,

    ExtDefList = 6,

    DefList = 7,

    // expression
    ExpAssign = 8,

    ExpAnd = 9,
    ExpOr = 10,

    ExpLT = 11,
    ExpGT = 12,
    ExpLE = 13,
    ExpGE = 14,
    ExpEQ = 15,
    ExpNE = 16,

    ExpPlus = 17,
    ExpMinus = 18,
    ExpNegative = 19,
    ExpMul = 20,
    ExpDiv = 21,
    ExpNot = 22,

    ExpBracketWrapped = 23,

    ExpArgsFuncCall = 24,
    ExpFuncCall = 25,

    ExpFiledAccess = 26,

    ExpId = 30,
    ExpInt = 27,
    ExpChar = 28,
    ExpFloat = 29,

    VarDec = 30,
    VarDecArray = 31,

    ExtDecListSingle = 32,
    ExtDecListMultiple = 33,

    FunDecArgs = 34,
    FunDec = 35,
};


struct Node
{
    int _token;
    char *_token_name;
    char *text;
    int childno;
    struct Node *children[32];
    int lineno;
    NodeType type;
};

struct Node *new_node(int token, const char *name, const char *text, int lineno);
void insert_node(struct Node *parent, struct Node *child);
void set_node_type(struct Node *node, NodeType type);
void display(struct Node *root, int depth);
