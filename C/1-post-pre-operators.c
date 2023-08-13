// Author: Yash Deshpande
// CSE C
// 01fe20bcs168

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i=0;

    printf(" check Initially, i = %d\n",i);
    printf(" print ++i = %d\n",++i);    // Pre-increment, first increment then use
    printf(" print i++ = %d\n",i++);    // Post-increment, first use then increment
	printf(" check i = %d\n",i);
	printf(" print -i = %d\n",-i);	// Temporary negative
	printf(" check i = %d\n",i);	// Actual value is not changed
	printf("Similar for --i and i--\n");

    return 0;
}
