
#ifndef STACK_H
#define STACK_H
#include "boolean.h"


typedef struct stacknode{
	float data;
	struct stacknode *next;
	} *stack;

void init_stack(stack *);

boolean is_full(void);

boolean is_empty(stack);

void push(stack *, float);

float pop(stack *);

void print_stack(stack);

#endif
