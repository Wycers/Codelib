#include "error.h"


struct Error *last_err = NULL;

void insert_err(int type, int line, const char* msg) {
    struct Error *err = (struct Error*)malloc(sizeof(struct Error));

    err->type = type;
    err->lineno = line;
    err->msg = strdup(msg);
    err->next = NULL;

    if (root_err == NULL) {
        root_err = err;
    } else {
        last_err->next = err;
    }
    last_err = err;
}

void print_err(struct Error *err)
{
    if (err->lineno == 0)
        return;
    printf("Error type %c at Line %d: %s\n", 'A' + err->type, err->lineno, err->msg);
}
