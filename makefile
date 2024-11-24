compiler:
	bison -d -v -r all parser.y
	flex lexer.l
	gcc -o compiler lex.yy.c parser.tab.c cgen.c -lfl
	./compiler < qsortWithComp.la
clean:
	rm -f compiler