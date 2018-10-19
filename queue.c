#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include "queue.h"

#define TRUE 1
#define FALSE 0

int front,rear;
int q_size;
//int *queuei[]=NULL;
void **queue;
void delete_queue()
{
    if (queue) {
       free(queue);
    }
    return;
}
bool create_queue(int size)
{
    if (size < 0) {
       printf("\n INvalid queue size to create");
       return FALSE;
    }
    queue = malloc(size*sizeof(void *));
    if (queue == NULL) {
       printf("\n INternal queue creation error");
       return FALSE;
    }

    /* Initialize the other variables needed */
    q_size = size;
    front = -1;
    rear = 0;
    return TRUE;
}

bool isqueue_empty()
{
    if (front == -1 && rear == 0) {
       return TRUE;
    } else {
       return FALSE;
    }
}

bool isqueue_full()
{
   if (front == (q_size-1) ||
       rear == (q_size-1))
   {
      return TRUE;
   } else {
      return FALSE;
   }
}

void *queue_frontelem()
{
   if (!isqueue_empty() && (front !=rear)) {
      return (queue[front]);
   } else {
      printf("\n Queue is empty");
      return 0;
   }
}

bool enqueue(void *data)
{
   if (isqueue_full()) {
      printf("\n Queue is full cant push the data");
      return FALSE;
   }
   queue[rear++] = data;
   if (front == -1) {
       front++;
   }
   return TRUE;
}
void dequeue()
{
   void *temp = NULL;
   if (!isqueue_empty()) {
       temp = queue[front];
       queue[front++] = NULL;;
       /* was this the last element towards the queue end then reset the queue to empty*/
       if (front == (q_size)) {
  
           front = -1;
           rear = 0;
       }
       free (temp);
       return;
   }
   else 
      return;
}
void print_queue()
{
    int i = 0;
    if (!isqueue_empty()) {
       for( i = front;i<=rear;i++)
       {
           printf("\t %p",queue[i]);
       }
       printf("\n Front=%d Rear = %d",front,rear);
    } else {
       printf("\n Queue is empty nothing to print");
    }
    return;
}
