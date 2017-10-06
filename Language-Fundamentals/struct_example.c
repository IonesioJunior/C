/*
* struct_example : Show how to define/use some struct
* Ionesio Junior
*/

#include <stdio.h>
#include <stdlib.h>

struct people{
	int age;
	char *name;
	int id;
};

int main(int argc,char** argv){
	struct people p1;
	
	// First way to set values of some struct object
	p1.age = 20;
	p1.name = "Peter";
	p1.id = 987;
	
	//Second wat to set values of some struct object
	struct people p2 = {
		17, 	 	// Age
		"Robert", 	//Name
		555		// ID
	};
	
	
	//How to get data of some Struct
	printf("First Person Infos: \n");
	printf("Name : %s\n",p1.name);
	printf("Age : %d\n",p1.age);
	printf("Id : %d\n",p1.id);

	printf("\n\n");	
	printf("Second Person Infos: \n");
        printf("Name : %s\n",p2.name);
        printf("Age : %d\n",p2.age);
        printf("Id : %d\n",p2.id);  	

	return 0;
}
