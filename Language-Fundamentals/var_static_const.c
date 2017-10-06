/*
* static_const.c : Show how to work static/const flags 
* Ionesio Junior
*/

#include <stdio.h>
#include <stdlib.h>


int count_normal(void){
	int count = 0;
	return count++;
}

int count_static(void)
{
	static int count = 0; // Local variable in static state ( This variable will not deleted after compute this method )
	return count++;
}

int try_change_immutable_value(const int immutable_value)
{
	//immutable_value = 20; //Delete comment bars and try compile ( You can't change value of const variables )
	return immutable_value;
}

int main(int argc,char** argv)
{
	int value = 10;
	try_change_immutable_value(value);
	printf("Immutable Value : %d\n",value);

	printf("Count with static local var : %d | Count with local var : %d\n" ,count_static() , count_normal());
 	printf("Count with static local var : %d | Count with local var : %d\n" ,count_static() , count_normal());
 	printf("Count with static local var : %d | Count with local var : %d\n" ,count_static() , count_normal());
 	printf("Count with static local var : %d | Count with local var : %d\n" ,count_static() , count_normal());
	return 0;
}
