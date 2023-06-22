#include "monty.h"

my_data_t my_data = {0, NULL, NULL};
int main(int argc, char **argv)
{
	
	if (argc != 2)
		print_usage_error();
	
	
	return (execute_file(argv[1]));
	
}
