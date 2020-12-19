#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_n = 0;
	char *token = NULL;
	stack_t *head;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		perror("fopen");
	exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		token = strtok(line, " \n\t\r");
		line_n++;
		search_opcode(token, line_n, &head);
		/*while(token != NULL)
		{
			printf("El token es:%s\n",token);
			token = strtok(NULL, " ");
		}*/
		
	}
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
