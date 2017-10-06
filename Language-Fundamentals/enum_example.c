/*
* enum_example.c : This app shows how to work with enums (const int values)
* Ionesio Junior
*/

#include <stdio.h>
#include <stdlib.h>

enum {
	JAN = 1,
	FEB = 2,
	MAR = 3,
	APR = 4,
	MAY = 5,
	JUN = 6,
	JUL = 7,
	AUG = 8,
	SEP = 9,
	OCT = 10,
	NOV = 11,
	DEC = 12
};

int main(int argc,char** argv){

	printf("Show Ordinal value of Jan ... %dº \n" , JAN);
	printf("Show Ordinal value of Feb ... %dº \n" , FEB);
	printf("Show Ordinal value of Mar ... %dº \n" , MAR);
	printf("Show Ordinal value of Apr ... %dº \n" , APR);
	printf("Show Ordinal value of May ... %dº \n" , MAY);
	printf("Show Ordinal value of Jun ... %dº \n" , JUN);
	printf("Show Ordinal value of Jul ... %dº \n" , JUL);
	printf("Show Ordinal value of Aug ... %dº \n" , AUG);
	printf("Show Ordinal value of Sep ... %dº \n" , SEP);
	printf("Show Ordinal value of Oct ... %dº \n" , OCT);
	printf("Show Ordinal value of Nov ... %dº \n" , NOV);
	printf("Show Ordinal value of Dec ... %dº \n" , DEC);
	return 0;
}
