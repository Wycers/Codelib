CC=g++
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

semantic_analysis: .lex .syntax
	$(CC) -c src/semantic_analysis.hpp -o semantic_analysis.o -I src


splc: node error
	# @mkdir bin
	$(CC) \
		-g syntax.tab.c \
		src/error/error.o \
		src/node/node.o \
		-lfl -ly \
		-o bin/splc \
		-I src/node \
		-I src/error \
		-I src \
		-I src/symbol_table \
		-I .
	@chmod +x bin/splc

clean:
	@rm -f lex.yy.c syntax.tab.* *.out
	@rm -rf bin/
