%{
    #include"lex.yy.c"
    void yyerror(const char*);
%}

%token LC RC LB RB COLON COMMA
%token STRING NUMBER
%token TRUE FALSE VNULL
%%

Json:
      Value
    ;
Value:
      Object
    | Array
    | STRING
    | NUMBER
    | TRUE
    | FALSE
    | VNULL
    ;
Object:
      LC RC
    | LC Members RC
    | LC Members RC error           { puts("extra value after close, recovered"); }
    ;
Members:
      Member
    | Member COMMA Members
    | Members COMMA error           { puts("unmatched right, recovered"); }
    | Member COMMA error            { puts("extra comma, recovered"); }
    ;
Member:
      STRING COLON Value
    | STRING COLON error            { puts("double colon, recovered"); }
    | STRING error Value            { puts("missing colon, recovered"); }
    ;
Array:
      LB RB
    | LB Values RB RB error         { puts("extra close, recovered"); }
    | LB Values RB
    | LB Values RB COMMA error      { puts("comma after the close, recovered"); }
    | LB Values error Values RB     { puts("unclosed array, recovered"); }
    | LB Values error               { puts("unclosed array, recovered"); }
    | LB Values RC error            { puts("unmatched right bracket, recovered"); }
    ;
Values:
      Value
    | COMMA COMMA                   { puts("double comma, recovered");}
    | Value COMMA error             { puts("extra comma, recovered");}
    | COMMA Value error             { puts("missing value, recovered");}
    | Value COMMA Values
    ;
%%

void yyerror(const char *s){
    printf("syntax error: ");
}

int main(int argc, char **argv){
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(-1);
    }
    else if(!(yyin = fopen(argv[1], "r"))) {
        perror(argv[1]);
        exit(-1);
    }
    yyparse();
    return 0;
}
