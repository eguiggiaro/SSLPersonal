#include <stdio.h>
#include <stdlib.h>
#include "StackModule.h"
#include "Scanner.h"

#define MAXOP 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	int getop(char [ ]);


int main() {
	
	double op2;
	Token t;
	
	

	while (GetNextToken(&t)) {
		switch(t.type) {
		case Number:
			Push(t.val.d);
			break;
		case Addition:
			Push(Pop() + Pop());
			break;
		case Multiplication:
			Push(Pop() * Pop());
			break;
		case Substraction:
			op2 = Pop();
			Push(Pop() - op2);
			break;
		case Division:
			op2 = Pop();
			if (op2 != 0.0)
				Push(Pop() / op2);
			else
				printf("error: divisor cero\n");
			break;
		case PopResult:
			printf("\t%.8g\n",Pop());
			break;
		case LexError:
			printf("error: comando desconocido %c\n",t.val.s);
			break;
		}
	}
	return 0;

}
