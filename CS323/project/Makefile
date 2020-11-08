CC=gcc
FLEX=flex
BISON=bison

.PHONY: .lex .syntax node

.lex: lex.l
	$(FLEX) lex.l

.syntax: syntax.y
	$(BISON) -t -d syntax.y


node: .lex .syntax
	$(CC) -c src/node/node.c -o src/node/node.o

error: .lex .syntax
	$(CC) -c src/error/error.c -o src/error/error.o

splc: node error
	# @mkdir bin
	$(CC) syntax.tab.c \
		src/error/error.o \
		src/node/node.o \
		-lfl -ly \
		-o bin/splc \
		-I src/node \
		-I src/error
	@chmod +x bin/splc

clean:
	@rm -f lex.yy.c syntax.tab.* *.out
	@rm -rf bin/
