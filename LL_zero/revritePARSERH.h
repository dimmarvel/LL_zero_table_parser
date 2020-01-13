#ifndef _PARSER_H_
#define _PARSER_H_


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lex_analyzer.h"

#define PARSER_TABLE_ROW 6
#define PARSER_TABLE_COLS 7

#define ERROR -1
#define EMPTY -1

#define PARSE_STACK_SIZE 10
#define VALUE_STACK_SIZE 10

#define TODO_TABLE_COL_LEN 4
#define TODO_TABLE_ROW_LEN 8

enum NONTERMINAL {
	STMT = 10,
	EXPR = 11,
	EXPR_PRIME = 12,
	TERM = 13,
	TERM_PRIME = 14,
	FACT = 15
};
enum ACTION {
	PLUS_ACT = 100,
	STAR_ACT = 101,
};

int parse_input(char* input_str);

static void init_parse_table();
static void init_todo_table();
static int parse_stack_pop();
static void parse_stack_push(int value);
static int value_stack_push();
static void value_stack_push(int value);
static void init();
static enum NONTERMINALS index_to_nonterminal(int index);
static int nonterminal_to_index(NONTERMINAL nonterm);
static void parse_stack_substitue(int value);

#endif