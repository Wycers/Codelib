#include <cstring>

using namespace std;


typedef struct BOOLEAN {
    bool val;
} BOOLEAN;

typedef struct STRING {
    char *str;
} STRING;

typedef struct NUMBER {
    int val;
} NUMBER;

typedef struct Value {
    char type[32];
    enum {
        Object, Array, STRING, NUMBER, BOOLEAN, VNULL
    } category;
    union {
        struct Object *object;
        struct Array *array;
        struct STRING *string;
        struct NUMBER *number;
        struct BOOLEAN *boolean;
    };
} Value;

typedef struct Values {
    struct Value *value;
    struct Values *next;
} Values;


typedef struct Member {
    char *key;
    struct Value *value;
} Member;

typedef struct Members {
    struct Member *member;
    struct Members *next;
} Members;


typedef struct Object {
    struct Members *members;
} Object;

typedef struct Array {
    struct Values *values;
} Array;

typedef struct JSON {
    enum {
        Object, Array
    } category;

    union {
        struct Object *object;
        struct Array *array;
    };
} JSON;
