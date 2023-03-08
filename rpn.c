#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
#include "rpn.h"


float rpneval(char input[]) {
stack top;
int i = -1;
int state = 0;
char temp[101];
int temp_index = 0;
float num1, num2, ans, x;

init_stack(&top);

while (1) {
switch (state) {
case 0:
i++;
if ((input[i] == '+') || (input[i] == '-') || (input[i] == '*') || (input[i] == '/'))
state = 1;
else if (isdigit(input[i]))
state = 2;
else if (input[i] == ' ')
state = 4;
else if (input[i] == '\0')
state = 5;
else
state = 6;
break;
case 1:
if (!is_empty(top))
num2 = pop(&top);
else {
printf("Error! No number available\n");
exit(0);
}
if (!is_empty(top))
num1 = pop(&top);
else {
printf("Error! No number available\n");
exit(0);
}
switch (input[i]){
case '+': ans = num1 + num2;
if (!is_full()) {
push(&top,ans);
}
else {
printf("Error! stack is full\n");
exit(0);
}
break;
case '-': ans = num1 - num2;
if (!is_full()) {
push(&top,ans);
}
else {
printf("Error! stack is full\n");
exit(0);
}
break;
case '*': ans = num1 * num2;
if (!is_full()) {
push(&top,ans);
}
else {
printf("Error! stack is full\n");
exit(0);
}
break;
case '/': if (num2 == 0) {
printf("Error! Division by zero\n");
exit(0);
}
else {
ans = (num1 / num2);

if (!is_full()) {
push(&top,ans);
}
else {
printf("Error! stack is full\n");
exit(0);
}
}
break;
}

state = 0;
break;
case 2:
temp[temp_index] = input[i];
temp_index++;
i++;
if ((input[i] == '.') || (isdigit(input[i])))
state = 2;
else
state = 3;
break;
case 3:
temp[temp_index] = '\0';
sscanf(temp, "%f", &x);
if (!is_full()) {
push(&top, x);
}
else {
printf("Error! Stack is full\n");
exit(0);
}
temp_index = 0;
i--;
state = 0;
break;
case 4:
state = 0;
break;
case 5:
if (!is_empty(top)) {
x = pop(&top);
if (is_empty(top)){
return x;
}
else {
printf("Error! LeftOvers in Stack\n");
exit(0);
}
}
else {
printf("Error! Stack is Empty\n");
exit(0);
}
break;

case 6:
printf("Error! Invalid Input\n");
exit(0);
break;
}
}
}

rpn.h

#ifndef RPN_H
#define RPN_H

float rpneval(char input[]);

#endif
