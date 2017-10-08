#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONFIG_FILE "sample-config"
typedef struct {
	char language[10];
	char compiler[10];
	char parser[50];
	char editor[10];
	char osver[50];
	char name[128];
	char home[128];
	char uuid[5];
} config_t;


typedef struct{
	char *optname;
	char *buffer;
	size_t size;
}parser_t;


static char *strfix( char *str )
{
	char *p_text;
	for(p_text = str; p_text != '\0' ; p_text++){
		if( *p_text == '\n' || *p_text =='\r' )
		{
			*p_text = '\0';
			break;
		}
	}
	return str;
}

int main(){
	FILE *p_file;
	char tmp[128] , *value;
	
	config_t conf;
	parser_t opts[] = {
		{"language" 	   , conf.language , sizeof(conf.language) },
		{"compiler" 	   , conf.compiler , sizeof(conf.compiler) },
		{"parser" 	   , conf.parser , sizeof(conf.parser) 	   },
		{"editor" 	   , conf.editor , sizeof(conf.editor) 	   },
		{"os version" 	   , conf.osver , sizeof(conf.osver)       },
		{"programmer name" , conf.name , sizeof(conf.name)	   },
		{"programmer home" , conf.home , sizeof(conf.home) 	   },
		{"programmer uuid" , conf.uuid , sizeof(conf.uuid) 	   }
	};
	
	const int opt_size = sizeof(opts) / sizeof(opts[0]);
	
	if(( p_file = fopen(CONFIG_FILE,"r"))  == NULL )
	{
		perror("open");
		exit(1);
	}
		
	//Read file until the end
	while( !feof(p_file) )
	{
		memset(tmp , 0, sizeof(tmp));
		
		//Get data of one line and store in tmp pointer
		if( fgets( tmp , sizeof(tmp), p_file ) == NULL ) break;
		
		value = tmp;
		//Skip empty lines / comment lines / ...
		if(*value == '\n' || *value == '#' || *value == '\r' || *value == '\t' || *value == '/')
		{
			continue;
		}

		//find equals simbol on current line
		while( *value != '=' && *value != '\0' )
		{
			value++;
		}
		if(*value != '=') continue;
		value++;
		
		//Skip spaces and tabs
		while( (*value == ' ' || *value == '\t') && *value != '\0' )
		{
			value++;
		}
		if(*value == '\0' ) continue;
		
		//Fill parse structure
		for(int i = 0 ; i < opt_size ; i++){
			if( !strncmp(opts[i].optname , tmp , strlen( opts[i].optname ) ) )
			{
				strncpy(opts[i].buffer, strfix(value) , opts[i].size );
			}
		}
	}
	
	//Show config infos 
	for(int i = 0 ; i < opt_size ; i++){
		printf(" [%s] = [%s] \n" , opts[i].optname , opts[i].buffer);
	}

	fclose(p_file);
	return 0;
}
