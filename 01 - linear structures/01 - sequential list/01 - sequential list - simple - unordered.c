/*	A SIMPLE NON ORDERED SEQUENTIAL LIST	*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 //Max range for the array

typedef int KEYTYPE; //used as id for each element

/*//////////////////////////	STRUCTURES DEFINITIONS	/////////////////////*/
///////////////////////////////////////////////////////////////////////////////

typedef struct{
	
	KEYTYPE key;
	char nome[50];
	int idade;
}RECORD;

typedef struct{
	
	RECORD vetorRecord[MAX];
	int numberElements;
}LIST;

/*////////////////////////////////	FUNCTIONS	//////////////////////////////*/
////////////////////////////////////////////////////////////////////////////////

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

//Insertion of element in position 'i'
bool insertElement(LIST * pointerList, int i, KEYTYPE key){
	
	int j;

	if((pointerList->numberElements >= MAX) || (i < 0) || (i > (pointerList->numberElements)))
		return (false); //full list or invalid index
	
	if((pointerList->numberElements > 0) && (i < pointerList->numberElements)) //realoc elements in list to receive new element
		for(j = pointerList->numberElements; j > i; j--){
			pointerList->vetorRecord[j] = pointerList->vetorRecord[j-1];
		}

	pointerList->vetorRecord[i].key = key;
	printf("Type a name for record: ");
	fgets(pointerList->vetorRecord[i].nome, sizeof(char[50]), stdin);
	printf("Type age: ");
	scanf("%d", &(pointerList->vetorRecord[i].idade));
	cleanBuffer();
	pointerList->numberElements++;
}

//Sequential Search in list
int sequentialSearch(LIST thisList, KEYTYPE keyToSearch){

	int index = 0;
	while(index < thisList.numberElements){
		if(thisList.vetorRecord[index].key == keyToSearch)
			return (index); //key found
		else
			index++;
	}
	return (-1); //Key not found
}

//Delete an element
bool deleteElement(LIST * pointerList, KEYTYPE keyToDelete){
	int positionElement, j;
	positionElement = sequentialSearch(*pointerList, keyToDelete);
	if(positionElement == -1){
		return (false); //Element not found
	}else{
		for(j = positionElement; j < pointerList->numberElements-1; j++)
			pointerList->vetorRecord[j] = pointerList->vetorRecord[j+1];
		pointerList->numberElements--;
		return (true); //Element deleted
	}
}

//List length
int listLength(LIST thisList){
	return thisList.numberElements;
}

//clear list
void clearSequentialList(LIST * pointerList)
{
	
	pointerList->numberElements = 0;
}


void main(){
	
	char menuOption;
	
	KEYTYPE keyToInsert;
	KEYTYPE keyToSearch;
	KEYTYPE keyToDelete;
	int indexToInsert;
	int resultIntFunction;
	bool resultBoolFunction;
	LIST thisList;

	do{
		printf("\n=============================================\n");
		printf("===================   MENU   ================\n");
		printf("=============================================\n\n");
		printf("1 - Start list\n");
		printf("2 - Show list\n");
		printf("3 - Insert an element\n");
		printf("4 - Search a key\n");
		printf("5 - Delete an element\n");
		printf("6 - List length\n");
		printf("7 - Clear list\n");
		printf("choose an option: ");

		scanf("%c", &menuOption);
		printf("\n\n");
		cleanBuffer();

		switch(menuOption){
			case '1':{

				startSequentialList(&thisList);
				printf("Initialization completed.\n");
				break;
			}
			case '2':{

				showList(thisList);
				break;
			}
			case '3':{

				printf("Enter a key of record to insert: ");
				scanf("%d", &keyToInsert);
				cleanBuffer();
				printf("Enter a index to insert the record: ");
				scanf("%d", &indexToInsert);
				cleanBuffer();
				resultBoolFunction = insertElement(&thisList, indexToInsert, keyToInsert);
				if(resultBoolFunction){
					printf("Sucess on insertion.\n");
				}else{
					printf("Failed.\n");
				}
				break;
			}
			case '4':{

				printf("Enter a key to search: ");
				scanf("%d", &keyToSearch);
				cleanBuffer();
				resultIntFunction = sequentialSearch(thisList, keyToSearch);
				if(resultIntFunction > -1)
				{
					printf("Record found on: %d index\n", resultIntFunction);
					printf("Key: %d\n", thisList.vetorRecord[resultIntFunction].key);
					printf("Nome: %s", thisList.vetorRecord[resultIntFunction].nome);
					printf("Idade: %d\n", thisList.vetorRecord[resultIntFunction].idade);
				}else
				{
					printf("Record not found.\n");
				}
				break;
			}
			case '5':{

				printf("Enter an element to delete: ");
				scanf("%d", &keyToDelete);
				cleanBuffer();
				resultBoolFunction = deleteElement(&thisList, keyToDelete);

				if(resultBoolFunction)
					printf("element successfully deleted.\n");
				else
					printf("element not found.\n");	
				break;
			}
			case '6':{
				
				printf("List length: %d\n", listLength(thisList));
				break;
			}
			case '7':{

				clearSequentialList(&thisList);
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
		printf("Type a key to continue...");
		cleanBuffer();
	}while(menuOption != '0');
}