#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

bool create_queue(int size);
bool isqueue_empty();
bool isqueue_full();
void *queue_frontelem();
bool enqueue(void *data);
void dequeue();
void delete_queue();
void print_queue();

#endif
