/*
* signal.c: How to get some system signals
* Ionesio Junior
*/

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void my_signal(int sig)
{
	fprintf(stdout, "recebendo sinal %d...\n", sig);
	exit(1);
}

int main(int argc,char** argv)
{
	char temp[128];
	signal(SIGHUP, SIG_IGN); // Interrompe a execução quando o terminal é desligado
	signal(SIGPIPE, SIG_IGN); // Interrompe a execução quando a problemas com descritores do arquivo
	signal(SIGINT, my_signal); // Chama a função definida my_signal quando apertado CRTL+C
	signal(SIGTERM, my_signal); // Chama a função definida my_signal quando o programa é fechado normalmente
	signal(SIGKILL, my_signal); // Chama a função definida my_signal quando o programa é forçado a fechar
	signal(SIGSEGV, my_signal); // Chama a função definida my_signal quando o programa viola o address_space
	while(!feof(stdin)) {
		memset(temp, 0, sizeof(temp));
		if(fgets(temp, sizeof(temp)-1, stdin) == NULL)
			break;
		else
			fprintf(stdout, "texto: %s", temp);
	}
	return 0;

}
