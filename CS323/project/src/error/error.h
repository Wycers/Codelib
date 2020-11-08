#pragma once

#include "../../syntax.tab.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct Error
{
    struct Error *next;
    int type;
    int lineno;
    char *msg;
};

extern struct Error* root_err;
void insert_err(int type, int line, const char *msg);
void print_err(struct Error *err);
