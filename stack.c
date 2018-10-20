#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include "stack.h"

#define TRUE 1
#define FALSE 0

typedef struct stack_info_ {
    int size;
    int top;
} stack_info;
//int top;
//int st_size;
//int *stacki[]=NULL;
//void **stack;
void delete_stack(void **stack)
{
    if (stack) {
       if (stack[0]) {
          free(stack[0]);
       }
       free(stack);
    }
    return;
}
void **create_stack(int size)
{
    void **stack = NULL;
    stack_info *metadata = NULL;
    if (size < 0) {
       printf("\n INvalid stack size to create");
       return FALSE;
    }
    stack = malloc((size+1)*sizeof(void *));
    if (stack == NULL) {
       printf("\n INternal stack creation error");
       return NULL;
    }

    /* Initialize the other variables needed
     * the first element in the stack is always the 
     * stack strucutre which will have information
     * realted to stack size and top element
     */
    metadata = (stack_info *)malloc(sizeof(stack_info));
    metadata->size = size;
    metadata->top = 0;
    stack[0] = (void *)metadata;
    return stack;
}

bool isStack_empty(void **stack)
{
    int top = -1;
    stack_info *metadata = (stack_info *)stack[0];
    top = metadata->top;
    if (top == 0) {
       return TRUE;
    } else {
       return FALSE;
    }
}

bool isStack_full(void **stack)
{
    int top = -1,st_size=0;
    stack_info *metadata = (stack_info *)stack[0];
    top = metadata->top;
    st_size = metadata->size;
   if (top == (st_size))
   {
      return TRUE;
   } else {
      return FALSE;
   }
}

void *stack_topelement(void **stack)
{
    int top = -1;
    stack_info *metadata = (stack_info *)stack[0];
    top = metadata->top;
   if (!isStack_empty(stack)) {
      return (stack[top]);
   } else {
      printf("\n Stack is empty");
      return 0;
   }
}

bool push(void **stack,void *data)
{
   // int top = -1;
    stack_info *metadata = (stack_info *)stack[0];
    //top = metadata->top;
   if (isStack_full(stack)) {
      printf("\n Stack is full cant push the data");
      return FALSE;
   }
   stack[++(metadata->top)] = data;
   return TRUE;
}
void *pop(void **stack)
{
   stack_info *metadata = (stack_info *)stack[0];
   if (!isStack_empty(stack)) {
      return stack[(metadata->top)--];
   }
   else 
      return 0;
}

void print_stack(void **stack)
{
    stack_info *metadata = (stack_info *)stack[0];
    int top = metadata->top;

    if (top == 0) {
        printf("\n Stack is empty, nothing to print");
        return;
    }
    while (top >0) {
        printf("\n %p",stack[top--]);
    }
    return;
}
