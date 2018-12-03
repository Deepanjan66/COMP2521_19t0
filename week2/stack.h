#ifndef STACK_H
#define STACK_H

typedef struct stack *Stack;

Stack stack_new (void);
void stack_drop (Stack);
Item stack_pop (Stack s);
void stack_push (Stack, Item);
size_t stack_size (Stack);

#endif
