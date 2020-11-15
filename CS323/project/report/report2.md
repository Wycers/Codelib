# Report2 for CS323

## Some info...

Author: 11711918 吴烨昌

## Design and Implementation

### Type structure

``` cpp

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
    NotExpr = -1
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
    Type(Primitive primitive);
    Type(Array *array);
    Type(Struct *structure);

    bool equals(const Type *other);
};
```

### Symbol table

#### EntryTableEntry

``` cpp

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

    std::string name();
};

```

implemented in cross-linked list.

``` cpp

struct SymbolTable
{

    unordered_map<string, vector<SymbolTableEntry *>> table_map;
    vector<vector<SymbolTableEntry *>> scope_stack;
    vector<Type *> scope_ret_stack;

    SymbolTable()
    {
        while (!scope_stack.empty())
            scope_stack.pop_back();
        table_map.clear();

        // For global scope
        scope_push(nullptr);
    }

    SymbolTableEntry *find(const string &name);

    SymbolTableEntry *find_in_scope(const string &name, EntryType entry_type);

    SymbolTableEntry *find(const string &name, EntryType entry_type);

    // insert a new symbol to current scope
    void insert(SymbolTableEntry *entry)
    {
#ifdef debug
        printf("insert\n");
#endif
        auto cur = find_in_scope(entry->name(), entry->entry_type);
        if (cur != nullptr)
        {
            // redefine
            if (entry->entry_type == EntryType::TYPE && entry->type->category == Category::STRUCT)
                semantic_error(ErrorType::SemanticType15, entry->lineno, entry->name().c_str());
            else if (entry->entry_type == EntryType::FUNC)
                semantic_error(ErrorType::SemanticType4, entry->lineno, entry->name().c_str());
            else
                semantic_error(ErrorType::SemanticType3, entry->lineno, entry->name().c_str());
            return;
        }

        const string &name = entry->name();
        auto entry_stack_iter = table_map.find(name);
        if (entry_stack_iter == table_map.end())
        {
            auto vec = new vector<SymbolTableEntry *>();
            table_map[name] = *vec;
        }

        table_map[name].push_back(entry);
        scope_stack.back().push_back(entry);
    }

    void scope_push(Type *type)
    {
        auto *st = new vector<SymbolTableEntry *>();
        scope_stack.push_back(*st);
        scope_ret_stack.push_back(type);
    }

    void scope_pop()
    {
        if (scope_stack.empty())
        {
            printf("fatal error!");
            exit(-1);
        }
        auto current_scope_stack = scope_stack.back();
        while (!current_scope_stack.empty())
        {
            auto entry = current_scope_stack.back();
            current_scope_stack.pop_back();

            auto name = entry->name();
            auto vec = table_map[name];
            vec.pop_back();
            delete entry;
        }
        scope_stack.pop_back();
    }

    void print();
} SYMBOL_TABLE;
extern SymbolTable SYMBOL_TABLE;

```

### Visitor

``` cpp
// ..... Lots of node handling functions

void program(Node *node)
{
#ifdef debug
    printf("program\n");
#endif
    ext_def_list(node->children[0]);
}

void semantic_analysis(Node *root)
{
    program(root);
}

```

From the root of AST (which should be program), recursively call corresponding handler for current node, convey necessary information through children.

#### Test cases

1. The are 1 cases(r10) correct and 9 cases having semantic error(r01-r09).

### Bonus

1. All the provided testcases passed.

   A valid example:

   ``` cpp
   int main()
   {
     if (i == 1) {
       int i = 2;
     }
     return i;
   }
   
   ```

2. struct equivalence based on field order

   A valid example:

   ``` c
   
   struct A {
     int i;
     float f;
   };
   
   struct B {
     int j;
     float f;
   };
   
   
   
   int main()
   {
     struct A a;
     struct B b;
     a = b;
     return 1
   }
   ```

   

