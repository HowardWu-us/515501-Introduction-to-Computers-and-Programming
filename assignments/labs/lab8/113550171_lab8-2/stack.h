#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct stack
{
    int *_contents;
    int _top, _capacity;
} Stack;

void make_empty(Stack *s, int capacity);
bool is_empty(const Stack *s);
int size(const Stack *s);
void push(Stack *s, int i);
void pop(Stack *s);
int peek(const Stack *s);
void clear_stack(Stack *s);
void print_stack(const Stack *s);

#endif // STACK_H