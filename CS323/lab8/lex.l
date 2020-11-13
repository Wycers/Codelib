%{
    #include"syntax.tab.h"
    #ifndef JSON
        #include "json.hpp"
    #endif
%}

%option noyywrap

unic u[0-9a-fA-F]{4}
esc \\([\"\\/bfnrt]|{unic})
scp [^"\\\x00-\x1f]
string \"({esc}|{scp})*\"

int 0|[1-9][0-9]*
frac \.[0-9]+
exp [Ee][+-]?[0-9]+
number -?{int}{frac}?{exp}?

err 0[0-9][0-9]*

empty [ \n\r\t]

%%

"{" { return LC; }
"}" { return RC; }
"[" { return LB; }
"]" { return RB; }
":" { return COLON; }
"," { return COMMA; }

"true" {
    yylval.JsonObject = json_bool(TRUE);
    return TRUE;
}
"false" {
    yylval.JsonObject = json_bool(FALSE);
    return FALSE;
}
"null" {
    yylval.JsonObject= json_vnull();
    return VNULL;
}

{string} {
    yylval.JsonObject = json_string(yytext);
    return STRING;
}
{number} {
    yylval.JsonObject = json_number(atoi(yytext));
    return NUMBER;
}

{empty} {}

{err} {
    printf("lexical error: %s\n", yytext);
    return err;
}

. { printf("lexical error: %s\n", yytext); }
