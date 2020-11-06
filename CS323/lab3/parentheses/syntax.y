%{
    #include"lex.yy.c"
    void yyerror(const char *s);
    int result;
%}
%token LP RP LB RB LC RC
%%
XD: %empty {result = 1; }
    | Valid { result = 1; }
    ;

Valid: XD LP XD RP
    | XD LB XD RB
    | XD LC XD RC
;
%%

int validParentheses(char *expr){
    yy_scan_string(expr);
    yyparse();
    return result;
}

void yyerror(const char *s) {
    // fprintf(stderr, "Syntax error: %s\n", s);
    result = 0;
}
