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
		printf("Nome: %s\n", thisList.vetorRecord[i].nome);
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
	scanf("%s", pointerList->vetorRecord[i].nome); ////////////////////////////////////////////////////////MELHORAR ESSA LEITURA PARA NÃO GERAR ESTOURO DE BUFFER
	cleanBuffer();
	printf("Type age: ");
	scanf("%d", &(pointerList->vetorRecord[i].idade));
	cleanBuffer();
	pointerList->numberElements++;
}



void main(){
	
	char menuOption;
	KEYTYPE keyToInsert;
	int indexToInsert;
	bool resultFunction;


	LIST thisList;

	do{
		printf("=============================================\n");
		printf("===================   MENU   ================\n");
		printf("=============================================\n\n");
		printf("1 - Start list\n");
		printf("2 - Show list\n");
		printf("3 - Insert an element\n");
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
				printf("Enter a key of record to insert: ");
				scanf("%d", &keyToInsert);
				printf("Enter a index to insert the record: ");
				scanf("%d", &indexToInsert);
				resultFunction = insertElement(&thisList, indexToInsert, keyToInsert);
				if(resultFunction){
					printf("Sucess on insertion.\n");
				}else{
					printf("Failed.\n");
				}

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