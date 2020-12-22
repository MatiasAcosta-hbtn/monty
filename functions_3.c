#include "monty.h"

/**
 * f_rotl - rotates the stack to the top.
 * @stack: head of double linked lisd
 * @line_number: line of code of file bytecode
 **/
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
		while (aux->next)
			aux = aux->next;
		aux->next = new;
		new->n = temp;
		new->prev = aux;
		new->next = NULL;
	}
}

/**
 * f_rotr - rotates the stack to the bottom
 * @stack: head of double linked lisd
 * @line_number: line of code of file bytecode
 **/
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
		temp = (*stack)->n;
		while (aux->next)
			aux = aux->next;

		temp2 = aux->n;
		aux->n = temp;
		(*stack)->n = temp2;
	}
}
