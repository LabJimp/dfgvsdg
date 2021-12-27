#include "fun_stack.h"

#include <stdlib.h>
#include <string.h>

typedef struct stack
{
	int par_level;
	char* funame;
	struct stack* next;
} stack;

stack* stos = NULL;

void put_on_fun_stack(int par_level, char* funame)
{
	stack* new_stack = malloc(sizeof(stack));
	char* new_funame = malloc((strlen(funame) + 1) * sizeof(char));
	strcpy(new_funame, funame);

	new_stack->par_level = par_level;
	new_stack->funame = new_funame;
	new_stack->next = stos;
	stos = new_stack;
}

char* get_from_fun_stack(void)
{
	if (stos == NULL) return NULL;
	char* result = stos->funame;
	stack* tmp = stos->next;
	free(stos);
	stos = tmp;

	return result;	
}

int top_of_funstack(void)
{
	if (stos == NULL) return -1;
	return stos->par_level;
}
