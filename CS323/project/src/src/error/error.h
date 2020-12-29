#pragma once

#include "../../syntax.tab.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

enum class ErrorType
{
    Lexical = 0,
    Syntax = 1,

    Semantic = 2,
    SemanticType1 = 3,      // variable is used without definition
    SemanticType2 = 4,      // function is invoked without definition
    SemanticType3 = 5,      // variable is redefined in the same scope
    SemanticType4 = 6,      // function is redefined (in the global scope, since we don’t have nested function)
    SemanticType5 = 7,      // unmatching types on both sides of assignment operator (=)
    SemanticType6 = 8,      // rvalue on the left side of assignment operator
    SemanticType7 = 9,      // unmatching operands, such as adding an integer to a structure variable
    SemanticType8 = 10,     // the function’s return value type mismatches the declared type
    SemanticType9 = 11,     // the function’s arguments mismatch the declared parameters (either types or numbers, or both)
    SemanticType10 = 12,    // applying indexing operator ([...]) on non-array type variables
    SemanticType11 = 13,    // applying function invocation operator (foo(...)) on non-function names
    SemanticType12 = 14,    // array indexing with non-integer type expression
    SemanticType13 = 15,    // accessing member of non-structure variable (i.e., misuse the dot operator)
    SemanticType14 = 16,    // accessing an undefined structure member
    SemanticType15 = 17     // redefine the same structure type
};

struct Error
{
    struct Error *next;
    ErrorType type;
    int lineno;
    char *msg;
};

void lexical_error(int line, const char *msg);
void syntax_error(int line, const char *msg);

// Semantic Error
void semantic_error(int line, const char *msg1, const char *msg2);
void semantic_error(int line, const char *msg);
void semantic_error(ErrorType type, int line, const char *msg);

bool has_error();
void print_err(struct Error *err);
void print_errors();
