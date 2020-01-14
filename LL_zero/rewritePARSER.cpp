#include "parser.h"
static int parse_table[PARSE_TABLE_ROWS][PARSE_TABLE_COLS];
static int todo_table[TODO_TABLE_ROW_LEN][TODO_TABLE_COL_LEN];
static int parse_stack[PARSE_STACK_SIZE];
static int value_stack[VALUE_STACK_SIZE];
static int parse_stack_index = -1;
static int value_stack_index = -1;

int parse_input(char* input_str) {
	token_lexeme token;
	int val1 = 0, val2 = 0;
	int top_of_stack;
	int action = 0;
	int parse_table_index;

	init();

	set_input_stream(input_str);
	token = get_next_token();

	if (token.token == UNKNOWN)
		return val1;

	parse_stack_push(STMT);

	while (parse_stack_index >= 0) {
		if (parse_stack[parse_stack_index] >= PLUS_ACT) {
			switch (parse_stack[parse_stack_index]) {
			case PLUS_ACT:
				val1 = value_stack_pop();
				val2 = value_stack_pop();
				val1 += val2;
				value_stack_push(val1);
				break;
			case STAR_ACT:
				val1 = value_stack_pop();
				val2 = value_stack_pop();
				val1 *= val2;
				value_stack_push(val1);
				break;
			default:
				break;
			}
		}
		else if (parse_stack[parse_stack_index] >= STMT) {
			top_of_stack = parse_stack_pop();
			parse_table_index = nonterminal_to_index(static_cast<NONTERMINALS>(top_of_stack));
			action = parse_table[parse_table_index][token.token];
			if (action < 0) {
				break;
			}
			else {
				parse_stack_substitute(action);
			}
		}
		else {
			top_of_stack = parse_stack_pop();
			if (top_of_stack < 0) {
				break;
			}
			if (top_of_stack != token.token) {
				break;
			}
			else {
				if (token.token == NUM) {
					value_stack_push(atoi(&token.lexeme));
				}
				token = get_next_token();
			}

		}
		return value_stack_pop();
	}