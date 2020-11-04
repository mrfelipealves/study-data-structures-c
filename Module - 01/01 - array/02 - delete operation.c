/*	Consider LA is a linear array with N elements and K is a positive 
integer such tha K <= N. Following the algorithm to delente an element 
available at the K position of LA.	
1 - Start 
2 - Set J = K
3 - Repeat steps 4 and 5 while J < N
4 - Set LA[J] = LA[J + 1]
5 - Set J = J + 1
6 - Set N = N - 1
7 - Stop	
Following tis the implementation of the above algorithm	*/

#include <stdio.h>

void main(){
	int LA[] = {1, 3, 5, 7, 8}; //Create and define an array
	int k = 3, n = 5; //K = position to delete, n = numbers of elements
	int i, j;

	//Show the original array
	printf("The original array elements are:\n");
	for(i = 0; i < n; i++){
		printf("LA[%d] = %d\n", i, LA[i]);
	}

	j = k;

	while(j < n){
		LA[j-1] = LA[j]; //Move elements and ovewrite the k element
		j = j + 1;
	}

	n = n - 1; //Update array length

	//Show the new array
	printf("The array elements after deletion:\n");
	for(i = 0; i < n; i++){
		printf("LA[%d] = %d\n", i, LA[i]);
	}
}

