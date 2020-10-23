CC=gcc
FLEX=flex
BISON=bison

.lex: lex.l
	$(FLEX) lex.l
.syntax: syntax.y
	$(BISON) -t -d syntax.y

.PHONY: splc
splc: .lex .syntax
	@mkdir bin
	$(CC) syntax.tab.c -lfl -ly -o bin/splc
	@chmod +x bin/splc
clean:
	@rm -f lex.yy.c syntax.tab.* *.out
	@rm -rf bin/
