%{
    #include "lex.yy.c"
    void yyerror(const char* msg) {}

    struct Node{
        int _token;
        char* _token_name;
        char* text;
		int childno;
        struct Node* children[32];
        int lineno;
    };

// #define debug
    struct Node* new_node(int token, const char* name, char* text, int lineno) {
#ifdef debug
        printf("[new node] name: %s text: %s line: %d\n", name, text, lineno);
#endif
        struct Node *node = (struct Node*)malloc(sizeof(struct Node));
        if (node == NULL)
        {
            printf("Error:out of memory.\n");
            exit(1);
        }
        node->_token = token;
        if(name != NULL)
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

    void display(struct Node *root, int depth){

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

    struct Node *root_node = NULL;

	struct Error {
		struct Error* next;
		int type;
		int lineno;
		char* msg;
	};

	struct Error *root_err = NULL, *last_err = NULL;

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

	void print_err(struct Error* err) {
		if (err->lineno == 0)
			return;
		printf("Error type %c at Line %d: %s\n", 'A' + err->type, err->lineno, err->msg);
	}

%}

%union{ struct Node *node; }

%nonassoc THEN
%nonassoc<node> ELSE

%type <node> NullableExp
%type <node> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier VarDec FunDec VarList ParamDec CompSt StmtList Stmt DefList Def DecList Dec Exp Args

%right<node> TYPE;

%token<node> INT CHAR FLOAT STRUCT IF FOR WHILE RETURN

%left<node> LT LE GT GE NE EQ

%token<node> SEMI COMMA
%left<node>  DOT LP RP LB RB
%token<node> LC RC


%left<node> AND OR
%right<node> NOT

%right<node> ASSIGN
%left<node>  PLUS SUB MUL DIV
%right<node> MINUS

%token<node> ID

%token<node> ERR
%nonassoc ERR


%%



















/* high-level definition */
Program
       	:	ExtDefList	{
       		          	    root_node = new_node(233, "Program", "NULL", $1->lineno);
                                 insert_node(root_node, $1);
       		          	    $$ = root_node;
       		          	}
       	;


ExtDefList
          	:	ExtDef ExtDefList	{
          		                 	    root_node = new_node(233, "ExtDefList", "NULL", $1->lineno);
                                        insert_node(root_node, $1);
          		                 	    insert_node(root_node, $2);
          		                 	    $$ = root_node;
          		                 	}
          	|	                 	{
          		                 	    root_node = new_node(0, "NULL", "NULL", 0);
                                        $$ = root_node;
          		                 	}
          	;


ExtDef
      	:	Specifier ExtDecList SEMI 	{
      		                          	    root_node = new_node(233, "ExtDef", "NULL", $1->lineno);
                                            insert_node(root_node, $1);
      		                          	    insert_node(root_node, $2);
      		                          	    insert_node(root_node, $3);
      		                          	    $$ = root_node;
      		                          	}
      	|	Specifier SEMI            	{
      		                          	    root_node = new_node(233, "ExtDef", "NULL", $1->lineno);
											insert_node(root_node, $1);
      		                          	    insert_node(root_node, $2);
      		                          	    $$ = root_node;
      		                          	}
      	|	Specifier FunDec CompSt   	{
      		                          	    root_node = new_node(233, "ExtDef", "NULL", $1->lineno);
											insert_node(root_node, $1);
      		                          	    insert_node(root_node, $2);
      		                          	    insert_node(root_node, $3);
      		                          	    $$ = root_node;
      		                          	}
      	|	Specifier ExtDecList error	{
											insert_err(1, $2 -> lineno, "Missing semicolon ';'");
      		                          	}
      	|	error SEMI                	{
											insert_err(1, $2 -> lineno, "Missing specifier");
      		                          	}
      	;


ExtDecList
          	:	VarDec                 	{
          		                       	    root_node = new_node(233, "ExtDecList", "NULL", $1->lineno);
											insert_node(root_node, $1);
          		                       	    $$ = root_node;
          		                       	}
          	|	VarDec COMMA ExtDecList	{
          		                       	    root_node = new_node(233, "ExtDecList", "NULL", $1->lineno);
											insert_node(root_node, $1);
          		                       	    insert_node(root_node, $2);
          		                       	    insert_node(root_node, $3);
          		                       	    $$ = root_node;
          		                       	}
          	;


/* specifier */
Specifier
         	:	TYPE           	{
         		               	    root_node = new_node(233, "Specifier", "NULL", $1->lineno);
                                        insert_node(root_node, $1);
         		               	    $$ = root_node;
         		               	}
         	|	StructSpecifier	{
         		               	    root_node = new_node(233, "Specifier", "NULL", $1->lineno);
                                        insert_node(root_node, $1);
         		               	    $$ = root_node;
         		               	}
         	;


StructSpecifier
               	:	STRUCT ID LC DefList RC	{
               		                       	    root_node = new_node(233, "StructSpecifier", "NULL", $1->lineno);
												insert_node(root_node, $1);
               		                       	    insert_node(root_node, $2);
               		                       	    insert_node(root_node, $3);
               		                       	    insert_node(root_node, $4);
               		                       	    insert_node(root_node, $5);
               		                       	    $$ = root_node;
               		                       	}
               	|	STRUCT ID              	{
               		                       	    root_node = new_node(233, "StructSpecifier", "NULL", $1->lineno);
												insert_node(root_node, $1);
               		                       	    insert_node(root_node, $2);
               		                       	    $$ = root_node;
               		                       	}
               	;


/* declarator */
VarDec
      	:	ID              	{
      		                	    root_node = new_node(233, "VarDec", "NULL", $1->lineno);
									insert_node(root_node, $1);
      		                	    $$ = root_node;
      		                	}
      	|	VarDec LB INT RB	{
      		                	    root_node = new_node(233, "VarDec", "NULL", $1->lineno);
									insert_node(root_node, $1);
      		                	    insert_node(root_node, $2);
      		                	    insert_node(root_node, $3);
      		                	    insert_node(root_node, $4);
      		                	    $$ = root_node;
      		                	}
      	|	ERR             	{
			  						insert_err(1, 0, "error");
      		                	}
      	;


FunDec
      	:	ID LP VarList RP      	{
      		                      	    root_node = new_node(233, "FunDec", "NULL", $1->lineno);
										insert_node(root_node, $1);
      		                      	    insert_node(root_node, $2);
      		                      	    insert_node(root_node, $3);
      		                      	    insert_node(root_node, $4);
      		                      	    $$ = root_node;
      		                      	}
      	|	ID LP VarList error LC	{
      		                      	    unput('{');
										insert_err(1, $1 -> lineno, "Missing closing parenthesis ')'");
      		                      	}
      	|	ID LP  error LC       	{
      		                      	    unput('{');
										insert_err(1, $1 -> lineno, "Missing closing parenthesis ')'");
      		                      	}
      	|	ID LP RP              	{
      		                      	    root_node = new_node(233, "FunDec", "NULL", $1->lineno);
										insert_node(root_node, $1);
      		                      	    insert_node(root_node, $2);
      		                      	    insert_node(root_node, $3);
      		                      	    $$ = root_node;
      		                      	}
      	;


VarList
       	:	ParamDec COMMA VarList	{
       		                      	    root_node = new_node(233, "VarList", "NULL", $1->lineno);
										insert_node(root_node, $1);
       		                      	    insert_node(root_node, $2);
       		                      	    insert_node(root_node, $3);
       		                      	    $$ = root_node;
       		                      	}
		| 	ParamDec COMMA error RP {
										unput(')');
										insert_err(1, $1->lineno, "Extra Comma");
									}
       	|	ParamDec              	{
       		                      	    root_node = new_node(233, "VarList", "NULL", $1->lineno);
											insert_node(root_node, $1);
       		                      	    $$ = root_node;
       		                      	}
       	;


ParamDec
        	:	Specifier VarDec	{
        		                	    root_node = new_node(233, "ParamDec", "NULL", $1->lineno);
                                        insert_node(root_node, $1);
        		                	    insert_node(root_node, $2);
        		                	    $$ = root_node;
        		                	}
        	|	error VarDec    	{
										insert_err(1, $2 -> lineno, "Missing semicolon ';'");
        		                	}
        	;


/* statement */
CompSt
      	:	LC DefList StmtList RC	{
      		                      	    root_node = new_node(233, "CompSt", "NULL", $1->lineno);
										insert_node(root_node, $1);
      		                      	    insert_node(root_node, $2);
      		                      	    insert_node(root_node, $3);
      		                      	    insert_node(root_node, $4);
      		                      	    $$ = root_node;
      		                      	}
      	;


StmtList
        	:	Stmt StmtList	{
        		             	    root_node = new_node(233, "StmtList", "NULL", $1->lineno);
									insert_node(root_node, $1);
        		             	    insert_node(root_node, $2);
        		             	    $$ = root_node;
        		             	}
        	|	             	{
        		             	    root_node = new_node(0, "NULL", "NULL", 0);
									$$ = root_node;
        		             	}
        	;


Stmt
    	:	Exp SEMI                    	{
    		                            	    root_node = new_node(233, "Stmt", "NULL", $1->lineno);
												insert_node(root_node, $1);
    		                            	    insert_node(root_node, $2);
    		                            	    $$ = root_node;
    		                            	}
    	|	CompSt                      	{
    		                            	    root_node = new_node(233, "Stmt", "NULL", $1->lineno);
                                                insert_node(root_node, $1);
    		                            	    $$ = root_node;
    		                            	}
    	|	RETURN Exp SEMI             	{
    		                            	    root_node = new_node(233, "Stmt", "NULL", $1->lineno);
                                                insert_node(root_node, $1);
    		                            	    insert_node(root_node, $2);
    		                            	    insert_node(root_node, $3);
    		                            	    $$ = root_node;
    		                            	}
    	|	Exp error SEMI              	{
												insert_err(1, $1 -> lineno, "Missing semicolon ';'");
    		                            	}
    	|	RETURN Exp error SEMI       	{
												insert_err(1, $1 -> lineno, "Missing semicolon ';'");
    		                            	}
    	|	IF LP Exp RP Stmt %prec THEN	{
    		                            	    root_node = new_node(233, "Stmt", "NULL", $1->lineno);
                                                insert_node(root_node, $1);
    		                            	    insert_node(root_node, $2);
    		                            	    insert_node(root_node, $3);
    		                            	    insert_node(root_node, $4);
    		                            	    insert_node(root_node, $5);
    		                            	    $$ = root_node;
    		                            	}
    	|	IF LP Exp RP Stmt ELSE Stmt 	{
    		                            	    root_node = new_node(233, "Stmt", "NULL", $1->lineno);
                                                insert_node(root_node, $1);
    		                            	    insert_node(root_node, $2);
    		                            	    insert_node(root_node, $3);
    		                            	    insert_node(root_node, $4);
    		                            	    insert_node(root_node, $5);
    		                            	    insert_node(root_node, $6);
    		                            	    insert_node(root_node, $7);
    		                            	    $$ = root_node;
    		                            	}
    	|	WHILE LP Exp RP Stmt        	{
    		                            	    root_node = new_node(233, "Stmt", "NULL", $1->lineno);
                                                insert_node(root_node, $1);
    		                            	    insert_node(root_node, $2);
    		                            	    insert_node(root_node, $3);
    		                            	    insert_node(root_node, $4);
    		                            	    insert_node(root_node, $5);
    		                            	    $$ = root_node;
    		                            	}
    	| 	FOR LP Exp SEMI Exp SEMI RP Stmt{
    		                            	    root_node = new_node(233, "Stmt", "NULL", $1->lineno);
                                                insert_node(root_node, $1);
    		                            	    insert_node(root_node, $2);
    		                            	    insert_node(root_node, $3);
    		                            	    insert_node(root_node, $4);
    		                            	    insert_node(root_node, $5);
    		                            	    insert_node(root_node, $6);
    		                            	    insert_node(root_node, $7);
    		                            	    insert_node(root_node, $8);
    		                            	    $$ = root_node;
    		                            	}
    	;


/* local definition */
DefList
       	:	Def DefList	{
       		           	    root_node = new_node(233, "DefList", "NULL", $1->lineno);
                            insert_node(root_node, $1);
       		           	    insert_node(root_node, $2);
       		           	    $$ = root_node;
       		           	}
       	|	           	{
       		           	    root_node = new_node(0, "NULL", "NULL", 0);
                            $$ = root_node;
       		           	}
       	;


Def
   	:	Specifier DecList SEMI      	{
   		                            	    root_node = new_node(233, "Def", "NULL", $1->lineno);
                                               insert_node(root_node, $1);
   		                            	    insert_node(root_node, $2);
   		                            	    insert_node(root_node, $3);
   		                            	    $$ = root_node;
   		                            	}
   	|	Specifier DecList error SEMI	{
											insert_err(1, $1 -> lineno, "Missing semicolon ';'");
   		                            	}
   	|	error DecList SEMI          	{
											insert_err(1, $2 -> lineno, "Missing specifier");
   		                            	}
   	;


DecList
       	:	Dec              	{
       		                 	    root_node = new_node(233, "DecList", "NULL", $1->lineno);
                                        insert_node(root_node, $1);
       		                 	    $$ = root_node;
       		                 	}
       	|	Dec COMMA DecList	{
       		                 	    root_node = new_node(233, "DecList", "NULL", $1->lineno);
                                        insert_node(root_node, $1);
       		                 	    insert_node(root_node, $2);
       		                 	    insert_node(root_node, $3);
       		                 	    $$ = root_node;
       		                 	}
       	;


Dec
   	:	VarDec           	{
   		                 	    root_node = new_node(233, "Dec", "NULL", $1->lineno);
                                    insert_node(root_node, $1);
   		                 	    $$ = root_node;
   		                 	}
   	|	VarDec ASSIGN Exp	{
   		                 	    root_node = new_node(233, "Dec", "NULL", $1->lineno);
                                    insert_node(root_node, $1);
   		                 	    insert_node(root_node, $2);
   		                 	    insert_node(root_node, $3);
   		                 	    $$ = root_node;
   		                 	}
   	|	VarDec ASSIGN ERR	{
								insert_err(1, 0, "error");
   		                 	}
   	;


/* Expression */
Exp
   	:	Exp ASSIGN Exp          	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp ERR Exp             	{
			  							insert_err(1, 0, "error");
   		                        	}
   	|	Exp ASSIGN ERR          	{
			  							insert_err(1, 0, "error");
   		                        	}
   	|	Exp AND Exp             	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp OR Exp              	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp LT Exp              	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp LE Exp              	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp GT Exp              	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp GE Exp              	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp NE Exp              	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp EQ Exp              	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp PLUS Exp            	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    $$ = root_node;
   		                        	}
    | 	MINUS Exp %prec SUB 		{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp MINUS Exp  %prec SUB	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp MUL Exp             	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp DIV Exp             	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    $$ = root_node;
   		                        	}
   	|	LP Exp RP               	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    $$ = root_node;
   		                        	}
   	|	LP Exp error RP         	{
										insert_err(1, $1 -> lineno, "Missing closing parenthesis ')'");
   		                        	}
   	|	SUB Exp %prec MINUS     	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    $$ = root_node;
   		                        	}
   	|	NOT Exp                 	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    $$ = root_node;
   		                        	}
   	|	ID LP Args RP           	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    insert_node(root_node, $4);
   		                        	    $$ = root_node;
   		                        	}
   	|	ID LP Args error SEMI   	{
   		                        	    unput(';');
										insert_err(1, $1 -> lineno, "Missing closing parenthesis ')'");
   		                        	}
   	|	ID LP RP                	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    $$ = root_node;
   		                        	}
   	|	ID LP error RP          	{
										insert_err(1, $1 -> lineno, "Missing closing parenthesis ')'");
   		                        	}
   	|	Exp LB Exp RB           	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    insert_node(root_node, $4);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp DOT ID              	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    $$ = root_node;
   		                        	}
   	|	ID                      	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    $$ = root_node;
   		                        	}
   	|	INT                     	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    $$ = root_node;
   		                        	}
   	|	FLOAT                   	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    $$ = root_node;
   		                        	}
   	|	CHAR                    	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    $$ = root_node;
   		                        	}
   	;

Args
    	:	Exp COMMA Args	{
    		              	    root_node = new_node(233, "Args", "NULL", $1->lineno);
                                insert_node(root_node, $1);
    		              	    insert_node(root_node, $2);
    		              	    insert_node(root_node, $3);
    		              	    $$ = root_node;
    		              	}
    	|	Exp           	{
    		              	    root_node = new_node(233, "Args", "NULL", $1->lineno);
                                insert_node(root_node, $1);
    		              	    $$ = root_node;
    		              	}
    	;




%%


int main(int argc, char **argv){

    FILE* fin = NULL;
    extern FILE* yyin;
    fin = fopen(argv[1],"r");

    if(fin == NULL)
    {
        printf("cannot open reading file.\n");
        return -1;
    }
    yyin = fin;
    /* yydebug = 1; */
    yyparse();
    fclose(fin);

    if (root_err == NULL)
        display(root_node, 0);
	else
		for (struct Error* now = root_err; now != NULL; now = now->next) {
			print_err(now);
		}
    return 0;

}
