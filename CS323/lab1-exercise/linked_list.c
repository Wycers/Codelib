#include "linked_list.h"

node *linked_list_init(){
    node *head = (node*)malloc(sizeof(node));
    head->count = 0;
    head->next = NULL;
    return head;
}

void linked_list_free(node *head){
    node *cur = head;
    node *last;
    while(cur != NULL){
        last = cur;
        cur = cur->next;
        free(last);
    }
}

char linked_list_string[0x10000];

char *linked_list_tostring(node *head){
    node *cur = head->next;
    char *position;
    int length = 0;
    while(cur != NULL){
        position = linked_list_string + length;
        length += sprintf(position, "%d", cur->value);
        cur = cur->next;
        if(cur != NULL){
            position = linked_list_string + length;
            length += sprintf(position, "->");
        }
    }
    position = linked_list_string + length;
    length += sprintf(position, "%c", '\0');
    return linked_list_string;
}

int linked_list_size(node *head){
    return head->count;
}

void linked_list_append(node *head, int val){
    node *cur = head;
    node *new_node;
    while(cur->next != NULL){
        cur = cur->next;
    }
    new_node = (node*)malloc(sizeof(node));
    new_node->value = val;
    new_node->next = NULL;
    cur->next = new_node;
    head->count++;
}

/* your implementation goes here */

node *linked_list_search_all(node *head, int val) {
	node *res_head = linked_list_init();

	node *cur = head->next;
    int pos = 0;
	while (cur != NULL) {
		if (cur->value == val) {
			linked_list_append(res_head, pos);
		}
        ++pos;
		cur = cur->next;
	}
	return res_head;
}



void linked_list_insert(node *head, int val, int index) {
	if (index < 0 || index + 1 > head->count) {
		return;
	}
	++head->count;
	int now = 0;
	node *cur = head;

	node *new_node = (node *) malloc(sizeof(node));
	new_node->value = val;
	while (cur != NULL) {
		if ((now++) == index) {
			new_node->next = cur->next;
			cur->next = new_node;
			break;
		}
		cur = cur->next;
	}
}

int linked_list_get(node *head, int index) {
	if (index < 0 || index + 1 > head->count) {
		return -2147483648;
	}
	node *cur = head->next;
	int now = 0;
	while (cur != NULL) {
		if ((now++) == index) {
			return cur->value;
		}
		cur = cur->next;
	}
	return -2147483648;
}


void linked_list_delete(node *head, int index) {
	if (index < 0 || index + 1 > head->count) {
		return;
	}
	--head->count;
	node *cur = head;
	int now = 0;
	while (cur != NULL) {
		if ((now++) == index) {
			cur->next = cur->next->next;
			break;
		}
		cur = cur->next;
	}
}

int linked_list_search(node *head, int val) {
	node *cur = head->next;
	int res = 0;
	while (cur != NULL) {
		if (cur->value == val) {
			return res;
		}
		++res;
		cur = cur->next;
	}
	return -1;
}

void linked_list_remove_all(node *head, int val) {
	node *cur = head;
	while (cur != NULL) {
		while (cur->next != NULL && cur->next->value == val) {
			cur->next = cur->next->next;
		}
		cur = cur->next;
	}
}

void linked_list_remove(node *head, int val) {
	node *cur = head;
	while (cur != NULL) {
		if (cur->next != NULL && cur->next->value == val) {
			cur->next = cur->next->next;
			break;
		}
		cur = cur->next;
	}
}
