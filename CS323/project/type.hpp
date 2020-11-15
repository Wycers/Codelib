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

    bool operator==(const Type *other) const;
    bool operator!=(const Type *other) const;
};

struct Field
{
    std::string name;
    struct Type *type;
    int lineno;

    Field(Type *type, int lineno) : type(type), lineno(lineno) {}
    Field(std::string name, Type *type, int lineno) : name(name), type(type), lineno(lineno) {}
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

bool Type::operator==(const Type *other) const
{
    if (this->category != other->category)
        return false;

    if (this->category == Category::PRIMITIVE)
        return this->primitive == other->primitive;

    if (this->category == Category::ARRAY)
        return this->array->type == other->array->type &&
               this->array->size == other->array->size;

    if (this->category == Category::STRUCT)
    {
        auto fields_1 = this->structure->fields;
        auto fields_2 = other->structure->fields;
        if (fields_1.size() != fields_2.size())
            return false;

        int s = fields_1.size();
        for (int i = 0; i < s; i++)
            if (fields_1[i]->type != fields_2[i]->type)
                return false;

        return true;
    }

    return false;
}

bool Type::operator!=(const Type *other) const
{
    return !(*this == other);
}
