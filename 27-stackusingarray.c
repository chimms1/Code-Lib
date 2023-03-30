#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

#define MAXSIZE 10

typedef struct stack
{
    int top;
    int S[MAXSIZE];
}*STACK;


int isEmpty(STACK st)
{
    if(st->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(STACK st)
{
    if(st->top==MAXSIZE){
        return 1;
    }
    else{
        return 0;
    }
}
int Push(STACK St,int item){

    if(isFull(St)){
        printf("     >>stack is full\n");
        return (0);
    }
    else{
        St->S[++St->top]=item;
        return (1);
    }
}
int Pop(STACK St){
    int item;
    if(isEmpty(St)){
        printf("     >>stack is empty\n");
        return (0);
    }
    else{
        St->S[--St->top];
        return (1);
    }
}
void Display(STACK St){
    if(!isEmpty(St)){
        printf("\n  => Elements of the stack are: \n");
        int temp=St->top;
        while(temp>=0){
            printf("=> %d\n",St->S[temp]);
            temp--;
        }
    }
    else{
        printf("\n  => The stack is Empty\n");
    }
}
int main()
{
    int data,num,choice;
    STACK mainstack;
    mainstack->top=-1;
    while(1){
        printf("\n === Menu === \n  > Push - 1\n  > Pop - 2\n  > Display - 3\n  > Exit - 4\n");
        printf("\n  >>> Enter the choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("\nEnter the element to be pushed: ");
            scanf("%d",&num);
            data=Push(mainstack,data);
            if(data==1)
                printf("    ---Push Successful---    \n");
            break;
        case 2:
            data=Pop(mainstack);
            if(data==1)
                printf("    ---Pop Successful---    \n");
            break;

        case 3:
            Display(mainstack);
            break;
        case 4:
            exit(0);
            break;
        }
    }

    return 0;
}

