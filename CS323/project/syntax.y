%{
    #include "lex.yy.c"
	#include "stdio.h"

	#include "node.h"
	#include "error.h"

    void yyerror(const char* msg) {}

    struct Node *root_node = NULL;
%}

%union{ struct Node *node; }

%nonassoc THEN
%nonassoc<node> ELSE

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
										set_node_type(root_node, NodeType::ExtDefList);
          		                 	    $$ = root_node;
          		                 	}
			| 	%empty 				{
										$$ = NULL;
									};
          	;


ExtDef
      	:	Specifier ExtDecList SEMI 	{
      		                          	    root_node = new_node(233, "ExtDef", "NULL", $1->lineno);
                                            insert_node(root_node, $1);
      		                          	    insert_node(root_node, $2);
      		                          	    insert_node(root_node, $3);
											set_node_type(root_node, NodeType::Declare);
      		                          	    $$ = root_node;
      		                          	}
      	|	Specifier SEMI            	{
      		                          	    root_node = new_node(233, "ExtDef", "NULL", $1->lineno);
											insert_node(root_node, $1);
      		                          	    insert_node(root_node, $2);
											set_node_type(root_node, NodeType::StructDef);
      		                          	    $$ = root_node;
      		                          	}
      	|	Specifier FunDec CompSt   	{
      		                          	    root_node = new_node(233, "ExtDef", "NULL", $1->lineno);
											insert_node(root_node, $1);
      		                          	    insert_node(root_node, $2);
      		                          	    insert_node(root_node, $3);
											set_node_type(root_node, NodeType::FuncDef);
      		                          	    $$ = root_node;
      		                          	}
      	|	Specifier ExtDecList error	{
											syntax_error($2 -> lineno, "Missing semicolon ';'");
      		                          	}
      	|	error SEMI                	{
											syntax_error($2 -> lineno, "Missing specifier");
      		                          	}
      	;


ExtDecList
          	:	VarDec                 	{
          		                       	    root_node = new_node(233, "ExtDecList", "NULL", $1->lineno);
											insert_node(root_node, $1);
											set_node_type(root_node, NodeType::ExtDecListSingle);
          		                       	    $$ = root_node;
          		                       	}
          	|	VarDec COMMA ExtDecList	{
          		                       	    root_node = new_node(233, "ExtDecList", "NULL", $1->lineno);
											insert_node(root_node, $1);
          		                       	    insert_node(root_node, $2);
          		                       	    insert_node(root_node, $3);
											set_node_type(root_node, NodeType::ExtDecListMultiple);
          		                       	    $$ = root_node;
          		                       	}
          	;


/* specifier */
Specifier
         	:	TYPE           	{
         		               	    root_node = new_node(233, "Specifier", "NULL", $1->lineno);
									insert_node(root_node, $1);
									set_node_type(root_node, NodeType::Specifier);
         		               	    $$ = root_node;
         		               	}
         	|	StructSpecifier	{
         		               	    root_node = new_node(233, "Specifier", "NULL", $1->lineno);
									insert_node(root_node, $1);
									set_node_type(root_node, NodeType::StructSpecifier);
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
												set_node_type(root_node, NodeType::StructSpecifierWithBody);
               		                       	    $$ = root_node;
               		                       	}
               	|	STRUCT ID              	{
               		                       	    root_node = new_node(233, "StructSpecifier", "NULL", $1->lineno);
												insert_node(root_node, $1);
               		                       	    insert_node(root_node, $2);
												set_node_type(root_node, NodeType::StructSpecifierNoBody);
               		                       	    $$ = root_node;
               		                       	}
               	;


/* declarator */
VarDec
      	:	ID              	{
      		                	    root_node = new_node(233, "VarDec", "NULL", $1->lineno);
									insert_node(root_node, $1);
									set_node_type(root_node, NodeType::VarDec);
      		                	    $$ = root_node;
      		                	}
      	|	VarDec LB INT RB	{
      		                	    root_node = new_node(233, "VarDec", "NULL", $1->lineno);
									insert_node(root_node, $1);
      		                	    insert_node(root_node, $2);
      		                	    insert_node(root_node, $3);
      		                	    insert_node(root_node, $4);
									set_node_type(root_node, NodeType::VarDecArray);
      		                	    $$ = root_node;
      		                	}
      	|	ERR             	{
			  						syntax_error(0, "error");
      		                	}
      	;


FunDec
      	:	ID LP VarList RP      	{
      		                      	    root_node = new_node(233, "FunDec", "NULL", $1->lineno);
										insert_node(root_node, $1);
      		                      	    insert_node(root_node, $2);
      		                      	    insert_node(root_node, $3);
      		                      	    insert_node(root_node, $4);
										set_node_type(root_node, NodeType::FunDecArgs);
      		                      	    $$ = root_node;
      		                      	}
      	|	ID LP VarList error LC	{
      		                      	    unput('{');
										syntax_error($1 -> lineno, "Missing closing parenthesis ')'");
      		                      	}
      	|	ID LP  error LC       	{
      		                      	    unput('{');
										syntax_error($1 -> lineno, "Missing closing parenthesis ')'");
      		                      	}
      	|	ID LP RP              	{
      		                      	    root_node = new_node(233, "FunDec", "NULL", $1->lineno);
										insert_node(root_node, $1);
      		                      	    insert_node(root_node, $2);
      		                      	    insert_node(root_node, $3);
										set_node_type(root_node, NodeType::FunDec);
      		                      	    $$ = root_node;
      		                      	}
      	;


VarList
       	:	ParamDec COMMA VarList	{
       		                      	    root_node = new_node(233, "VarList", "NULL", $1->lineno);
										insert_node(root_node, $1);
       		                      	    insert_node(root_node, $2);
       		                      	    insert_node(root_node, $3);
										set_node_type(root_node, NodeType::VarList);
       		                      	    $$ = root_node;
       		                      	}
		| 	ParamDec COMMA error RP {
										unput(')');
										syntax_error($1->lineno, "Extra Comma");
									}
       	|	ParamDec              	{
       		                      	    root_node = new_node(233, "VarList", "NULL", $1->lineno);
										insert_node(root_node, $1);
										set_node_type(root_node, NodeType::ParamDec);
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
										syntax_error($2 -> lineno, "Missing semicolon ';'");
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
									set_node_type(root_node, NodeType::StmtList);
        		             	    $$ = root_node;
        		             	}
        	|	%empty      	{
        		             	    root_node = new_node(0, "NULL", "NULL", 0);
									$$ = root_node;
        		             	}
        	;


Stmt
    	:	Exp SEMI                    	{
    		                            	    root_node = new_node(233, "Stmt", "NULL", $1->lineno);
												insert_node(root_node, $1);
    		                            	    insert_node(root_node, $2);
												set_node_type(root_node, NodeType::StmtExp);
    		                            	    $$ = root_node;
    		                            	}
    	|	CompSt                      	{
    		                            	    root_node = new_node(233, "Stmt", "NULL", $1->lineno);
                                                insert_node(root_node, $1);
												set_node_type(root_node, NodeType::StmtCompSt);
    		                            	    $$ = root_node;
    		                            	}
    	|	RETURN Exp SEMI             	{
    		                            	    root_node = new_node(233, "Stmt", "NULL", $1->lineno);
                                                insert_node(root_node, $1);
    		                            	    insert_node(root_node, $2);
    		                            	    insert_node(root_node, $3);
												set_node_type(root_node, NodeType::StmtReturn);
    		                            	    $$ = root_node;
    		                            	}
    	|	Exp error SEMI              	{
												syntax_error($1 -> lineno, "Missing semicolon ';'");
    		                            	}
    	|	RETURN Exp error SEMI       	{
												syntax_error($1 -> lineno, "Missing semicolon ';'");
    		                            	}
    	|	IF LP Exp RP Stmt %prec THEN	{
    		                            	    root_node = new_node(233, "Stmt", "NULL", $1->lineno);
                                                insert_node(root_node, $1);
    		                            	    insert_node(root_node, $2);
    		                            	    insert_node(root_node, $3);
    		                            	    insert_node(root_node, $4);
    		                            	    insert_node(root_node, $5);
												set_node_type(root_node, NodeType::StmtIf);
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
												set_node_type(root_node, NodeType::StmtIfElse);
    		                            	    $$ = root_node;
    		                            	}
    	|	WHILE LP Exp RP Stmt        	{
    		                            	    root_node = new_node(233, "Stmt", "NULL", $1->lineno);
                                                insert_node(root_node, $1);
    		                            	    insert_node(root_node, $2);
    		                            	    insert_node(root_node, $3);
    		                            	    insert_node(root_node, $4);
    		                            	    insert_node(root_node, $5);
												set_node_type(root_node, NodeType::StmtWhile);
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
							set_node_type(root_node, NodeType::DefList);
       		           	    $$ = root_node;
       		           	}
       	|	%empty   	{
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
											syntax_error($1 -> lineno, "Missing semicolon ';'");
   		                            	}
   	|	error DecList SEMI          	{
											syntax_error($2 -> lineno, "Missing specifier");
   		                            	}
   	;


DecList
       	:	Dec              	{
       		                 	    root_node = new_node(233, "DecList", "NULL", $1->lineno);
									insert_node(root_node, $1);
									set_node_type(root_node, NodeType::VarDecListSingle);
       		                 	    $$ = root_node;
       		                 	}
       	|	Dec COMMA DecList	{
       		                 	    root_node = new_node(233, "DecList", "NULL", $1->lineno);
									insert_node(root_node, $1);
       		                 	    insert_node(root_node, $2);
       		                 	    insert_node(root_node, $3);
									set_node_type(root_node, NodeType::VarDecListMultiple);
       		                 	    $$ = root_node;
       		                 	}
       	;


Dec
   	:	VarDec           	{
   		                 	    root_node = new_node(233, "Dec", "NULL", $1->lineno);
								insert_node(root_node, $1);
								set_node_type(root_node, NodeType::Dec);
   		                 	    $$ = root_node;
   		                 	}
   	|	VarDec ASSIGN Exp	{
   		                 	    root_node = new_node(233, "Dec", "NULL", $1->lineno);
								insert_node(root_node, $1);
   		                 	    insert_node(root_node, $2);
   		                 	    insert_node(root_node, $3);
								set_node_type(root_node, NodeType::DecWithAssign);
   		                 	    $$ = root_node;
   		                 	}
   	|	VarDec ASSIGN ERR	{
								syntax_error(0, "error");
   		                 	}
   	;


/* Expression */
Exp
   	:	Exp ASSIGN Exp          	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
										set_node_type(root_node, NodeType::ExpAssign);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp ERR Exp             	{
			  							syntax_error(0, "error");
   		                        	}
   	|	Exp ASSIGN ERR          	{
			  							syntax_error(0, "error");
   		                        	}
   	|	Exp AND Exp             	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
										set_node_type(root_node, NodeType::ExpAnd);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp OR Exp              	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
										set_node_type(root_node, NodeType::ExpOr);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp LT Exp              	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
										set_node_type(root_node, NodeType::ExpLT);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp LE Exp              	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
										set_node_type(root_node, NodeType::ExpLE);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp GT Exp              	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
										set_node_type(root_node, NodeType::ExpGT);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp GE Exp              	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
										set_node_type(root_node, NodeType::ExpGE);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp NE Exp              	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
										set_node_type(root_node, NodeType::ExpNE);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp EQ Exp              	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
										set_node_type(root_node, NodeType::ExpEQ);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp PLUS Exp            	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
										set_node_type(root_node, NodeType::ExpPlus);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp MINUS Exp  				{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
										set_node_type(root_node, NodeType::ExpMinus);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp MUL Exp             	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
										set_node_type(root_node, NodeType::ExpMul);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp DIV Exp             	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
										set_node_type(root_node, NodeType::ExpDiv);
   		                        	    $$ = root_node;
   		                        	}
   	|	LP Exp RP               	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
										set_node_type(root_node, NodeType::ExpBracketWrapped);
   		                        	    $$ = root_node;
   		                        	}
   	|	LP Exp error RP         	{
										syntax_error($1 -> lineno, "Missing closing parenthesis ')'");
   		                        	}
    | 	MINUS Exp %prec NOT 		{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
										set_node_type(root_node, NodeType::ExpNegative);
   		                        	    $$ = root_node;
   		                        	}
   	|	NOT Exp                 	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
										set_node_type(root_node, NodeType::ExpNot);
   		                        	    $$ = root_node;
   		                        	}
   	|	ID LP Args RP           	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    insert_node(root_node, $4);
										set_node_type(root_node, NodeType::ExpArgsFuncCall);
   		                        	    $$ = root_node;
   		                        	}
   	|	ID LP Args error SEMI   	{
   		                        	    unput(';');
										syntax_error($1 -> lineno, "Missing closing parenthesis ')'");
   		                        	}
   	|	ID LP RP                	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
										set_node_type(root_node, NodeType::ExpFuncCall);
   		                        	    $$ = root_node;
   		                        	}
   	|	ID LP error RP          	{
										syntax_error($1 -> lineno, "Missing closing parenthesis ')'");
   		                        	}
   	|	Exp LB Exp RB           	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
   		                        	    insert_node(root_node, $4);
										set_node_type(root_node, NodeType::ExpArrayIndex);
   		                        	    $$ = root_node;
   		                        	}
   	|	Exp DOT ID              	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
   		                        	    insert_node(root_node, $2);
   		                        	    insert_node(root_node, $3);
										set_node_type(root_node, NodeType::ExpFiledAccess);
   		                        	    $$ = root_node;
   		                        	}
   	|	ID                      	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
										set_node_type(root_node, NodeType::ExpId);
   		                        	    $$ = root_node;
   		                        	}
   	|	INT                     	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
										set_node_type(root_node, NodeType::ExpInt);
   		                        	    $$ = root_node;
   		                        	}
   	|	FLOAT                   	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
										set_node_type(root_node, NodeType::ExpFloat);
   		                        	    $$ = root_node;
   		                        	}
   	|	CHAR                    	{
   		                        	    root_node = new_node(233, "Exp", "NULL", $1->lineno);
										insert_node(root_node, $1);
										set_node_type(root_node, NodeType::ExpChar);
   		                        	    $$ = root_node;
   		                        	}
   	;

Args
    	:	Exp COMMA Args	{
    		              	    root_node = new_node(233, "Args", "NULL", $1->lineno);
                                insert_node(root_node, $1);
    		              	    insert_node(root_node, $2);
    		              	    insert_node(root_node, $3);
								set_node_type(root_node, NodeType::ArgsMultiple);
    		              	    $$ = root_node;
    		              	}
    	|	Exp           	{
    		              	    root_node = new_node(233, "Args", "NULL", $1->lineno);
                                insert_node(root_node, $1);
								set_node_type(root_node, NodeType::ArgsSingle);
    		              	    $$ = root_node;
    		              	}
    	;


%%

#include "semantic_analysis.hpp"

int main(int argc, char **argv){

	char *filename = argv[1];


    FILE* fin = NULL;
    extern FILE* yyin;
    fin = fopen(filename, "r");

    if(fin == NULL)
    {
        printf("cannot open reading file.\n");
        return -1;
    }
    yyin = fin;
    /* yydebug = 1; */
    yyparse();
    fclose(fin);

	int len = strlen(filename);
	filename[len - 3] = 'o';
	filename[len - 2] = 'u';
	filename[len - 1] = 't';

	freopen(filename, "w", stdout);

	semantic_analysis(root_node);

    if (has_error()) {
		print_errors();
		return -1;
	}

	/* display(root_node, 0); */

	/* SYMBOL_TABLE.print(); */

	fclose(stdout);
	return 0;

}
