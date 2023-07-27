SRC_DIR := ./src
BUILD_DIR := ./build

all: compiler

compiler: parser lexer build_dir
	gcc -lfl -o $(BUILD_DIR)/parser.o -c $(SRC_DIR)/parser/y.tab.c
	g++ -o $(BUILD_DIR)/parse $(BUILD_DIR)/parser.o $(SRC_DIR)/main.cpp

parser:
	cd $(SRC_DIR)/parser && yacc -v -d parser.y

lexer:
	cd $(SRC_DIR)/parser && flex lexer.l

build_dir:
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(SRC_DIR)/parser/y.tab.c
	rm -f $(SRC_DIR)/parser/y.tab.h
	rm -f $(SRC_DIR)/parser/y.output
	rm -f $(SRC_DIR)/parser/lex.yy.c
	rm -rf ${BUILD_DIR}