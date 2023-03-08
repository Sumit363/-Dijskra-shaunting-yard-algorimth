#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
#include "rpn.h"
#include "algtorpn.h"


int is_operator(char c) {	// finds out is the char is operator
    const char* operators = "+-*/";
    return (strchr(operators, c) != NULL);
	}

int get_prec(char operator) {	//gets the precedence of operator
    switch(operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    	}
}

float algtorpn(char input[]) {
    stack top;
    int i = -1;
    int state = 0;
    char temp[101];
    int temp_index = 0;
    char ch1, ch2, ch3, ch4, ch5;

    init_stack(&top);	// initializing the stack

    while (1) {
        switch (state) {
            case 0:
                i++;
                if (isdigit(input[i]))
                    state = 1;
                else if ((input[i] == '+') || (input[i] == '-') || (input[i] == '*') || (input[i] == '/'))
                    state = 2;
                else if (input[i] == '(')
                    state = 3;
                else if (input[i] == ')')
                    state = 4;
                else if (input[i] == '\0')
                    state = 5;
                else
                    state = 6;
                break;
            case 1:
                temp[temp_index] = input[i];
                temp_index++;
                i++;
                while ((input[i] == '.') || (isdigit(input[i]))) {
                    temp[temp_index] = input[i];
                    temp_index++;
                    i++;
                }
                temp[temp_index] = ' ';
                temp_index++;
                i--;
                state = 0;
                break;
            case 2:
                while (!is_empty(top) && is_operator(top->data) && (get_prec(input[i]) <= get_prec(top->data))){
                    ch1 = pop(&top);
                    temp[temp_index] = ch1;
                    temp_index++;
                    temp[temp_index] = ' ';
                    temp_index++;
                	}
                if (!is_full())
                    push(&top, input[i]);
                else {
                    printf("Error! Stack is full\n");
                    exit(0);
                	}
                state = 0;
                break;
            case 3:
                if (!is_full())
                    push(&top, input[i]);
                else {
                    printf("Error! Stack is full\n");
                    exit(0);
                }
                state = 0;
                break;
            case 4:
                while (!is_empty(top) && (top->data != '(')){
                    ch2 = pop(&top);
                    temp[temp_index] = ch2;
                    temp_index++;
                    temp[temp_index] = ' ';
                    temp_index++;
                }
                if (!is_empty(top))
                    ch3 = pop(&top);
                else {
                    printf("Error! Empty stack.\n");
                    exit(0);
                }
                 state = 0;
                 break;
            case 5:
                while (!is_empty(top) && is_operator(top->data)){
                    ch4 = pop(&top);
                    temp[temp_index] = ch4;
                    temp_index++;
                    temp[temp_index] = ' ';
                    temp_index++;
                }
                if (!is_empty(top)){
                    printf("Error! Stack is not empty.\n");
                    exit(0);
                }
                else {
                    temp[temp_index] = '\0';
                    return rpneval(temp);	// sends the value to RPN Evaluator program
                }
                break;
            case 6:
                printf("Error! Input not recognized\n");
                exit(0);
                break;
        }
    }
}
