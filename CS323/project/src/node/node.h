#pragma once

#include "../../syntax.tab.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

struct Node
{
    int _token;
    char *_token_name;
    char *text;
    int childno;
    struct Node *children[32];
    int lineno;
};

struct Node *new_node(int token, const char *name, const char *text, int lineno);
void insert_node(struct Node *parent, struct Node *child);
void display(struct Node *root, int depth);
