#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

//Lista de parametros variaveis
static void debug(const char * fmt, ...){
	va_list ap; // Toodos os outros elementos passados como parametros 
	if( getenv("DEBUG") ){ // verifica se existe uma variavel de ambiente 
		va_start(ap,fmt);
		fprintf(stdout,"debug: ");
		vfprintf(stdout,fmt,ap);
		va_end(ap);
	}
}

int main(int argc, char** argv){
	int x = 1,y =2;
	
	fprintf(stdout, "Testing process X ... \n");
	debug("Computing result of x + y : %d | %s | %s | %d \n" , x+ y, "Ionesio" , "LSD" , 358 );
	
	fprintf(stdout,"Testing process Y ... \n");
	debug("Computing result of x - y: %d | %s | %s \n" , x - y , "Robert" , "BATATA");
	return 0;
}
