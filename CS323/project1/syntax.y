%{
    #include"lex.yy.c"

    void yyerror(const char *s);

    struct Node{
        char* text;
        struct Node* brother;
        struct Node* child;
        int No_Line;
        int No_Child;
        int IsBegin;
        int _type;
        char _typeName[20];
    };


    struct Node* new_node(char* text, int line, int type, char *typeName) {
        // printf("now i am here\n");
        struct Node *p = (struct Node*)malloc(sizeof(struct Node));
        if (p==NULL)
        {
            printf("Error:out of memory.\n");
            exit(1);
        }
        strcpy(p->text, text);
        p->brother=NULL;
        p->child=NULL;
        p->No_Line=line;
        p->No_Child=0;
        p->IsBegin=0;
        p->_type = type;
        if(typeName != NULL)
            strncpy(p->_typeName,typeName,20);
        return p;
    }



    void insert(struct Node *parent,struct Node *child)
    {
        struct Node *p;
        if (child==NULL)
            return;
        if(parent->No_Child==0)
        {
            parent->child=child;
            child->IsBegin=1;
            parent->No_Child=1;
        }
        else
        {
            p=parent->child;
            while(p->brother!=NULL)
                p=p->brother;
            p->brother=child;
            child->IsBegin=0;
            parent->No_Child++;
        }
    }

    void display(struct Node *root, int depth){

        if (root->_type == 0)
            return;
        for(int i = 0; i < depth; ++i)
            printf("  ");

        if (root->_type == TYPE)
            printf("TYPE: %s\r\n", root->name);
        else if(root->_type == ID)
            printf("ID: %s\r\n", root->name);
        else if (root->_type == CHAR) {
            char ans[20];
            strncpy(ans,root->name+1,strlen(root->name) -2);
            ans[strlen(root->name) -2] = '\0';
            printf("%s: %s\r\n",root->_typeName, ans);
        }
        else if(root->_type >= INT && root->_type <= FLOAT){
            printf("%s: %s\r\n",root->_typeName, root->name);
        }
        else if(root->_type>= 258 && root->_type <=293)
            printf("%s\r\n",root->_typeName);
        else
            printf("%s (%d)\r\n",root->name,root->No_Line);
        if(root->No_Child == 0) return;
        struct Node *p  = root->child;
        for(int i  = 0; i < root->No_Child; ++i) {

            display(p, depth +1 );
            p = p->brother;
        }
        return ;
    }


%}

%token TYPE

%token INT CHAR FLOAT

%token STRUCT IF ELSE WHILE RETURN

%token LT LE GT GE NE EQ

%token SEMI COMMA DOT LP RP LB RB LC RC

%token AND OR NOT

%token ASSIGN PLUS MINUS MUL DIV

%token ID

%%
String: %empty {}




%%

void yyerror(const char *s){
    printf("syntax error: %s",s);
}

int main(int argc, char **argv){
    FILE* fin=NULL;
    extern FILE* yyin;
    fin=fopen(argv[1],"r");

    if(fin==NULL)
    {
        printf("cannot open reading file.\n");
        return -1;
    }
    yyin=fin;
    /* yydebug = 1; */
    yyparse();
    fclose(fin);


    if (!EXE_FAIL)
        display(p,0);
    return 0;

}
