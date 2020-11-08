#include "node.h"

// #define debug
struct Node *new_node(int token, const char *name, const char *text, int lineno)
{
#ifdef debug
    printf("[new node] name: %s text: %s line: %d\n", name, text, lineno);
#endif
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL)
    {
        printf("Error:out of memory.\n");
        exit(1);
    }
    node->_token = token;
    if (name != NULL)
        node->_token_name = strdup(name);
    node->text = strdup(text);
    node->lineno = lineno;

    node->childno = 0;
    return node;
}


void insert_node(struct Node *parent, struct Node *child) {
#ifdef debug
    printf("[insert] parent: (%s, %d), child: (%s, %d)\n",
        parent->_token_name, parent->lineno,
        child->_token_name, child->lineno
    );
#endif
    // if (parent->child == NULL) {
    //     parent->child = child;
    // } else {
    //     struct Node *node = parent->child;
    //     while (node->brother != NULL) {
    //         node = node->brother;
    //     }
    //     node->brother = child;
    // }
    parent->children[parent->childno++] = child;
}


void display(struct Node *root, int depth) {

    if (root == NULL || root->_token == 0)
        return;

    for(int i = 0; i < depth; ++i)
        printf("  ");

    if (root->_token == TYPE || root->_token == ID) {
        printf("%s: %s\r\n",root->_token_name, root->text);
    }
    else if(root->_token >= INT && root->_token <= FLOAT){
        printf("%s: %s\r\n",root->_token_name, root->text);
    }
    else if(root->_token>= 258 && root->_token <=293)
        printf("%s\r\n",root->_token_name);
    else
        printf("%s (%d)\r\n",root->_token_name,root->lineno);

    for (int i = 0; i < root->childno; ++i) {
        display(root->children[i], depth + 1);
    }
    return ;
}
