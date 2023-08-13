//https://www.youtube.com/watch?v=A8IkGIqZoLQ

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* getString()
{
    // things declared in double quotes are literals
    // They cannot be modified
    // They are stored in sperate location other than heap or the stack
    // Also can be called const char pointers
    return "test";
}

int main()
{
    // char* s = getString();
    // s[0]='p';   // Not Possible


    
    // char *str = "Hello"; // warning: String constant and char* C/C++ standards

    // /*
    //  str[0]='h'; // Segmentation fault -> String constant and char* C/C++ standards
    //  if you want to use a pointer then do
     
    //  char *str = malloc(50*sizeof(char));
    //  strcpy(str,"Hello");

    //  str[0]='h'; // No error
    // */

    char *temp;// = (char*)malloc(50*sizeof(char));
    strcpy(temp,"Hello");

    printf("Given String: %s \n",temp);

    temp[2] = 'j';

    printf("Changed String String: %s \n",temp);
    
}