/* app.c : Application using generated static lib
* Ionesio Junior
*/
#include <stdio.h>
#include "slib.h"


int main(int argc,char** argv)
{
	slib_put(3);
	slib_put(5);
	slib_put(7);
	slib_put(9);
	
	
	fprintf(stdout, "Valor 1 : %d \n", slib_get() );
	fprintf(stdout, "Valor 2 : %d \n", slib_get() );
	fprintf(stdout, "Valor 3 : %d \n", slib_get() );
	fprintf(stdout, "Valor 4 : %d \n", slib_get() );

	return 0;
}
