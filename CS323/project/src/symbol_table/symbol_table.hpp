#include <symbol_table_entry.h>

#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;

string to_str(Type *type)
{
    if (type->category == Category::PRIMITIVE)
    {
        if (type->primitive == Primitive::INT)
            return "INT";
        else if (type->primitive == Primitive::FLOAT)
            return "FLOAT";
        else if (type->primitive == Primitive::INT)
            return "CHAR";
        else if (type->primitive == Primitive::NEXP)
            return "NON-EXP";
        else
            return to_string(static_cast<int>(type->primitive));
    }
    else if (type->category == Category::STRUCT)
    {
        return "struct " + type->structure->name;
    }
    else
    {
        return to_str(type->array->type) + "[" + to_string(type->array->size) +
               "]";
    }
}

string to_str(Field *field, int indent = 0)
{
    Type *type = field->type;
    string name = field->name;
    return string(indent, ' ') + to_str(type) + ": " + name + " (" +
           to_string(field->lineno) + ")";
}

string to_str(Struct *structure, int indent = 0)
{
    string s = string(indent, ' ') + "struct " + structure->name + " {\n";
    for (auto f : structure->fields)
    {
        s = s + string(indent, ' ') + to_str(f, 2) + "\n";
    }
    s = s + string(indent, ' ') + "}";
    return s;
}

string to_str(Func *func, int indent = 0)
{
    string s = string(indent, ' ') + to_str(func->ret) + " " + func->name + "(";
    for (auto f : func->params)
    {
        s = s + string(indent, ' ') + to_str(f) + ", ";
    }
    s = s + string(indent, ' ') + ")";
    return s;
}

struct SymbolTable
{

    unordered_map<string, vector<SymbolTableEntry *>> table_map;
    vector<vector<SymbolTableEntry *>> scope_stack;
    vector<Type *> scope_ret_stack;

    SymbolTable() {
        while (!scope_stack.empty())
            scope_stack.pop_back();
        table_map.clear();

        // For global scope
        scope_push(nullptr);
    }

    SymbolTableEntry *find(const string &name) {
        auto entry_stack_iter = table_map.find(name);
        // there is no such name
        if (entry_stack_iter == table_map.end())
            return nullptr;
        auto entry_stack = entry_stack_iter->second;
        if (entry_stack.empty())
            return nullptr;
        auto entry = entry_stack.back();
        return entry;
    }

    SymbolTableEntry *find(const string &name, EntryType entry_type) {
        auto entry_stack_iter = table_map.find(name);
        if (entry_stack_iter == table_map.end()) {
            return nullptr;
        }
        auto entry_stack = entry_stack_iter->second;
        if (entry_stack.empty())
            return nullptr;
        for (auto i = entry_stack.rbegin(); i != entry_stack.rend(); ++i) {
            if ((*i)->entry_type == entry_type) {
                return *i;
            }
        }
        return nullptr;
    }

    // insert a new symbol to current scope
    void insert(SymbolTableEntry *entry) {
#define debug
#ifdef debug
        printf("insert\n");
#endif
        auto cur = find(entry->name(), entry->entry_type);
        if (cur != nullptr) {
            // redefine
            // insert_err(...)
            return;
        }

        const string &name = entry->name();
        auto entry_stack_iter = table_map.find(name);
        if (entry_stack_iter == table_map.end()) {
            auto vec = new vector<SymbolTableEntry *>();
            table_map[name] = *vec;
        }

        table_map[name].push_back(entry);
        scope_stack.back().push_back(entry);
    }

    void scope_push(Type *type) {
        auto *st = new vector<SymbolTableEntry *>();
        scope_stack.push_back(*st);
        scope_ret_stack.push_back(type);
    }

    void scope_pop() {
        if (scope_stack.empty()) {
            printf("fatal error!");
            exit(-1);
        }
        auto current_scope_stack = scope_stack.back();
        while (!current_scope_stack.empty()) {
            auto entry = current_scope_stack.back();
            auto name = entry->name();
            auto vec = table_map[name];
            vec.pop_back();
            delete entry;
        }
        scope_stack.pop_back();
    }

    void print() {
        int indent = 0;
        for (const auto &t : scope_stack) {
            for (auto entry : t) {

                if (entry == nullptr)
                    return;
               if (entry->entry_type == EntryType::FIELD) {
                   cout << to_str(entry->field, indent);
               } else if (entry->entry_type == EntryType::TYPE) {
                   cout << to_str(entry->type->structure, indent);
               } else {
                   cout << to_str(entry->func, indent);
               }
                // cout << entry << endl;
                cout << "\n";
            }
            indent += 2;
        }
    }

} SYMBOL_TABLE;
extern SymbolTable SYMBOL_TABLE;
