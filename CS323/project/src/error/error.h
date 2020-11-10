#pragma once

#include "../../syntax.tab.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"


enum class ErrorType {
    Lexical = 0,
    Syntax = 1,
    Semantic = 2
};

struct Error
{
    struct Error *next;
    ErrorType type;
    int lineno;
    char *msg;
};


void lexical_error(int line, const char *msg);
void semantic_error(int line, const char *msg1, const char *msg2);
void semantic_error(int line, const char *msg);
void syntax_error(int line, const char *msg);



bool has_error();
void print_err(struct Error *err);
void print_errors();
