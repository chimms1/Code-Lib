#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

int main()
{
    int a=69;

    printf("d = %d\n",a);
    printf("c = %c\n",a);
    printf("X = %X\n",a);
    printf("#X = %#X\n",a);
    printf("p with &a = %p\n",&a);

    printf("\n-------------------\n");

    char buffer[200];

    // Puts printf content in given memory location
    sprintf(buffer,"test %d",a);
    //snprintf(buffer,200,"test %d",a);
    // copy only maximum size specified
    printf("buffer ==>%s<==\n",buffer);

    //fprintf(FILE pointer,"content",variables);
    // It can also be used to print to standard error
    fprintf_s(stderr,"Here is output of std error\n");

    // s - buffer
    // n - buffer size
    // f - stream (file)
    // _s - safer version (C11)



}