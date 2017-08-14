#include<stdio.h>
#include "StackModule.h"
#define MaxLongitud 100

double array[MaxLongitud]; 
int inicial = -1;  
 
void Push(double x) 
{
  if(inicial == MaxLongitud-1) { // overflow 
		printf("Error: Stack overflow\n");
		return;
	}
	array[++inicial] = x;
}

double Pop(void) 
{
	if(inicial == -1) { // Si la pila esta vacia, debe tirar un error 
		printf("Error: No element to pop\n");
		return -1;
	}
	return array[inicial--];
}

 
int IsFull()  //Si la pila esta completa, retorna 1, de lo contrario 0
{
	if(inicial == MaxLongitud) return 1;
    return 0;
}


int IsEmpty() //Si la pila esta vacia, retorna 1, de lo contrario 0
{
    if(inicial == -1) return 1;
    return 0;
}
