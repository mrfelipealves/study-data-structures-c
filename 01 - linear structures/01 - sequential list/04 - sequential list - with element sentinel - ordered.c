/*	A ORDERED SEQUENTIAL LIST	WITH SENTINEL ELEMENT*/

/*Funções que serão implementadas
- Inicializar estrutura
- Retornar quantidade de elementos válidos
- Exibir elementos da estrutura
- Buscar por um elemento na estrutura
- Inserir elementos na estrutura
- Excluir elementos na estrutura
- Reiniciar estrutura
*/

#define MAX 5 //Max range for the array

typedef int KEYTYPE; //Used as id for each element

/*///////////////////////	STRUCTURES DEFINITIONS	/////////////////////////*/
///////////////////////////////////////////////////////////////////////////////

typedef struct{

	KEYTYPE key;
	char nome[50];
	int idade;
}TYPERECORD;

typedef struct{

	RECORD vetorRecord[MAX+1]; //E extra position to element sentinel
	int numberElements;
}TYPELIST;

/*////////////////////////////////	FUNCTIONS	//////////////////////////////*/
////////////////////////////////////////////////////////////////////////////////

void cleanBuffer(){

	while((getchar())!= '\n');
}

//list initialization
void startSequentialList(TYPELIST * pointerList){

	pointerList->numberElements = 0;
}

//return number of list elements
int listLength(TYPELIST thisList){

	return thisList.numberElements;
}

//Show list
void showList(TYPELIST thisList){

	int index;
	if(thisList.numberElements != 0){
		printf("============= IMPRESSÃO DA LISTA ============\n\n");
		for(index = 0; index < thisList.numberElements; index++){
			printf("Chave: %d\n", thisList.vetorRecord[index].key);
			printf("Nome: %s", thisList.vetorRecord[index].nome);
			printf("Idade: %d\n\n", thisList.vetorRecord[index].idade);	
		}
		printf("finished.\n");
	}else
	{
		printf("Empty list.\n");
	}
}

//Sequential search in ordered list with element sentinel
int sequentialSearchInOrderedList(TYPELIST thisList, KEYTYPE keyToSearch){

	int index = 0;

	thisList.vetorRecord[thisList.numberElements].key = keyToSearch;

	while(thisList.vetorRecord[index].key < keyToSearch)
		index++;

	if((thisList.vetorRecord[index].key == keyToSearch)&&(index != thisList.numberElements))
		return (index);

	return (-1);
}

//Insertion of element in ordered list with sentinel element
bool insertElementInOrderedList(TYPELIST * pointerList, KEYTYPE keyToInsert){

	int index 0;
	int indexAux;

	if(pointerList->numberElements >= MAX)
		return (false);

	pointerList->vetorRecord[pointerList->numberElements].key = keyToInsert;

	while(thisList->vetorRecord[index].key < keyToInsert)
		index++;

	if((thisList->vetorRecord[index].key == keyToInsert)&&(index < pointerList->numberElements))
		return (false) //Element already exists

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

	int positionElement, j;

	positionElement = sequentialSearchInOrderedList(*pointerList, keyToDelete);

	if(positionElement == -1)
		return (false); //Element not found
	else{
		for(j = positionElement; j < pointerList->numberElements-1; j++)
			pointerList->vetorRecord[j] = pointerList->vetorRecord[j+1];
		pointerList->numberElements--;
		return (true);
	}
}

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

	bool resultBoolFunction;

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
				printf("Initialization completed.\n");
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

				resultIntFunction = sequentialSearchInOrderedList(thisList, keyToSearch);

				if(resultIntFunction > -1){
					printf("Record found on %d index\n", resultIntFunction);
					printf("Key: %d", thisList.vetorRecord[resultIntFunction].key);
					printf("Nome: %s", thisList.vetorRecord[resultIntFunction].nome);
					printf("Idade: %d anos", thisList.vetorRecord[resultIntFunction].idade);
				}else{
					printf("Record not found.\n");
				}
				break;
			}
			case '5':{

				printf("Enter a key of record to insert: ");
				scanf("%d", &keyToInsert);
				cleanBuffer();

				resultBoolFunction = insertElementInOrderedList(&thisList, keyToInsert);

				if(resultBoolFunction)
					printf("Sucess on insertion.\n");
				else
					printf("Failed.\n");

				break;
			}
			case '6':{

				printf("Enter and element to delete: ");
				scanf("%d", );
			}
			default:{
				printf("Invalid option.\n");
			}
		}
		printf("Type a key to continue...");
		cleanBuffer();
	}while(menuOption != '0');

}