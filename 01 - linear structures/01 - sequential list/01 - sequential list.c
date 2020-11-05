#include <stdio.h>

#define MAX 5 //Max range for the array

typedef int TIPOCHAVE; //used as id for each element

typedef struct{
	TIPOCHAVE chave;
	char nome[50];
	int idade;
}RECORD;

typedef struct{
	RECORD vetorRecord[MAX];
	int numberElements;
}LIST;

void main(){
	printf("Hello world!");
}