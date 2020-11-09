/*	A ORDERED SEQUENTIAL LIST	WITH SENTINEL ELEMENT*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 //Max range for the array

typedef int KEYTYPE; //used as id for each element

/*///////////////////////	STRUCTURES DEFINITIONS	/////////////////////////*/
///////////////////////////////////////////////////////////////////////////////

typedef struct{
	
	KEYTYPE key;
	char nome[50];
	int idade;
}RECORD;

typedef struct{
	
	RECORD vetorRecord[MAX+1]; //a extra position to element sentinel
	int numberElements;
}LIST;

/*////////////////////////////////	FUNCTIONS	//////////////////////////////*/
////////////////////////////////////////////////////////////////////////////////

void cleanBuffer()
{
	
	while((getchar())!= '\n');
}

//list initialization
void startSequentialList(LIST * pointerList)
{
	
	pointerList->numberElements = 0;
}

//show list
void showList(LIST thisList){

	int i;
	if(thisList.numberElements != 0){
		printf("============= IMPRESSÃO DA LISTA ============\n\n");
		for(i = 0; i < thisList.numberElements; i++){
			printf("Chave: %d\n", thisList.vetorRecord[i].key);
			printf("Nome:  %s", thisList.vetorRecord[i].nome);
			printf("Idade: %d\n\n", thisList.vetorRecord[i].idade);
		}
		printf("Finished.\n");
	}else
		printf("Empty list.\n");
}