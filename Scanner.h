#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED
#include <stdbool.h>
enum TokenType {
 Number,
 Addition='+',
 Multiplication='*',
 Substraction='-',
 Division='/',
 PopResult='\n',
 LexError
};

typedef union { double d; char s;  } TokenValue;

typedef enum TokenType TokenType;


typedef struct 
{
 TokenType type;
 TokenValue val;
} Token;

bool GetNextToken(Token *t /*out*/);

#endif
