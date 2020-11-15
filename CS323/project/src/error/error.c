#include "error.h"


struct Error* root_error = NULL;
struct Error *last_err = NULL;

void insert_err(ErrorType type, int line, const char* msg) {
    struct Error *err = (struct Error*)malloc(sizeof(struct Error));

    err->type = type;
    err->lineno = line;
    err->msg = strdup(msg);
    err->next = NULL;

    if (root_error == NULL) {
        root_error = err;
    } else {
        last_err->next = err;
    }
    last_err = err;
}

void lexical_error(int line, const char *text) {
    char* msg = (char *)malloc(strlen("unknown lexeme") + strlen(text) + 1);
    if (!msg) {
        fprintf(stderr, "malloc() failed: insufficient memory!\n");
        return;
    }
    strcpy(msg, "unknown lexeme ");
    strcat(msg, text);
    insert_err(ErrorType::Lexical, line, msg);
    free(msg);
}

void semantic_error(int line, const char *msg1, const char *msg2) {
    char* msg = (char *)malloc(strlen(msg1) + strlen(msg2) + 1);
    if (!msg) {
        fprintf(stderr, "malloc() failed: insufficient memory!\n");
        return;
    }
    strcpy(msg, msg1);
    strcat(msg, msg2);
    insert_err(ErrorType::Semantic, line, msg);
}
void semantic_error(int line, const char *msg) {
    insert_err(ErrorType::Semantic, line, msg);
}
void syntax_error(int line, const char *msg) {
    insert_err(ErrorType::Syntax, line, msg);
}
void semantic_error(ErrorType type, int line, const char *msg) {
    insert_err(type, line, msg);
}

bool has_error() {
    return root_error != NULL;
}

void print_errors() {
    for (struct Error* now = root_error; now != NULL; now = now->next) {
        print_err(now);
    }
}

void print_err(struct Error *err)
{
    if (err->lineno == 0)
        return;

    if (err->type == ErrorType::Lexical ||
        err->type == ErrorType::Syntax  ||
        err->type == ErrorType::Semantic)
     {
        printf("Error type %c at Line %d: %s\n",
            'A' + (int)err->type,
            err->lineno,
            err->msg
        );
        return;
    }

    // Semantic Error
    printf("Error type %d at Line %d: %s\n",
        (int)err->type - (int)ErrorType::SemanticType1 + 1,
        err->lineno,
        err->msg
    );
}
