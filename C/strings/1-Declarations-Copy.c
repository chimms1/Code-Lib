#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char text1[50]; // string of size 50 bytes = 50 characters including '\0' at end as a character
    char text2[] = "Temp";
    char text3[] = "Hello this world"; 
    
    // "Hello this world" is of size 17 and not 16 ('\0' added automatically)
    /*
    Declaring like this will cause string to not terminate as there is no place for '\0'
        char text3[16] = "Hello this world";

    then text3 will become "Hello this worldTemp\0"
    
    Reason: Memory Allocation Stack

    1. text1 is declared in memory:
    ->50 bytes

    2. text2 is declared in memory:

    T
    e
    m
    p
    \0
    50 bytes

    3. text3 is declared in memory:

    H
    e
    .
    .
    l
    d
    ~~\0    // this place is terminator for the above string, else it goes untill \0
    T
    e
    m
    p
    \0
    50 bytes

    */
	printf("Initially\n");
    printf(" Text1: %s\n Text2: %s\n Text3: %s\n",text1,text2,text3);
	/*
	 strcpy Copies source to destination with null terminator
	 except: if dest is smaller than src, then sizeof(dest) is cut pasted from src, but copy is successful
	 ex: if text1 = 10 bytes
	 then text1 will have "Hello this world"
	 text3 will have " world", "Hello this" = 10 bytes
	*/
	      //dest,src
    //strcpy(text1,text3);

	// Copy only n characters from src to dest with or without \0
	// compiler warns if overflow and result will be same as above
	strncpy(text1,text3,17);

	/*
	 Note: strlen return length without counting \0, it returns "number of characters in the string 1..n"
	 strncpy(text1,tex3,strlen(text3));	// len = 16, does not include \0
	 text1[16 (17th)] = '\0';
	 
	*/
	printf("\n After Copy\n");
	printf(" Text1: %s\n Text2: %s\n Text3: %s\n",text1,text2,text3);


    char *str = "Hello"; // warning: String constant and char* C/C++ standards

    /*
     str[0]='h'; // Segmentation fault -> String constant and char* C/C++ standards
     if you want to use a pointer then do
     
     char *str = malloc(50*sizeof(char));
     strcpy(str,"Hello");

     str[0]='h'; // No error
    */

	return 0;
}