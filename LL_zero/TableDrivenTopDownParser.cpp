#include "parser.h"

int main(int argc, char** argv)
{

	int result;
	char q[19] = { '3', '*' ,'(' ,'3', '+','3',')', '+','3' };
	//result = parse_input(argv[1] + '\0');
	result = parse_input(q);
	
	printf("Result: %d\n", result);
	system("pause");
	return 0;

}