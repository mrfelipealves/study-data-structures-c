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

//Sequential search with element sentinel
int sequantialSearchWithSentinel(LIST thisList, KEYTYPE keyToSearch){
	int index = 0;
	
	thisList.vetorRecord[thisList.numberElements].key = keyToSearch;

	while(thisList.vetorRecord[index].key < keyToSearch)
		index++;

	if((index > (thisList.numberElements-1))||(thisList.vetorRecord[index].key != keyToSearch))
		return (-1);

	else
		return index;
}

//Delete an element
bool deleteElement(LIST * pointerList, KEYTYPE keyToDelete){
	int positionElement, j;
	
	positionElement = sequantialSearchWithSentinel(*pointerList, keyToDelete);

	if(positionElement == -1)
		return (false); //Element not found
	else{
		for(j = positionElement; j < pointerList->numberElements-1; j++)
			pointerList->vetorRecord[j] = pointerList->vetorRecord[j+1];
		pointerList->numberElements--;
		return (true); //Element deleted
	}
}