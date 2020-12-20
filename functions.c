#include "monty.h"

int search_opcode(char *token, unsigned int line_n, stack_s **head, int number)
{
	instruction_t options[] = { {"pall", f_pall},{"push", f_push}, {NULL, NULL} };
	int i = 0;
	printf("Entro en la funcion");
	while(options[i].opcode != NULL)
	{
		printf("opcode y token: %s y %s\n",options[i].opcode, token);
		if (strcmp(options[i].opcode, token) == 0)
		{
			options[i].f(head, line_n);
			return(1);
		}
		i++;
	}
	return (0);
}

void f_push(stack_s **stack, unsigned int line_number)
{
}
void f_pall(stack_s **stack, unsigned int line_number)
{
	printf("es un pall\n");
}
