#pragma once
#include "syntax.tab.h"
#include <string>
#include <vector>

enum class Category
{
    PRIMITIVE,
    ARRAY,
    STRUCT
};

enum class Primitive
{
    INT = INT,
    FLOAT = FLOAT,
    CHAR = CHAR,
    NEXP = -1
};

struct Type;
struct Field;
struct Struct;
struct Array;
struct Func;
struct Type
{
    Category category;
    union
    {
        Primitive primitive;
        Array *array;
        Struct *structure;
    };
    Type(Primitive primitive)
    {
        this->category = Category::PRIMITIVE;
        this->primitive = primitive;
    };
    Type(Array *array)
    {
        this->category = Category::ARRAY;
        this->array = array;
    };
    Type(Struct *structure)
    {
        this->category = Category::STRUCT;
        this->structure = structure;
    };
};

struct Field
{
    char *name;
    struct Type *type;
    int lineno;
};

struct Array
{
    struct Type *type;
    int size;
};

struct Struct
{
    std::string name;
    std::vector<Field *> fields;
};

struct Func
{
    std::string name;
    std::vector<Field *> params;
    Type *ret;
};
