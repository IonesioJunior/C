/* xshell.c : Simple shell simulation for exit / cd methods
*  Ionesio Junior
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


//struct of commands and your methods
typedef struct{
	char *cmd;
	void (*func) (char **lines);
} cmdptr;

//Clean text of some chars
static char *fixstr(char *str)
{
	char *ptr;
	for(ptr = str ; *ptr != '\0' ; ptr++){
		if( *ptr == '\n' || *ptr == '\r' )
		{
			*ptr = '\0';
			break;
		}
	}
	return ptr;
}
//Split a text when found char(' ')
static void split(char *str , char **lines)
{
	while(*str != '\0')
	{
		while( *str == ' ' && *str != '\0' ) *str++ = '\0';
		*lines++ = str;
		while( *str != ' ' && *str != '\0' ) str++;
	}
	*lines = NULL;
}

//Our method to implement cd bash function
void builtin_cd(char **lines)
{
	if( chdir(*lines) == -1)
	{
		perror("chdir");
	}
}

//Our method to implement exit bash function
void builtin_exit(char **lines)
{
	fprintf(stdout, "oops\n");
	exit(0);
}

//List of our commands
static cmdptr cmdlist[] = {
	{ "cd" , builtin_cd },
	{ "exit" , builtin_exit}
};

int main(int argc,char** argv)
{
	cmdptr *ptr;
	int i , is_builtin;
	char tmp[4096], *lines[sizeof(tmp) / 2];
	const int cmdlen = sizeof(cmdlist) / sizeof(cmdlist[0]);
	
	// Ignore CRTL + C
	signal(SIGINT,SIG_IGN);
	
	while(1)
	{
		fprintf(stdout, "$ ");
		fflush(stdout);
		
		memset(tmp , 0 , sizeof(tmp) );
		//Get text from input
		if( fgets( tmp , sizeof(tmp) , stdin)  == NULL ) break;
		
		//Ignore this caracters
		if( *tmp == '\0' || *tmp == '\r' || *tmp == '#' || *tmp == ' ') continue;
		
		fixstr(tmp);
		split(tmp , lines);
		
		//Verify if command is for our command or another system command
		is_builtin = 0;
		for(int i = 0 ; i < cmdlen; i++){
			if( !strcmp(*lines , cmdlist[i].cmd) )
			{
				//Exec our commands
				cmdlist[i].func( &lines[1] );
				is_builtin = 1;
			}
		}
		if(is_builtin) continue;
	
		//Exec another system command
		switch( fork() ){
			case -1 :
				perror("fork");
				exit(1);
			case 0 :
				execvp(*lines,lines);
				perror("exec");
				_exit(1);
			default:
				wait(NULL);
		}
	}		
	return 0;
}
