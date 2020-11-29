/*	A SIMPLE ORDERED SEQUENTIAL LIST */

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
}TYPERECORD;

typedef struct{
	TYPERECORD vetorRecord[MAX];
	int numberElements;
}TYPELIST;

/*////////////////////////////////	FUNCTIONS	//////////////////////////////*/
////////////////////////////////////////////////////////////////////////////////


//function to clear buffer after read a value from keyboard
void cleanBuffer(){
	
	while((getchar()) != '\n');
}

//list initialization
void startSequentialList(TYPELIST * pointerList){
	
	pointerList->numberElements = 0;
}

//return number of list elements
int listLength(TYPELIST thisList){

	return thisList.numberElements;
}

//show list
void showList(TYPELIST thisList){

	int index;
	if(thisList.numberElements != 0){
		printf("============= IMPRESSÃO DA LISTA ============\n\n");
		for(index = 0; index < thisList.numberElements; index++){
			printf("Chave: %d\n", thisList.vetorRecord[index].key);
			printf("Nome: %s", thisList.vetorRecord[index].nome);
			printf("Idade: %d\n\n", thisList.vetorRecord[index].idade);
		}
		printf("Finished.\n");
	}else
		printf("Empty list.\n");
}

//Simple sequential search in ordered list
int sequentialSearch(TYPELIST thisList, KEYTYPE keyToSearch){

	int index = 0;
	while((index < thisList.numberElements)&&(keyToSearch >= thisList.vetorRecord[index].key)){
		if(thisList.vetorRecord[index].key == keyToSearch)
			return (index); //key found
		else
			index++;
	}
	return (-1); //key not found
}

//Binary search in sequential ordered list
int binarySearch(TYPELIST thisList, KEYTYPE keyToSearch){
	int inferior, superior, meio;

	inferior = 0;
	superior = thisList.numberElements-1;

	while(inferior <= superior){
		meio = ((inferior+superior)/2);

		if(thisList.vetorRecord[meio].key == keyToSearch)
			return meio;
		else
			if(thisList.vetorRecord[meio].key < keyToSearch)
				inferior = meio+1;
			else
				superior = meio-1;
	}

	return -1;

}

//Insertion of element in ordered list
bool insertElementInOrderedList(TYPELIST * pointerList, KEYTYPE keyToInsert){

	int index = 0;
	int indexAux;

	if(pointerList->numberElements >= MAX)
		return (false); //list full

	while((index < pointerList->numberElements)&&(pointerList->vetorRecord[index].key < keyToInsert))
		index++;
	

	if((pointerList->vetorRecord[index].key == keyToInsert)&&(index < pointerList->numberElements))
		return (false); //key already exists

	for(indexAux = pointerList->numberElements; indexAux > index; indexAux--)
		pointerList->vetorRecord[indexAux] = pointerList->vetorRecord[indexAux-1];

	pointerList->vetorRecord[index].key = keyToInsert;
	printf("Type a name for record: ");
	fgets(pointerList->vetorRecord[index].nome, sizeof(char[50]), stdin);
	printf("Type age: ");
	scanf("%d", &(pointerList->vetorRecord[index].idade));
	cleanBuffer();
	pointerList->numberElements++;

	return (true);

}

//Delete an element
bool deleteElement(TYPELIST * pointerList, KEYTYPE keyToDelete){
	int positionElement, indexAux;

	positionElement = sequentialSearch(*pointerList, keyToDelete);

	if(positionElement == -1)
		return (false); //Element not found
	else{
		for(indexAux = positionElement; indexAux < pointerList->numberElements-1; indexAux++)
			pointerList->vetorRecord[indexAux] = pointerList->vetorRecord[indexAux+1];

	pointerList->numberElements--;
	return (true);
	}
}

//clear list
void clearSequentialList(TYPELIST * pointerList){

	pointerList->numberElements = 0;
}

void main(){

	char menuOption;

	TYPELIST thisList;

	KEYTYPE keyToSearch;
	KEYTYPE keyToInsert;
	KEYTYPE keyToDelete;

	int resultIntFunction;
	int indexToInsert;

	int indexAux;

	bool resultBoolunction;

	do{

		printf("\n=============================================\n");
		printf("===================   MENU   ================\n");
		printf("=============================================\n\n");
		printf("1 - Start list\n");
		printf("2 - List length\n");
		printf("3 - Show list\n");
		printf("4 - Search a key\n");
		printf("5 - Insert an element\n");
		printf("6 - Delete an element\n");
		printf("7 - Clear list\n");
		printf("choose an option: ");

		scanf("%c", &menuOption);
		printf("\n\n");
		cleanBuffer();

		switch(menuOption){

			case '1':{

				startSequentialList(&thisList);
				printf("initialization completed.\n");
				break;
			}
			case '2':{

				printf("List length: %d\n", listLength(thisList));
				break;
			}
			case '3':{

				showList(thisList);
				break;
			}
			case '4':{

				printf("Enter a key to search: ");
				scanf("%d", &keyToSearch);
				cleanBuffer();

				resultIntFunction = binarySearch(thisList, keyToSearch);
				if(resultIntFunction > -1){
					printf("Record found on %d index\n", resultIntFunction);
					printf("Key: %d\n", thisList.vetorRecord[resultIntFunction].key);
					printf("Nome: %s", thisList.vetorRecord[resultIntFunction].nome);
					printf("Idade: %d anos \n", thisList.vetorRecord[resultIntFunction].idade);
				}else
					printf("Record not found.\n");
				break;
			}
			case '5':{

				printf("Enter a key of record to insert: ");
				scanf("%d", &keyToInsert);
				cleanBuffer();

				resultBoolunction = insertElementInOrderedList(&thisList, keyToInsert);

				if(resultBoolunction)
					printf("Sucess on insertion.\n");
				else
					printf("Failed.\n");

				break;	
			}
			case '6':{

				printf("Enter and element to delete: ");
				scanf("%d", &keyToDelete);
				cleanBuffer();

				resultBoolunction = deleteElement(&thisList, keyToDelete);

				if(resultBoolunction)
					printf("Element sucessfully deleted.\n");
				else
					printf("Element not found.\n");
				break;
			}
			case '7':{

				clearSequentialList(&thisList);
				break;
			}
			case '9':{
				printf("Number of elements: %d\n\n", thisList.numberElements);
				printf("List: \n\n");
				for(indexAux = 0; indexAux < MAX; indexAux++){
					printf("Key: %d\n", thisList.vetorRecord[indexAux].key);
					printf("Name: %s\n", thisList.vetorRecord[indexAux].nome);
					printf("Age: %d\n\n", thisList.vetorRecord[indexAux].idade);
				}

				break;
			}
			case '0':{


				printf("Good bye.\n");
				break;
			}
			default:
				printf("Invalid option.\n");
		}

	}while(menuOption != '0');


}
