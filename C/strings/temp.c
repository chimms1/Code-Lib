#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "/home/anyamanaska/vscodium-c-cpp/System-Software/itoa.h"



int main()
{
    char text[100];
    scanf("%s",text);

    int int_array[7];
    char* temp;
    int i=0;
    int k=0;

    while(text[i]!='\0')
    {
        int_array[i]=text[i];   // Take char into decimal ascii

        // Convert decimal ascii to hex ascii (which is actually just decimal int to hexadecimal int)

        // Convert using itoa(), that hex ascii to string in a temp variable
        temp = itoa(int_array[i],temp,16);

        printf("\n%s",temp);
        // Concatenate temp with main string


        // int_array[k]=text[i];
        i++;
        k++;
    }

    // for(int j=0;j<=5;j++)
    // {
    //     printf("%X ",int_array[j]);
    // }
    
}