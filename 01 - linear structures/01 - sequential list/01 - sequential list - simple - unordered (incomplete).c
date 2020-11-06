/*	A SIMPLE NON ORDERED SEQUENTIAL LIST	*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 //Max range for the array

typedef int KEYTYPE; //used as id for each element

/*/////////	STRUCTURES DEFINITIONS	/////////*/
///////////////////////////////////////////////

typedef struct{
	KEYTYPE key;
	char nome[50];
	int idade;
}RECORD;

typedef struct{
	RECORD vetorRecord[MAX];
	int numberElements;
}LIST;

/*//////////	FUNCTIONS	//////////*/
////////////////////////////////////////

//function to clear buffer after read a value from keyboard
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
	printf("============== IMPRESSÃO DA LISTA ==============\n\n");
	for(i = 0; i < thisList.numberElements; i++){
		printf("Chave: %04d\n", thisList.vetorRecord[i].key);
		printf("Nome: %s", thisList.vetorRecord[i].nome);
		printf("Idade: %02d\n\n", thisList.vetorRecord[i].idade);
	}
}

//Insertion of element in position 'i'
bool insertElement(LIST * pointerList, int i, KEYTYPE key){
	
	int j;

	if((pointerList->numberElements >= MAX) || (i < 0) || (i > (pointerList->numberElements)))
		return (false); //full list or invalid index
	
	if((pointerList->numberElements > 0) && (i < pointerList->numberElements))
		for(j = pointerList->numberElements; j >= (i+1); j--){
			pointerList->vetorRecord[j] = pointerList->vetorRecord[j-1];
		}

	pointerList->vetorRecord[i].key = key;
	printf("record key: %d\n", pointerList->vetorRecord[i].key);
	printf("Type a name for record: ");
	fgets (pointerList->vetorRecord[i].nome, 50, stdin);
	printf("Type age: ");
	scanf("%d", &(pointerList->vetorRecord[i].idade));
}



void main(){
	
	char menuOption;
	KEYTYPE keyToInsert;

	LIST thisList;

	do{
		printf("=============================================\n");
		printf("===================   MENU   ================\n");
		printf("=============================================\n\n");
		printf("1 - Start list\n");
		printf("2 - Show list\n");
		//Destruir lista
		//Busca sequencial em lista
		//Exclusão
		printf("choose an option: ");

		scanf("%c", &menuOption);
		cleanBuffer();
		printf("\n\n\n");

		switch(menuOption){
			case '1':{
				startSequentialList(&thisList);
				printf("Initialization completed.\n");
				break;
			}
			case '2':{
				showList(thisList);
				printf("Finished.\n");
				break;
			}
			case '3':{
				break;
			}
			case '0':{
				printf("Good bye.\n");
				break;
			}
			default:{
				printf("Invalid option.\n");
			}
		}

		printf("\n\n\n");
	}while(menuOption != '0');
}