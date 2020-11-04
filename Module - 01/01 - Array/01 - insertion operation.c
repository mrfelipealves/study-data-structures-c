/*	Let LA be a linear array (unordered) with N elements and K is a positive integer such
that K <= N. Following is the algorithm where ITEM is inserted into the K position of LA.

1 - Start
2 - Set J = N
3 - Set N = N + 1
4 - Repeat steps 5 and 6 while j >= K
5 - Set LA[J+1] = LA[J]
6 - Set J = J-1
7 - Set LA[K] = ITEM
8 - Stop	*/

#include <stdio.h>

void main(){
	
	int LA[10] = {1, 3, 5, 7, 8}; //Create and define array
	int item = 10, k = 3, n = 5; //item = item to insert, k = position to insert, n = numbers of elements
	int i = 0, j = n;

	//Show the oritinal array
	printf("The original array elements are:\n");
	for(i = 0; i < n; i++){
		printf("LA[%d] = %d\n", i, LA[i]);
	}

	//move elements and open space for insert item
	n = n+1;
	while(j >= k){
		LA[j+1] = LA[j];
		j = j - 1;
	}

	LA[k] = item;

	//Show array after insertion
	printf("The array elements after insertion:\n");
	for(i = 0; i < n; i++){
		printf("LA[%d] = %d\n", i, LA[i]);
	}
}