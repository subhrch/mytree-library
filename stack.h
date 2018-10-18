#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

bool create_stack(int size);
bool isStack_empty();
bool isStack_full();
void *stack_topelement();
bool push(void *data);
void * pop();
void delete_stack();

#endif
