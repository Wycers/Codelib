
#include <string>
#include <type.hpp>

enum class EntryType
{
    TYPE = 0,
    FUNC = 1,
    FIELD = 2
};

struct SymbolTableEntry
{

    EntryType entry_type;

    int lineno;

    union
    {
        Type *type;
        Field *field;
        Func *func;
    };

    SymbolTableEntry(Field *field, int lineno)
        : field(field), lineno(lineno), entry_type(EntryType::FIELD) {}

    SymbolTableEntry(Func *func, int lineno)
        : func(func), lineno(lineno), entry_type(EntryType::FUNC) {}

    SymbolTableEntry(Type *type, int lineno)
        : type(type), lineno(lineno), entry_type(EntryType::TYPE) {}

    std::string name()
    {
        if (this->entry_type == EntryType::FIELD)
            return this->field->name;
        if (this->entry_type == EntryType::FUNC)
            return this->func->name;
        if (this->entry_type == EntryType::TYPE && this->type->category == Category::STRUCT)
            return this->type->structure->name;

        return "";
    }
};
