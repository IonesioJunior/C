/*
* slib.c : static lib code implementation
* Ionesio Junior
*/
#include <stdio.h>
#include <string.h>


static int slib_stack[4];
static int slib_stack_pos = 0;
const int slib_stack_size = sizeof(slib_stack) / sizeof(slib_stack[0]);


void slib_init(void)
{
	memset(slib_stack,0,sizeof(slib_stack) );
}

int slib_put(int input)
{
	if(slib_stack_pos == slib_stack_size ) return -1;
	else
		slib_stack[slib_stack_pos++] = input;
	if(slib_stack_pos == slib_stack_size)
	{
		slib_stack_pos--;
	}
	return input;
}

int slib_get()
{
	if(slib_stack_pos < 0) return -1;
	return slib_stack[slib_stack_pos--];
}


void slib_quit()
{
	slib_init();
}
