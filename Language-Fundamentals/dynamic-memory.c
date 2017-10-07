/* dynamic-memory : This code show how to allocate/reallocate/free memory dynamically
*  Ionesio Junior
*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc,char** argv){
	const int ARRAY_SIZE = 20;
	//Using malloc
	int *integer_array = (int*) malloc( ARRAY_SIZE * sizeof(int)); //Malloc will allocate ARRAY_SIZE * int type size  Bytes
	//When we use malloc, we will get some garbage data in allocated memory
	printf("Show garbage in allocated memory by malloc ... \n");
	for(int *pointer= integer_array; pointer < (integer_array + ARRAY_SIZE); pointer++){
		printf("%d " , *pointer);
	}
	printf("\n\n");
	

	//Using calloc
        // Calloc will allocate first param(nº of data) * second param(size of data) Bytes
	int *another_integer_array = (int *) calloc(ARRAY_SIZE, sizeof(int) );
	//Calloc clean all allocated memory before return a pointer
	printf("Show value in allocated memory using calloc ...\n");
	for(int *pointer = another_integer_array; pointer < (another_integer_array + ARRAY_SIZE) ; pointer++){
		printf("%d ",*pointer);
	}
	printf("\n\n");


	//If we need to increase/decrease memory allocated, we can reset using realloc
	another_integer_array = (int *) realloc(another_integer_array,ARRAY_SIZE*2 * sizeof(int) );
	
	//To clean some garbage data inside of allocated data, we can use memset
	memset(another_integer_array,0,ARRAY_SIZE * 2 * sizeof(int));
	printf("New allocated space ... \n");
	for(int *pointer = another_integer_array ; pointer < (another_integer_array + (ARRAY_SIZE * 2)) ; pointer++){
		printf("%d ",*pointer);
	}
	printf("\n\n");

	//After all of this process, we  need to free allocated memory
	printf("Free allocated memory ...\n");
	free(integer_array);
	free(another_integer_array);		
	return 0;
}
