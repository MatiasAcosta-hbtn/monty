#include "monty.h"

int search_opcode(char *token, unsigned int line_n, stack_t **head)
{
	instruction_t options[] = { {"pall", f_pall},{"push", f_push}, {NULL, NULL} };
	int i = 0;

	while(options[i].opcode != NULL)
	{
		printf("opcode y token: %s y %s\n",options[i].opcode, token);
		if (strcmp(options[i].opcode, token) == 0)
		{
			printf("encontro coincidencia en :%s y %s\n",options[i].opcode, token);
			
			options[i].f(head, line_n);
		}
		i++;
	}
}

void f_push(stack_t **stack, unsigned int line_number)
{
	printf("es un push\n");
}
void f_pall(stack_t **stack, unsigned int line_number)
{
	printf("es un pall\n");
}
