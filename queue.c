#include <stdio.h>
#include <stdlib.h>
	struct queue{
   		int front;
   		int rear;
   		int *arr;
   		int size;
		};
		
		
// creating a queue dynamically
void createQ(struct queue *q,int size)
 {
 	q->front = q->rear = -1;
 	q->size = size;
 	q->arr = (int *)malloc(sizeof(int)*size);
 }
 
 
// function to enqueue
void enq(int item,struct queue *q,int size)
{
 if(q->rear+1 == size )
  {
    printf("queue full\n");
  }
  else
  {
    q->rear = q->rear+1;
    q->arr[q->rear]= item; 
  }
}

// function to dequeue
int deq(struct queue *q)
 {
   if  (q->rear == q->front)
      {
       printf("queues is empty\n");
       return -1;
      }
   else
   {q->front = q->front+1;
   int p= q->arr[q->front];
   return p;}
 }
void main()
{
  struct queue d;
  int size;
  printf("enter size of queue\n");
  scanf("%d",&size);
  createQ(&d,size);
  char val;
  int x = 0;
  while(x != 3)
  {
   printf("what do u want to do\n ");
   printf("[1- enqueu : 2 - dequeu : 3 - exit]\n");
   scanf("%d",&x);
   switch (x)
   {
     case 1:
     int item;
     printf("enter element to enqueue\n");
     scanf("%d",&item);
     enq(item,&d,size);
     break;
     case 2:
     int del;
     del =deq(&d);
     if(del != -1)
     {
     printf("dequed element is: %d\n",del);
     }
     else if(del == -1)
     break;
     break;
     case 3:
     x = 3;
     break;
     default :
     printf("wrong input\n");
     
  }
   
  }
  


}
