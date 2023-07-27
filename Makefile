all: frontend

frontend: parser lexer
	gcc -lfl -o parser.o -c y.tab.c
	g++ -o parse parser.o main.cpp

parser:
	yacc -v -d parser.y

lexer:
	flex lexer.l

clean:
	rm -f y.tab.c
	rm -f y.tab.h
	rm -f y.output
	rm -f lex.yy.c
	rm -f parse
	rm -f parser.o