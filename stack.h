#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

#if 0
bool create_stack(int size);
bool isStack_empty();
bool isStack_full();
void *stack_topelement();
bool push(void *data);
void * pop();
void delete_stack();
#endif
void print_stack(void **stack);
void *pop(void **stack);
bool push(void **stack,void *data);
void *stack_topelement(void **stack);
bool isStack_full(void **stack);
bool isStack_empty(void **stack);
void **create_stack(int size);
void delete_stack(void **stack);

#endif
