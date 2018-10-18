#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include "stack.h"

#define TRUE 1
#define FALSE 0

int top;
int st_size;
//int *stacki[]=NULL;
void **stack;
void delete_stack()
{
    if (stack) {
       free(stack);
    }
    return;
}
bool create_stack(int size)
{
    if (size < 0) {
       printf("\n INvalid stack size to create");
       return FALSE;
    }
    stack = malloc(size*sizeof(void *));
    if (stack == NULL) {
       printf("\n INternal stack creation error");
       return FALSE;
    }

    /* Initialize the other variables needed */
    st_size = size;
    top = -1;
    return TRUE;
}

bool isStack_empty()
{
    if (top == -1) {
       return TRUE;
    } else {
       return FALSE;
    }
}

bool isStack_full()
{
   if (top == (st_size-1))
   {
      return TRUE;
   } else {
      return FALSE;
   }
}

void *stack_topelement()
{
   if (!isStack_empty()) {
      return (stack[top]);
   } else {
      printf("\n Stack is empty");
      return 0;
   }
}

bool push(void *data)
{
   if (isStack_full()) {
      printf("\n Stack is full cant push the data");
      return FALSE;
   }
   stack[++top] = data;
   return TRUE;
}
void *pop()
{
   if (!isStack_empty()) {
      return stack[top--];
   }
   else 
      return 0;
}
