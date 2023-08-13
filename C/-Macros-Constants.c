// https://www.youtube.com/watch?v=TfJHlez7bek
#include<stdio.h>
#include<stdlib.h>
/*
 Macros : handled by preprocessor, not the compiler
 Not actually a variable, just the data.
 hence memory space and dereferencing variables is saved
 but compiler optimizations have been made.
*/
#define SIZE 10
#define TEXT "What "
#define PRODUCT(X,Y) (X)*(Y)
// Macros are just replaced in the code

// Constants
const int MAX = 10;
// const int TEMP;  // Compiler Error: Uninitialized constant
const char* string = "What ";

int main()
{
    int arr1[SIZE]; //Equivalent to arr1[10]
    // MAX=20; constants are non-modifiable variables
    //TEMP=20;
    int arr2[MAX];  // variable length array of size MAX
    int a=10,b=10;
    printf("%d\n",PRODUCT(a+1,b));

    printf("\nsee ""this\n");   // Literals are concatenated
    printf(TEXT"Magic ""Strings\n"); // Also with macro strings
    // This does not work with const or just any kind of variable

    return 0;
}