%{
    #include "lex.yy.c"

    void yyerror(const char *s);

    struct Node{
        int _token;
        char* _token_name;
        char* text;
        struct Node* brother;
        struct Node* child;
        int lineno;
    };

// #define debug
    struct Node* new_node(int token, const char* name, char* text, int lineno) {
#ifdef debug
        printf("[new node] name: %s text: %s line: %d\n", name, text, lineno);
#endif
        struct Node *p = (struct Node*)malloc(sizeof(struct Node));
        if (p==NULL)
        {
            printf("Error:out of memory.\n");
            exit(1);
        }
        p->_token = token;
        if(name != NULL)
            p->_token_name = strdup(name);
        p->text = strdup(text);
        p->lineno = lineno;
        p->brother=NULL;
        p->child=NULL;
        return p;
    }


    void insert(struct Node *parent, struct Node *child) {
#ifdef debug
        printf("[insert] parent: (%s, %d), child: (%s, %d)\n",
            parent->_token_name, parent->lineno,
            child->_token_name, child->lineno
        );
#endif
        if (child == NULL)
            return;
        if (parent->child == NULL) {
            parent->child = child;
        } else {
            struct Node *p = parent->child;
            while (p->brother != NULL) {
                p = p->brother;
            }
            p->brother = child;
        }
    }

    void display(struct Node *root, int depth){

        if (root == NULL || root->_token == 0)
            return;

        for(int i = 0; i < depth; ++i)
            printf("  ");

        if (root->_token == TYPE) {
            printf("TYPE: %s\r\n", root->text);
        }
        else if(root->_token == ID) {
            printf("ID: %s\r\n", root->text);
        }
        else if (root->_token == CHAR) {
            printf("%s: %c\r\n",root->_token_name, *(root->text + 1));
        }
        else if(root->_token >= INT && root->_token <= FLOAT){
            printf("%s: %s\r\n",root->_token_name, root->text);
        }
        else if(root->_token>= 258 && root->_token <=293)
            printf("%s\r\n",root->_token_name);
        else
            printf("%s (%d)\r\n",root->_token_name,root->lineno);

        struct Node *p  = root->child;
        while (p != NULL) {
            display(p, depth + 1);
            p = p->brother;
        }
        return ;
    }

    struct Node* p;
    int EXE_FAIL = 0;

    #define newNode(w, y, z, x) new_node((z), (w), (x), (y))

%}


%nonassoc THEN
%nonassoc ELSE


%union{ struct Node *token_p;}

%type <token_p>  Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier VarDec FunDec VarList ParamDec CompSt StmtList Stmt DefList Def DecList Dec Exp Args

%right<token_p> TYPE;

%token<token_p> INT CHAR FLOAT STRUCT IF ELSE WHILE RETURN

%left<token_p> LT LE GT GE NE EQ

%token<token_p> SEMI COMMA
%left<token_p>  DOT LP RP LB RB
%token<token_p> LC RC


%left<token_p> AND OR
%right<token_p> NOT

%right<token_p> ASSIGN
%left<token_p>  PLUS SUB MUL DIV
%right<token_p> MINUS

%token<token_p> ID

%token<token_p> ERR
%nonassoc ERR


%%




























/* high-level definition */
Program : ExtDefList                { /*printf("Program\n");*/ p=newNode("Program",$1->lineno, 233, "NULL");
                                    insert(p,$1);
                                    $$ =p;}

    ;
ExtDefList : ExtDef ExtDefList      { /* printf("ExtDefList\n");*/ p=newNode("ExtDefList",$1->lineno, 233, "NULL");
                                    insert(p,$1);
                                    insert(p,$2);
                                    $$=p;}
    |                               {  /*printf("ExtDefList\n");*/ p=newNode("NULL",0, 0, "NULL"); $$=p; }
    ;
ExtDef : Specifier ExtDecList SEMI  {  /*printf("ExtDef\n"); */p=newNode("ExtDef",$1->lineno, 233, "NULL");
                                     insert(p,$1);
                                     insert(p,$2);
                                     insert(p,$3);
                                     $$=p;}

    | Specifier SEMI                {  /*printf("ExtDef\n"); */p=newNode("ExtDef",$1->lineno, 233, "NULL");
                                     insert(p,$1);
                                     insert(p,$2);
                                     $$=p;}
    | Specifier FunDec CompSt       { /*printf("ExtDef\n"); */p=newNode("ExtDef",$1->lineno, 233, "NULL");
                                    insert(p,$1);
                                    insert(p,$2);
                                    insert(p,$3);
                                    $$=p;}
    | Specifier ExtDecList error    {printf("Error type B at Line %d: Missing semicolon ';'\n",$2->lineno);EXE_FAIL = 1;}
    | error SEMI                    { printf("Error type B at Line %d: Missing specifier\n",$2->lineno);EXE_FAIL = 1;}
    ;
ExtDecList : VarDec                 { /*printf("ExtDecList\n"); */p=newNode("ExtDecList",$1->lineno, 233, "NULL");
                                    insert(p,$1);
                                    $$=p;}
    | VarDec COMMA ExtDecList       { /*printf("ExtDecList\n"); */p=newNode("ExtDecList",$1->lineno, 233, "NULL");
                                    insert(p,$1);
                                    insert(p,$2);
                                    insert(p,$3);
                                    $$=p;}
    ;
/* specifier */
Specifier : TYPE                    { /*printf("Specifier\n"); */p=newNode("Specifier",$1->lineno, 233, "NULL")
                                    ;insert(p,$1);
                                    $$=p;}
    | StructSpecifier               { /*printf("Specifier\n"); */p=newNode("Specifier",$1->lineno, 233, "NULL");
                                    insert(p,$1);
                                    $$=p;}
    ;
StructSpecifier : STRUCT ID LC DefList RC   { /*printf("StructSpecifier\n"); */p=newNode("StructSpecifier",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            insert(p,$4);
                                            insert(p,$5);
                                            $$=p;}
    | STRUCT ID                             { /*printf("StructSpecifier\n"); */p=newNode("StructSpecifier",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            $$=p;}
    ;

/* declarator */
VarDec : ID                                 { /*printf("VarDec\n"); */p=newNode("VarDec",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            $$=p;}
    | VarDec LB INT RB                      { /*printf("VarDec\n"); */p=newNode("VarDec",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            insert(p,$4);
                                            $$=p;}
| ERR                                       {EXE_FAIL = 1;}
    ;
FunDec : ID LP VarList RP                   { /*printf("FunDec\n"); */p=newNode("FunDec",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            insert(p,$4);
                                            $$=p;}
    |  ID LP VarList error LC               {unput('{'); printf("Error type B at Line %d: Missing closing parenthesis ')'\n", $1->lineno);EXE_FAIL = 1;}
    |  ID LP  error LC                      {unput('{'); printf("Error type B at Line %d: Missing closing parenthesis ')'\n", $1->lineno);EXE_FAIL = 1;}
    | ID LP RP                              { /*printf("FunDec\n"); */p=newNode("FunDec",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}

    ;
VarList : ParamDec COMMA VarList            { /*printf("VarList\n"); */p=newNode("VarList",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    | ParamDec                              { /*printf("VarList\n"); */p=newNode("VarList",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            $$=p;}
    ;
ParamDec : Specifier VarDec                 { /*printf("ParamDec\n");  */p=newNode("ParamDec",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            $$=p;}
    | error VarDec                          {printf("Error type B at Line %d: Missing semicolon ';'\n",$2->lineno);EXE_FAIL = 1;}
    ;
/* statement */
CompSt : LC DefList StmtList RC             { /*printf("CompSt\n"); */p=newNode("CompSt",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            insert(p,$4);
                                            $$=p;}
    ;
    ;
StmtList : Stmt StmtList                    { /*printf("StmtList\n");  */p=newNode("StmtList",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            $$=p;}
    |                                       { /*printf("StmtList NULL\n"); */p=newNode("NULL",0, 0, "NULL"); $$=p; }
    ;
Stmt : Exp SEMI                             { /*printf("Stmt\n"); */p=newNode("Stmt",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            $$=p;}
    | CompSt                                { /*printf("Stmt\n"); */p=newNode("Stmt",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            $$=p;}
    | RETURN Exp SEMI                       { /*printf("Stmt\n"); */p=newNode("Stmt",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    | Exp error SEMI                        { printf("Error type B at Line %d: Missing semicolon ';'\n",$1->lineno);EXE_FAIL = 1;}
    | RETURN Exp error SEMI                 { printf("Error type B at Line %d: Missing semicolon ';'\n",$1->lineno);EXE_FAIL = 1;}

    | IF LP Exp RP Stmt %prec THEN          { /*printf("Stmt\n"); */p=newNode("Stmt",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            insert(p,$4);
                                            insert(p,$5);
                                            $$=p;}
    | IF LP Exp RP Stmt ELSE Stmt           { /*printf("Stmt\n"); */p=newNode("Stmt",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            insert(p,$4);
                                            insert(p,$5);
                                            insert(p,$6);
                                            insert(p,$7);
                                            $$=p;}
    | WHILE LP Exp RP Stmt                  { /*printf("Stmt\n"); */p=newNode("Stmt",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            insert(p,$4);
                                            insert(p,$5);
                                            $$=p;}
    ;
/* local definition */
DefList : Def DefList                       { /*printf("DefList\n"); */p=newNode("DefList",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            $$=p;}
    |                                       { /*printf("DefList\n"); */p=newNode("NULL",0, 0, "NULL");$$=p; }
    ;
Def : Specifier DecList SEMI                { /*printf("Def\n"); */p=newNode("Def",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}

    |  Specifier DecList error SEMI         { printf("Error type B at Line %d: Missing semicolon ';'\n",$1->lineno);EXE_FAIL = 1;}
    |  error DecList SEMI                    { printf("Error type B at Line %d: Missing specifier\n",$2->lineno);EXE_FAIL = 1;}
    | error FunDec CompSt                   { printf("Error type B at Line %d: Missing specifier\n",$2->lineno);EXE_FAIL = 1;}
    ;
DecList : Dec                               { /*printf("DecList\n"); */p=newNode("DecList",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            $$=p;}
    | Dec COMMA DecList                     { /*printf("DecList\n"); */p=newNode("DecList",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    ;
Dec : VarDec                                {/*printf("Dec\n");  */p=newNode("Dec",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            $$=p;}
    | VarDec ASSIGN Exp                     { /*printf("Dec\n"); */p=newNode("Dec",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
     | VarDec ASSIGN ERR  { EXE_FAIL = 1; }
    ;
/* Expression */
Exp : Exp ASSIGN Exp                        { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    | Exp ERR Exp                           { EXE_FAIL = 1;  }
    | Exp ASSIGN ERR                        { EXE_FAIL = 1;  }
    | Exp AND Exp                           { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    | Exp OR Exp                            { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    | Exp LT Exp                            { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    | Exp LE Exp                            { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    | Exp GT Exp                            { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    | Exp GE Exp                            { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    | Exp NE Exp                            { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    | Exp EQ Exp                            { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    | Exp PLUS Exp                          { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    | Exp MINUS Exp  %prec SUB                          { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    | Exp MUL Exp                           { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    | Exp DIV Exp                           { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    | LP Exp RP                             { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    | LP Exp error RP                       {printf("Error type B at Line %d: Missing closing parenthesis ')'\n", $1->lineno);EXE_FAIL = 1;}
    | SUB Exp %prec MINUS                   { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            $$=p;}
    | NOT Exp                               { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            $$=p;}
    | ID LP Args RP                         { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            insert(p,$4);
                                            $$=p;}
    | ID LP Args error SEMI                 {unput(';'); printf("Error type B at Line %d: Missing closing parenthesis ')'\n", $1->lineno);EXE_FAIL = 1;}
    | ID LP RP                              { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    | ID LP error RP                        {printf("Error type B at Line %d: Missing closing parenthesis ')'\n", $1->lineno);EXE_FAIL = 1;}
    | Exp LB Exp RB                         { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            insert(p,$4);
                                            $$=p;}
    | Exp DOT ID                            { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}

    | ID                                    { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            $$=p;}
    | INT                                   { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            $$=p;}
    | FLOAT                                 { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            $$=p;}
    | CHAR                                  { /*printf("Exp\n"); */p=newNode("Exp",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            $$=p;}

    ;
Args : Exp COMMA Args                       { /*printf("Args\n"); */p=newNode("Args",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            insert(p,$2);
                                            insert(p,$3);
                                            $$=p;}
    | Exp                                   { /*printf("Args\n"); */p=newNode("Args",$1->lineno, 233, "NULL");
                                            insert(p,$1);
                                            $$=p;}
    ;





























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
