#include <cstring>
using namespace std;



typedef struct Member {

};

typedef struct Members {

};


typedef struct Object {

};
typedef struct Array {

};
typedef struct STRING {

};
typedef struct NUMBER {
    string str;

};

typedef struct Values {

};

typedef struct Value {
    char type[32];
    enum {Object, Array, STRING, NUMBER, TRUE, FALSE, VNULL} category;
    union {
        struct Object *object;
        struct Array *array;
        struct STRING *string;
    };
};

typedef struct Json {
    struct Value* value;
};
