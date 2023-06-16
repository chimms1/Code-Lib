/*
Name: Yash Deshpande
Sec: C
Roll: 345
USN: 01fe20bcs168
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef struct queue
{
    int A[MAXSIZE];
    int front,rear;
}QUEUE;

int isEmpty(QUEUE *Q);
int isFull(QUEUE *Q);
int Enqueue(QUEUE *Q,int k);
int Dequeue(QUEUE *Q);
void QueueDisplay(QUEUE);

int main()
{
    QUEUE P;
    P.front=0;
    P.rear=-1;

    int choice;
    int enq,deq,n,k;

while(1){
        printf("\n\n     ---Menu---     \n  => Enqueue - 1\n  => Dequeue - 2\n  => Display - 3\n  => Exit - 4\n");
        printf("\n  =>Enter your choice: ");

        scanf("%d",&choice);

        switch(choice){
            case 1:
                    printf("   ---Enter an integer to insert in queue: ");
                    scanf("%d",&n);
                    enq=Enqueue(&P,n);
                    if(enq==1){
                        printf("\n   ---Enqueue Successful---   \n\n");
                    }
                    else if(enq==0){
                        printf("\n   ---Enqueue not Successful---   \n\n");
                    }
                    break;
            case 2:
                    deq=Dequeue(&P);
                    printf("   ---Integer Dequeued from queue: %d\n\n",deq);
                    break;
            case 3:
                    QueueDisplay(P);
                    break;
            case 4:
                    exit(0);
                    break;
            default:
                    printf("   === Invalid Selection ===   \n");
                    break;
        }//End of Switch
    }//End of While loop
}//End of Main


int isEmpty(QUEUE *Q)
{
    if(Q->front>Q->rear){
    return(1);
    }

    else{
    return(0);
    }
}
int isFull(QUEUE *Q)
{
    if(Q->rear==MAXSIZE-1){
    return(1);
    }

    else{
    return(0);
    }
}

int Enqueue(QUEUE *Q,int k)
{
    if(isFull(Q)){
        printf("\n   => Queue is Full <=   \n");
    return(0);
    }

    else{
        Q->rear=Q->rear+1;
        Q->A[Q->rear]=k;
    return(1);
    }
}

int Dequeue(QUEUE *Q)
{
    int data;

    if(isEmpty(Q)){
        printf("\n   => Queue is Empty <=   \n");
        printf("\n   ---Dequeue not Successful---   \n\n");
    return;
    }

    else{
        data=Q->A[Q->front];
        Q->front=Q->front+1;
    return(data);
    }
}

void QueueDisplay(QUEUE Q)
{
    if(!isEmpty(&Q)){
        printf("\n---Queue:\n");
        printf("\n   => ");
        for(int i=Q.front;i<=Q.rear;i++){
            printf(" %d ",Q.A[i]);
        }
        printf("  <=\n");
    }

    else{
        printf("\n   => Queue is Empty <=   \n");
    }
}
