#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>

static void match(const regex_t *regex , const char * filename){
	int line = 0;
	char tmp[1024];
	FILE *p_file = filename ? fopen( filename , "r") : stdin;
	
	if( !p_file )
	{
		fprintf(stderr , "%s : %s\n"  , filename, strerror(errno));
		return;
	}
		
	while( !feof(p_file) )
	{
		memset(tmp , 0 , sizeof(tmp));
		
		if( fgets(tmp , sizeof(tmp) , p_file) == NULL ) break;
		line++;
		if( regexec( regex , tmp , 0 , 0 , 0) == REG_NOMATCH )
		{
			continue;
		}else{
			fprintf(stdout, "%s(%d) : %s\n" , filename ? filename : stdin , line , tmp);
		}
	}
	
	if(filename) {
		fclose(p_file);
	}
}

int main(int argc,char** argv)
{	
	if( argc <  2 )
	{
		fprintf( stderr , "Ex: %s eregex [file1 file2 ...]\n" , *argv );
		exit( 1 );
	}
	regex_t reg;
	int r;
	int c = argc;
	char err[128] , *regex , **files;
	regex = argv[1];
	files = &argv[2];
	if(   ( r = regcomp(&reg, regex, REG_EXTENDED|REG_NEWLINE|REG_NOSUB) ) )
	{
		memset(err, 0 , sizeof(err));
		regerror(r,&reg,err,sizeof(err));
		regfree(&reg);
		fprintf(stderr,"regex error %s\n" , err);
		return 1;
	}

	if(c)
	{
		while(c--) match(&reg,*files++);
	}else{
		match( &reg , NULL );
	}
	return 0;
}
