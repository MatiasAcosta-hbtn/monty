#include "monty.h"

void f_rotl(stack_s **stack, unsigned int line_number)
{
	stack_s *aux, *new;
	unsigned int temp;
	int stack_len = 0;

	(void)line_number;
	stack_len = list_len(stack);
	if (*stack != NULL && stack_len >= 2)
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
	return;
}

void f_rotr(stack_s **stack, unsigned int line_number)
{
	stack_s *aux;
	int stack_len = 0;
	unsigned int temp, temp2;

	(void)line_number;
	stack_len = list_len(stack);
	if (*stack != NULL && stack_len >= 2)
	{
		aux = *stack;
		temp = aux->n;
		while (aux->next)
			aux = aux->next;
		
		temp2 = aux->n;
		aux->n = temp;
		aux = *stack;
		aux->n = temp2;
	}
	return;
}
