/*
* getop.c : Simulates getopt bash function
* Ionesio Junior
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>



int main(int argc,char** argv)
{
	int c , optind = 0;
	const char *opts = "e:1:dchu";
	const struct option optl[] = {
		{"edit",     1, 0, 'e'},
		{"list",     1, 0, 'l'},
		{"date",     0, 0, 'd'},
		{"cpu-info", 0, 0, 'c'},
		{"help",     0, 0, 'h'},
		{"uname",    0, 0, 'u'},
		{0,0,0,0},
	};	

	void help(){
		fprintf(stderr , 
				"getopt-long v0.1\n"
				"use: %s [OPÇÃO]\n\n"
				"OPÇÕES:\n"
				"-d, --date 		Imprime data e hora do sistema\n"
				"-c, --cpu-info 		Imprime caracteristicas do cpu\n"
				"-h, --help		Imprime esta tela\n"
				"-u, --uname 		Imprime a versao do sistema operacional\n"
				"-e, --edit-ARQ		Edita o Arquivo\n"
				"-l, --list-ARQ		Lista o Arquivo\n" ,*argv);
		exit(1);
	}
	if(argc == 1)
	{
		help();
	}
	while( (c = getopt_long(argc,argv,opts,optl,&optind)) != -1)
	{
		switch(c)
		{
			case 'e':
				fprintf(stdout , "Edita o arquivo %s\n" , optarg);
				break;
			case 'l':
				fprintf(stdout , "Lista o arquivo %s\n" , optarg);
				break;
			case 'd':
				fprintf(stdout ,  "Imprime a data \n");
				break;
			case 'c':
				fprintf(stdout , "Imprime dados do CPU \n");
				break;
			case 'u':
				fprintf(stdout , "Imprime dados do sistema operacional \n");
				break;
			default:
				help();
		}
	}
	return 0;
}
