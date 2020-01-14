#ifndef  _PARSER_H_
#define _PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lex_analyzer.h"

#define PARSE_TABLE_ROWS 6
#define PARSE_TABLE_COLS 7

#define ERROR -1
#define EMPTY -1

#define PARSE_STACK_SIZE 10
#define VALUE_STACK_SIZE 10

#define TODO_TABLE_COL_LEN 4
#define TODO_TABLE_ROW_LEN 8

enum NONTERMINALS {
	STMT = 10,
	EXPR = 11,
	EXPR_PRIME = 12,
	TERM = 13,
	TERM_PRIME = 14,
	FACT = 15
};

enum ACTIONS {
	PLUS_ACT = 100,
	STAR_ACT = 101
};

int parse_input(char* input_str); //

static void init_parse_table(void); //инициализирует таблицу парсинга
static void init_todo_table(void); // инит таблицу todo
static int parse_stack_pop(void); // извлекает элемент из вершины и уменьшает стек
static void parse_stack_push(int value);// помещает элемент из вершины и увел стек
static int value_stack_pop(void); //извлекает значение из вершины стека значений и уменьшает на 1
static void value_stack_push(int value); //помещает значение в стек значений и увел на 1
static void init(void); //запускает инициализацию таблицы  значений, парсинга, todo таблицы
static enum NONTERMINALS index_to_nonterminal(int index); //конвертирует индекс таблицы парсинга в нонтерминал
static int nonterminal_to_index(enum NONTERMINALS nonterm);//конвертирует нонтерминал в индекс таблицы парсинга
static void parse_stack_substitute(int value); //принимает индекс строки todo таблицы  помещает в стек парсинга
											   //все непустые значения из этой  строки todo таблицы

 #endif