#include "monty.h"

void f_rotl(stack_s **stack, unsigned int line_number)
{
    stack_s *aux, *new;
    unsigned int temp;
	(void)line_number;
	if (stack != NULL)
	{
		new = malloc(sizeof(stack_s));
		if (!new)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		aux = *stack;
		temp = aux->n;
		*stack = aux->next;
		free(aux);
		aux = *stack;
		while(aux->next)
			aux = aux->next;
		aux->next = new;
		new->n = temp;
		new->prev = aux;
		new->next = NULL;
	}
}
