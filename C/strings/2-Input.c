// This code is for reference
// Running it may cause un-intended errors which is due to various selective codes not cbeing commented
// https://www.youtube.com/watch?v=Lksi1HEMZgY
// https://www.youtube.com/watch?v=lXYSW4_ojEk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    // Reading line of string
    char text[100];
    printf("Type a line of text here: ");
    scanf("%s",text);
    printf("You typed %s\n",text);

    // use everything until \n ==> scanf("%[^\n]s",text);
    // but using that will cause the remaining \n to be taken by next scanf
    // so use getchar() to take that remaining \n

    // Using fgets to read line
    fgets(text, 100,stdin);

    for(int j=0;j<strlen(text);j++)
    {
        printf("%d ",text[j]); // Printing ASCII value
    }
    // It can be seen that ascii of \n is present in the end
    // Read Furthur...

    // Using scanf with fgets
    int id;
    char message[256];
    for(int i=0;i<=2;i++)
    {
        printf("Inpupt ID: ");
        scanf("%d",&id);
        
        // 1.
        //scanf("%s",message);
        /* scanf with %s will read untill newline: '\n'
        // so everything untill first space will be considered and
        // remaining portion will be left in std input buffer
        */
        
        // 2.
        //fgets(message,256,stdin);
        /* scanf actually works like: <input>\n---> when you press enter
        => to solve this, use fgetc(stdin) before fgets to read that remaining \n
        
        Also know that fgets also stores \n in the string
        */

        fgetc(stdin);

        printf("Input Message: ");
        fgets(message,256,stdin);
        message[strlen(message)-1]='\0';
        
        printf("(%d) Sent message %s\n",id,message);
    }

    
}