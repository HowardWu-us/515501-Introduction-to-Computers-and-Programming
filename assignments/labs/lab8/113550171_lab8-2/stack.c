#include <stdio.h>
#include <stdlib.h>
#include "custom_assert.h"
#include "stack.h"

void make_empty(Stack *s, int capacity)
{
    s->_contents = (int *)malloc(capacity * sizeof(int));
    s->_top = 0;
    s->_capacity = capacity;
}

void clear_stack(Stack *s)
{
    s->_top = 0;
    free(s->_contents);
}

bool is_empty(const Stack *s)
{
    return s->_top == 0;
}

int size(const Stack *s)
{
    return s->_top;
}

void print_stack(const Stack *s)
{
    printf("Current stack contains: ");
    for (int i = s->_top - 1; i >= 0; i--)
    {
        printf("%d ", s->_contents[i]);
    }
    puts("");
}

void push(Stack *s, int i) {

#ifdef DEBUG
    printf("DEBUG: Pushing at stack\n");
#endif
    if(size(s) == s->_capacity) {
        assert("Stack overflow.\n");
    } else {
        s->_contents[size(s)] = i;
        s->_top++;
    }
}
void pop(Stack *s) {
#ifdef DEBUG
    printf("DEBUG: Poping at stack\n");
#endif
    if(size(s)==0) {
        assert("Stack underflow.\n");
    }
    else {
        s->_top -= 1;
    }
}
int peek(const Stack *s) {
#ifdef DEBUG
    printf("DEBUG: Peeking at stack\n");
#endif
    if(is_empty(s)) {
        assert("The stack is empty.\n");
        return 0;
    } else {
        return s->_contents[s->_top-1];
    }
}