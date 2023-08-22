
#include <stdlib.h>
#define JSON
typedef struct JsonObject {
    enum {
        OBJECT,
        ARRAY,
        _STRING,
        _NUMBER,
        _BOOLEAN,
        _VNULL
    } category;
    union {
        struct ObjectMember *members;
        struct ArrayValue *values;
        char *string;
        double number;
        int boolean;
    };
} JsonObject;

typedef struct ObjectMember {
    char *key;
    struct JsonObject *value;
    struct ObjectMember *next;
} ObjectMember;

typedef struct ArrayValue {
    JsonObject *value;
    struct ArrayValue *next;
} ArrayValue;

JsonObject *json_object(ObjectMember *member) {
    JsonObject *json_value = (JsonObject *)malloc(sizeof(JsonObject));
    json_value->members = member;
    while (member != NULL) {
        struct ObjectMember* tmp = member->next;
        while (tmp != NULL) {
            if (strcmp(member->key, tmp->key) == 0) {
                printf("duplicate key: %s\n", tmp->key);
                exit(-1);
            }
        }
    }
    return json_value;
}

JsonObject *json_array(ArrayValue *values) {
    JsonObject *json_value = (JsonObject *)malloc(sizeof(JsonObject));
    json_value->values = values;
    return json_value;
}

JsonObject *json_string(char *string) {
    JsonObject *json_value = (JsonObject *)malloc(sizeof(JsonObject));
    json_value->string = string;
    return json_value;
}

JsonObject *json_number(double number) {
    JsonObject *json_value = (JsonObject *)malloc(sizeof(JsonObject));
    json_value->number = number;
    return json_value;
}

JsonObject *json_bool(int boolean) {
    JsonObject *json_value = (JsonObject *)malloc(sizeof(JsonObject));
    json_value->boolean = boolean;
    return json_value;
}

JsonObject *json_vnull() {
    JsonObject *json_value = (JsonObject *)malloc(sizeof(JsonObject));
    return json_value;
}

ObjectMember *object_value_member(JsonObject *value) {
    ObjectMember *object_member = (ObjectMember *)malloc(sizeof(ObjectMember));
    object_member->value = value;
    return object_member;
}

ObjectMember *object_member(char *key, JsonObject *value, ObjectMember *next) {
    ObjectMember *object_member = (ObjectMember *)malloc(sizeof(ObjectMember));
    object_member->key = key;
    object_member->value = value;
    object_member->next = next;
    return object_member;
}

ArrayValue *array_value(JsonObject *value) {
    ArrayValue *array_value = (ArrayValue *)malloc(sizeof(ArrayValue));
    array_value->value = value;
    return array_value;
}

JsonObject *add_object(JsonObject *member, JsonObject *head) {
    head->members->next = member->members;
    return head;
}
