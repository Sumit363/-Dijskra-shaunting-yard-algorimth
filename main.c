
#include <stdio.h>
#include <string.h>
#include "rpn.h"

/*   Name: Sumit Basnet
	Class: Data Structure
	Assignment: FSM - Dijkstra's Shunting Yard Algorithm
*/



int main(void){
	char my_input[101];
	printf("Enter an expression: ");
	gets(&input);
	printf("%.2f\n", algtorpn(input));
	return 0;
}


