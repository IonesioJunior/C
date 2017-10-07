/* memory-mapping.c : How to read and write files using linux mmap method
* Ionesio Junior
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>


void cat_mmap(char *filename)
{
	int fd;
	struct stat st;
	char *p_map = NULL;
	
	/* abre o arquivo */
	fd = open(
		  filename, //Path to file
		  O_RDWR // Read and write (O_RDONLY,O_WRONLY,O_RDWR)
	);
	if(fd == -1) 
	{
		perror("open");
		return;
	}

	/* obtem informações do arquivo */
	if(fstat(fd, &st) == -1) 
	{
		perror("fstat");
		close(fd);
		return;
	}
	

	/* mapeia */
	p_map = mmap(0, //Em caso de 0, o sistema define automaticamente o endereço de mapping
		     st.st_size, // Tamanho do que será mapeado
		     PROT_READ | PROT_WRITE,  // Proteção da memoria durante o mapping ( PROT_EXEC , PROT_READ, PROT_WRITE, PROT_NONE )
		     MAP_SHARED, // Define se o processo pode ser visto por outros processos ( MAP_SHARED ,  MAP_PRIVATE )
		     fd, // File descriptor
		     0
	);

	if(p_map == MAP_FAILED)
	{
		perror("mmap");
		close(fd);
		return;
	}else{
		close(fd);
	}

	/* imprime o conteúdo no terminal */
	fprintf( stdout , "-- %s (%d bytes) --\n" , filename, (int) st.st_size);
	fwrite(p_map, sizeof(char), st.st_size, stdout);


	//Escreve algo no arquivo
	//memcpy(p_map  , "Hello Linux!!!" ,15 );

	/* desaloca a memória */
	munmap(p_map, st.st_size);
}


int main(int argc, char **argv)
{
	char **fn;
	if(argc < 2) {
		fprintf(stderr, "use: %s arquivo[s]...\n", *argv);
		return 1;
	} else{
		fn = ++argv;
	}
	while(--argc)
		cat_mmap(*fn++);
	return 0;
}
