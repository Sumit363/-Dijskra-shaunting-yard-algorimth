
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "boolean.h"



void init_stack(stack *s){
	(*s) = NULL;
	}


boolean is_full(void){
	stack temp;
	temp = (stack) malloc (sizeof(struct stacknode));
	if (temp == NULL)
	return TRUE;
	else{
		free (temp);
	return FALSE;
		}
	}

 boolean is_empty(stack s){
	if (s == NULL)
	return TRUE;
	else
	return FALSE;
	}


void push(stack *s, float x){
		stack temp;
		temp = (stack) malloc(sizeof(struct stacknode));
		temp -> data = x;
		temp -> next = (*s);
		(*s) = temp;
		}


float pop(stack *s){
	stack temp;
	float data_popped;
	temp = *s;
	data_popped = temp -> data;
	*s = temp -> next;
	free (temp);
	return data_popped;
	}


void print_stack(stack s){
	if(!is_empty(s)){
	printf("%f\n", s -> data);
	print_stack (s -> next);
	}
	}



