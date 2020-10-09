%{
    #include "syntax.tab.h"
    #define debug
%}

%option noyywrap
%option yylineno


%%


int|float|char {
#ifdef debug
    puts("type");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return TYPE;
#endif
}


0(x|X)([0-9A-F]{1,8}) {
#ifdef debug
    puts("INT (hex)");
    printf("text: %s\n", yytext);
#endif
    #ifndef debug
    // yylval.token_p= newNode(yytext,No_Line);
    return INT;
#endif
}
[0-9]{1,10} {
#ifdef debug
    puts("INT (dec)");
    printf("text: %s\n", yytext);
#endif
    #ifndef debug
    // yylval.token_p= newNode(yytext,No_Line);
    return INT;
#endif
}

([1-9][0-9]*|[0]{1,1})[.][0-9]* {
#ifdef debug
    puts("FLOAT");
    printf("text: %s\n", yytext);
#endif
    //
    #ifndef debug
    // yylval.token_p= newNode(yytext,No_Line);
    return FLOAT;
#endif
}

'[a-zA-Z0-9_]' {
#ifdef debug
    puts("CHAR (char)");
    printf("text: %s\n", yytext);
#endif
    //
    #ifndef debug
    // yylval.token_p= newNode(yytext,No_Line);
    return CHAR;
#endif
}
'\\[xX][0-9a-fA-F]{2}' {
#ifdef debug
    puts("CHAR (hex)");
    printf("text: %s\n", yytext);
#endif
    //
    #ifndef debug
    // yylval.token_p= newNode(yytext,No_Line);
    return CHAR;
#endif
}



"struct" {
#ifdef debug
    puts("STRUCT");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return STRUCT;
#endif
}
"if" {
#ifdef debug
    puts("IF");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return IF;
#endif
}
"else" {
#ifdef debug
    puts("ELSE");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return ELSE;
#endif
}
"while" {
#ifdef debug
    puts("WHILE");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return WHILE;
#endif
}
"return" {
#ifdef debug
    puts("RETURN");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return RETURN;
#endif
}


"<" {
#ifdef debug
    puts("LT");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return LT;
#endif
}

"<=" {
#ifdef debug
    puts("LE");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return LE;
#endif
}

">" {
#ifdef debug
    puts("GT");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return GT;
#endif
}

">=" {
#ifdef debug
    puts("GE");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return GE;
#endif
}

"==" {
#ifdef debug
    puts("EQ");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return EQ;
#endif
}

"!=" {
#ifdef debug
    puts("NE");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return NE;
#endif
}



"," {
#ifdef debug
    puts("COMMA");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return COMMA;
#endif
}

";" {
#ifdef debug
    puts("SEMI");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return SEMI;
#endif
}

"." {
#ifdef debug
    puts("DOT");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return DOT;
#endif
}



"(" {
#ifdef debug
    puts("LP");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return LP;
#endif
}

")" {
#ifdef debug
    puts("RP");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return RP;
#endif
}

"[" {
#ifdef debug
    puts("LB");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return LB;
#endif
}

"]" {
#ifdef debug
    puts("RB");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return RB;
#endif
}

"{" {
#ifdef debug
    puts("LC");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return LC;
#endif
}

"}" {
#ifdef debug
    puts("RC");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return RC;
#endif
}


"&&" {
#ifdef debug
    puts("AND");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return AND;
#endif
}
"||" {
#ifdef debug
    puts("OR");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return OR;
#endif
}
"!" {
#ifdef debug
    puts("NOT");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return NOT;
#endif
}


"+" {
#ifdef debug
    puts("PLUS");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return PLUS;
#endif
}
"-" {
#ifdef debug
    puts("MINUS");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return MINUS;
#endif
}
"*" {
#ifdef debug
    puts("MUL");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return MUL;
#endif
}
"/" {
#ifdef debug
    puts("DIV");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return DIV;
#endif
}
"=" {
#ifdef debug
    puts("ASSIGN");
    printf("text: %s\n", yytext);
#endif
#ifndef debug
    return ASSIGN;
#endif
}


[\n\t\r" "] {
// #ifdef debug
//     puts("empty");
//     printf("text: %s\n", yytext);
// #endif
}

[a-zA-Z_][a-zA-Z_0-9]* {
#ifdef debug
    puts("ID");
    printf("text: %s\n", yytext);
#endif
    // yylval.token_p= newNode(yytext,No_Line);
#ifndef debug
    return ID;
#endif
}

. { fprintf(stdout, "unknown symbol: %s\n", yytext); }

%%

int main(int argc, char **argv) {
    char *file_path;
    if(argc < 2){
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }
    else if(argc == 2){
        file_path = argv[1];
        if(!(yyin = fopen(file_path, "r"))){
            perror(argv[1]);
            return 1;
        }
        yylex();
        return 0;
    }
    else{
        fprintf("Too much arguments!\n", stderr);
        return 1;
    }
}
