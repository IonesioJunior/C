/*
* var_sig_unsig.c : Show difference of values using signed/unsigned variables
* Ionesio Junior
*/
#include <stdio.h>
#include <stdlib.h>


int main(int argc,char** argv){
	printf("====== Signed/Unsigned char dynamic ====== \n\n");
	/* One byte have 2 ^8 possibilities to combine 0 and ones (256 values),
	*  using a normal char value, we can represent numbers in range of (-128  ,  127 ),
	*  if we set some value bigger then 127 or lower then -128, we will get an overflow/underflow
	*/
	printf("Normal char limits : \n");
	char max_char_value = 127;
	printf("Max char value : %d\n", max_char_value);
	char overflow_char_value = 128;
	printf("Overflow char value : %d\n" , overflow_char_value);

	/* Using an unsigned char we still have 256 values, but now we can represent numbers in range of (0,255)
	*  Now, we can't represent negative numbers.
	*/
	printf("\nUnsigned char limits : \n");
	unsigned char max_uchar_value = 255;
	printf("Max unsigned char value : %d\n" , max_uchar_value);
	unsigned char negative_char_value = -128;
	printf("Trying to set negative value on unsigned char : %d\n" , negative_char_value);

	
	
	printf("\n\n====== Signed/Unsigned short int dynamic ====== \n\n");
	/* The size of some short integer is 2 Bytes ( 2 ^16 possibilities ),
	*  using a normal int value, we can represent numbers in range of ( −32,767, +32,767 ) 
	* if we set some value bigger then 32,767 or lower then -32,768, we will get an overflow/underflow
	*/
	printf("Short int limits : \n");
	short int max_s_int_value = 32767;
	printf("Max short int value : %d\n",max_s_int_value);
	short int underflow_s_int_value = -32769;
	printf("Underflow short int value : %d \n" , underflow_s_int_value);
	
	/* Using an unsigned int we still have 2 ^ 16 values ,  but now we can represent numbers in range of (0,65535)
	* Now, we can't represent negative numbers
	*/
        printf("\nShort unsigned int limits : \n");
        unsigned short int max_s_uint_value = 65535;
        printf("Max unsigned short int value : %d\n",max_s_uint_value);
        unsigned short int overflow_s_uint_value = 65536;
        printf("Overflow unsgined int value : %d \n" , overflow_s_uint_value);




        printf("\n\n====== Signed/Unsigned int dynamic ====== \n\n");
        /* The size of some normal integer is 4 Bytes ( 2 ^32 possibilities ),
        *  using a normal int value, we can represent numbers in range of ( −2,147,483,648, +2,147,483,647 ) 
        * if we set some value bigger then +2,147,483,647 or lower then −2,147,483,648, +2,147,483,647, we will get 
	*  an overflow/underflow.
        */
        printf("Normal int limits : \n");
        int max_int_value = 2147483647;
        printf("Max normal int value : %d\n",max_int_value);
        int underflow_int_value = -2147483649;
        printf("Underflow normal int value : %d \n" , underflow_int_value);

        /* Using an unsigned int we still have 2 ^ 16 values ,  but now we can represent numbers 
	*  in range of (0,4,294,967,295).Now, we can't represent negative numbers
        */
        printf("\nNormal unsigned int limits : \n");
	unsigned int max_uint_value = 4294967295;
        printf("Max unsigned int value : %lu \n",max_uint_value);
        unsigned int overflow_uint_value = 4294967296;
        printf("Overflow unsgined int value : %d \n" , overflow_uint_value);
	return 0;
}
