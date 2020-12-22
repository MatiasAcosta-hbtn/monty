#include "monty.h"

int search_function(char *token, unsigned int line_n, stack_s **head)
{
	instruction_t options[] = { 
				{"pall", f_pall}, {"push", f_push}, {"pint", f_pint}, {"pop", f_pop}, {"swap", f_swap}, 
				{"add", f_add}, {"sub", f_sub}, {"div", f_div}, {"mul", f_mul}, {"mod", f_mod}, {"pchar", f_pchar}, 
				{"pstr", f_pstr}, {"nop", f_nop}, {"rotl",f_rotl},{"rotr",f_rotr}, {NULL, NULL} };
	int i = 0;
	while(options[i].opcode != NULL)
	{
		if (strcmp(options[i].opcode, token) == 0)
		{
			options[i].f(head, line_n);
			return(1);
		}
		i++;
	}
	fprintf(stderr,"L%u: unknown instruction %s\n",line_n, token);
	free_stack(*head);
	exit(EXIT_FAILURE);
}

void f_push(stack_s **stack, unsigned int line_number)
{
	stack_s *new = NULL;

	(void) line_number;
	if (!stack)
	{
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_s));
	if (!new)
	{
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new->n = number;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;

	*stack = new;
	return;
}

void f_pall(stack_s **stack, unsigned int line_number)
{
	stack_s *aux;

	(void) line_number;
	if (stack == NULL)
	{
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	aux = *stack;

	while (aux)
	{
		printf("%i\n", aux->n);
		aux = aux->next;
	}
	return;
}

void f_pint(stack_s **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
	return;
}

void f_pop(stack_s **stack, unsigned int line_number)
{
	stack_s *aux;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	*stack = (*stack)->next;
	free(aux);
	return;
}

void f_pchar(stack_s **stack, unsigned int line_number)
{
	int num = 0;
	stack_s *tmp = *stack;

	if (!tmp)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	num = tmp->n;
	if (num < 0 || num > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
                free_stack(*stack);
                exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}

void f_pstr(stack_s **stack, unsigned int line_number)
{

	stack_s *aux = *stack;

	(void)line_number;
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	while ((aux))
	{
		if (aux->n <= 0 || aux->n > 127)
			break;
		printf("%c", aux->n);
		aux = aux->next;
	}
	printf("\n");
}
