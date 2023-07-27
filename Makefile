all: frontend

frontend: parser lexer
	gcc -lfl -o parse y.tab.c

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