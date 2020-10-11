# Lab2 for CS315

## Some info...

Author: 11711918 吴烨昌



## Tools

### Flex

Flex is used to parse and tokenize the input SPL code with pre-defined regex rules, detecting lexical errors. 

### Bison 
Bison is used to parse the tokens from lexer and build the corresponding syntax tree. 

## Design and Implementation

#### Syntax Tree Node

``` c
struct Node{
    int _token;
    char* _token_name;
    char* text;
    struct Node* brother;
    struct Node* child;
    int lineno;
};

struct Node* new_node(int token, const char* name, char* text, int lineno);

void insert_node(struct Node *parent, struct Node *child);

void display(struct Node *root, int depth);

struct Node *root_node = NULL;
```

Using poly tree to binary tree structure, the syntax tree is defined as a binary tree.

Syntax tree nodes store the token text and token name (from lexer), line number where token occurs (from lexer), its children (from yacc parser)

#### Error and its recovery

``` c
struct Error {
    struct Error* next;
    int type;
    int lineno;
    char* msg;
};

struct Error *root_err = NULL, *last_err = NULL;

void insert_err(int type, int line, const char* msg);

void print_err(struct Error* err);
```

``` c
if (root_err == NULL)
    display(root_node, 0);
else
    for (struct Error* now = root_err; now != NULL; now = now->next) {
        print_err(now);
    }
```

When error detected, it will not display syntax tree but output error messages.

#### Test cases 

1. The are 5 correct  cases with only basic statements

### Features

1.  All the provided testcases passed.

2. Scientific notation support for float number.

   ``` c
   int main() {
       float f = 1e10;
       float f = -1e10;
   
       float f = 1e-10;
       float f = -1e-10;
   
       float f = 2.5e5;
       float f = -2.5e5;
   
       float f = 2.5e-10;
       float f = -2.5e-10;
   
       float f = 2.5e-10 + 10;
       float f = -2.5e-10 + 10;
   }
   ```

   

