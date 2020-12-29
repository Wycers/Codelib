CMAKE=cmake
FLEX=flex
BISON=bison

.PHONY: .lex .syntax node

.lex: lex.l
	$(FLEX) -o src/lex.yy.c lex.l

.syntax: syntax.y
	$(BISON) -o src/syntax.tab.c --defines=src/syntax.tab.h -t -d syntax.y

splc: .lex .syntax
	-@mkdir build
	$(CMAKE) -S ./src -Bbuild
	$(CMAKE) --build ./build --target splc
	-@mkdir bin
	cp build/splc ./bin/
	-@chmod +x bin/splc

clean:
	@rm -f lex.yy.c syntax.tab.* *.out
	@rm -rf bin/
