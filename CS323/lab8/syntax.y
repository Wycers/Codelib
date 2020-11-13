%{
    #include"lex.yy.c"
    #ifndef JSON
        #include "json.hpp"
    #endif
    void yyerror(const char*);

    ArrayValue *array_value_;
    ArrayValue *array_head_;
%}
%union {
    struct JsonObject *JsonObject;
    struct ObjectMember *ObjectMember;
}
%token <JsonObject> LC RC LB RB COLON COMMA
%token <JsonObject> STRING NUMBER
%token <JsonObject> TRUE FALSE VNULL err
%type <JsonObject> Value Array Object Member Members
%type <ObjectMember> Json

%%

Json:
      Value {$$ = object_value_member($1);}
    ;
Value:
      Object {$$ = $1;}
    | Array {$$ = $1;}
    | STRING {$$ = $1;}
    | NUMBER {$$ = $1;}
    | TRUE {$$ = $1;}
    | FALSE {$$ = $1;}
    | VNULL {$$ = $1;}
    ;
Object:
      LC RC {}
    | LC Members RC {$$ = $2;}
    | LC Members RC error           { puts("extra value after close, recovered"); }
    ;
Members:
      Member {$$ = $1;}
    | Member COMMA Members          {$$ = add_object($3, $1);}
    | Members COMMA error           { puts("unmatched right, recovered"); }
    | Member COMMA error            { puts("extra comma, recovered"); }
    ;
Member:
      STRING COLON Value {
        $$ = json_object(object_member($1->string, $3, NULL));
      }
    | STRING COLON error            { puts("double colon, recovered"); }
    | STRING error Value            { puts("missing colon, recovered"); }
    ;
Array:
      LB RB
    | LB Values RB RB error         { puts("extra close, recovered"); }
    | LB Values RB                  { $$ = json_array(array_value_); }
    | LB Values RB COMMA error      { puts("comma after the close, recovered"); }
    | LB Values error Values RB     { puts("unclosed array, recovered"); }
    | LB Values error               { puts("unclosed array, recovered"); }
    | LB Values RC error            { puts("unmatched right bracket, recovered"); }
    ;
Values:
      Value                         {
                                        array_value_ = array_value($1);
                                        array_head_ = array_value_;
                                    }
    | COMMA COMMA                   { puts("double comma, recovered");}
    | Value COMMA error             { puts("extra comma, recovered");}
    | COMMA Value error             { puts("missing value, recovered");}
    | Value COMMA Values            {
                                        array_value_->next = array_value($1);
                                        array_value_ = array_value_->next;
                                    }
    ;
%%

void yyerror(const char *s){
    printf("syntax error: ");
}
