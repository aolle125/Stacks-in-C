#ifndef STACK_LL_H
#define STACK_LL_H

#define MAX_STACK 10

typedef struct node {
  void *elem;
  struct node *next;
} Node;

typedef struct stack {
  Node *top;
  int count;
} Stack;

/* Initialize a new Stack */
Stack *stack_initialize();

/* Adds a new element into the stack */
int stack_push(Stack *stack, void *elem);

/* Destacks an element and returns it */
void *stack_pop(Stack *stack);

/* Returns the first element in the stack (FRONT) */
void *stack_peek(Stack *stack);

/* Prints the stack using the element print function */
void stack_print(Stack *stack, void (*elem_print)(void *elem));

/* Returns the length of the stack */
int stack_get_length(Stack *stack);

/* Destroys the stack */
void stack_destroy(Stack *stack);

#endif
