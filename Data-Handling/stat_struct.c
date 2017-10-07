#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>



void filetype(char * filepath){
	
	int size;
	struct stat st;
	char tmp[1024];
	
	if(lstat(filepath,&st) == -1)
	{
		perror("stat");
		return;
	}
	
	size = (int) st.st_size;
	memset(tmp,0,sizeof(tmp));
	
	if(S_ISREG(st.st_mode))
		fprintf(stdout, "%s: arquivo comum, %d bytes\n", filepath, size);
	else if(S_ISDIR(st.st_mode))
		fprintf(stdout, "%s: diretório, %d bytes\n", filepath, size);
	else if(S_ISCHR(st.st_mode))
		fprintf(stdout, "%s: character device\n", filepath);
	else if(S_ISBLK(st.st_mode))
		fprintf(stdout, "%s: block device\n", filepath);
	else if(S_ISFIFO(st.st_mode))
		fprintf(stdout, "%s: fifo\n", filepath);
	else if(S_ISLNK(st.st_mode)) {
		readlink(filepath, tmp, sizeof(tmp));
		fprintf(stdout, "%s: link para %s\n", filepath, tmp);
	} else if(S_ISSOCK(st.st_mode))
		fprintf(stdout, "%s: unix domain socket\n", filepath);
}

int main(int argc,char** argv){
	char **filepath = argv;
	if(argc < 2 ){
		fprintf(stderr,"Ex : %s <filepath>  \n",*argv);
		exit(1);
	}
	filepath++;
	while(--argc){
		filetype(*filepath++);
	}
	return 0;
}
