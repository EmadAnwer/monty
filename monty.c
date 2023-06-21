#include "monty.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		print_usage_error();
	
	return (execute_file(argv[1]));
}
