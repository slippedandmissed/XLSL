SRC_DIR := ./src
BUILD_DIR := ./build

SRC_FILES := $(shell find $(SRC_DIR)/ -type f -name '*.cpp')

CC := gcc
CXX := g++
CPPFLAGS := -Wall -std=c++17 -g

all: compiler

compiler: parser
	$(CXX) $(CPPFLAGS) -o $(BUILD_DIR)/compile $(BUILD_DIR)/parser.o $(SRC_FILES)

parser: build_dir
	cd $(SRC_DIR)/parser && yacc -v -d parser.y
	cd $(SRC_DIR)/parser && flex lexer.l
	$(CC) -lfl -o $(BUILD_DIR)/parser.o -c $(SRC_DIR)/parser/y.tab.c

build_dir:
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(SRC_DIR)/parser/y.tab.c
	rm -f $(SRC_DIR)/parser/y.tab.h
	rm -f $(SRC_DIR)/parser/y.output
	rm -f $(SRC_DIR)/parser/lex.yy.c
	rm -rf ${BUILD_DIR}