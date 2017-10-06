/*
* ptrfunc.c: Example of pointer to methods
*
* Ionesio Junior
*/

#include <stdio.h>
#include <stdlib.h>

int add_two_integers(int x, int y)
{
	return x + y;
}

int main(int argc,char** argv)
{
	int (*add_pointer)( int , int );
	add_pointer = add_two_integers;
	fprintf(stdout, "Result: %d\n", add_pointer(10, 29));
	return 0;
}
