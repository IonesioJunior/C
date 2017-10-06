
#include <stdio.h>
#include <stdlib.h>


union num_var {
	int vi;
	short int svi;
	unsigned int uvi;
	float vf;
	double vd;	
	char *word;
};

int main(int argc,char** argv){
	
	union num_var temp;
	printf("Declare union temp var using short integer  ... \n");
	temp.svi = 32000;
	printf("Value of union in short int type : %d\n",temp.svi);
	printf("Value of union in float type : %.2f\n",temp.vf);
	printf("Value of union in int type : %d\n",temp.vi);
	printf("Value of union in double type : %.2f\n",temp.vd);
	printf("Value of union in unsigned int : %u\n" , temp.uvi);
	
	printf("\nDeclare union temp var using float ...\n");
	temp.vf = 15.5;
        printf("Value of union in short int type : %d\n",temp.svi);
        printf("Value of union in float type : %.2f\n",temp.vf);
        printf("Value of union in int type : %d\n",temp.vi);
        printf("Value of union in double type : %.2f\n",temp.vd);
        printf("Value of union in unsigned int : %u\n" , temp.uvi);
	
	
	printf("\nDeclare union temp var using char ...\n");
        temp.word = "This is an union variable";
        printf("Value of union in short int type : %d\n",temp.svi);
        printf("Value of union in float type : %.2f\n",temp.vf);
        printf("Value of union in int type : %d\n",temp.vi);
        printf("Value of union in double type : %.2f\n",temp.vd);
        printf("Value of union in unsigned int : %u\n" , temp.uvi);
	printf("Value of union in char *: %s \n",temp.word);
	return 0;
}
