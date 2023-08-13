#include<stdio.h>

/*
0x1000 0x6
0x1001 
0x1002 0x1000
0x1003 
0x1004 0x1002
*/

int main()
{
    int a = 6;
    int* pA = &a;

    // & -> used before a variable, gives it address;
    // * -> 1. used to declare a pointer
        //  2. used as a dereferencer

    printf("address of a: %p\n",&a);
    printf("value of pA: %p\n",pA);

    // printf("address of pA: %p\n",&pA);

    printf("dereferenced value of pA: %d\n",*pA);

    int** p2 = &pA;

    printf("dereferenced value of p2: %d\n",**p2);
}
