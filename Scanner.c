#include<stdio.h>
#include "StackModule.h"
#define MaxLongitud 100
#include "Scanner.h"
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

typedef enum TokenType TokenType;

bool GetNextToken(Token *t) // Retorna si pudo leer, almacena en t el token leido.
{
	int i;
	char c;
	char s[MaxLongitud];
	i = 0;		
		
	while (((c = getchar()) == ' ' || c == '\t') && c != EOF)
	;
	
	switch (c) {
		case Addition:
			t->type = Addition;
			t->val.s = c;
			return true;
		case Multiplication:
			t->type = Multiplication;
			t->val.s = c;
			return true;
		case Substraction:
			t->type = Substraction;
			t->val.s = c;
			return true;
		case Division:
			t->type = Division;
			t->val.s = c;
			return true;
		case PopResult:
			t->type = PopResult;
			t->val.s = c;
			return true;
		case EOF:
			return false;
		default:
			if (!isdigit(c)) /* reune la parte entera */
			 {
			 	t->type = LexError;
				t->val.s = c;
				return true;
			 }
			
			if (isdigit(c)) /* reune la parte entera */
				s[i++] = c;
				while (isdigit(s[i++] = c = getchar()))
					;
			if (c == '.') /* reune la parte fraccionaria */
				while (isdigit(s[i++] = c = getchar()))	
					;
			s[i] = '\0';
			if (c != EOF)
				ungetc(c,stdout);
			t->type = Number;
			t->val.d = atof(s);
			return true;					
	}
}
