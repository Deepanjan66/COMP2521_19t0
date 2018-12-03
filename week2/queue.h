#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue *Queue;

Queue queue_new (void);
void queue_drop (Queue);
Item queue_de (Queue q);
void queue_en (Queue, Item);
size_t queue_size (Queue);

#endif
