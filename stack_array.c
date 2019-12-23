#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack_array.h"

/* Local Functions */
static int is_full(Stack *stack) {
  if(stack->top == MAX_STACK) {
    return 1;
  }
  else {
    return 0;
  }
}

static int is_empty(Stack *stack) {
  if(stack->top == -1) {
    return 1;
  }
  else {
    return 0;
  }
}

/* Initialize a new Array Based Stack */
Stack *stack_initialize() {
  Stack *new_stack = malloc(sizeof(Stack));
  if(new_stack != NULL) {
    new_stack->top = -1;
  }
  return new_stack;
}

/* Adds a new element into the stack, return 0 if full */
int stack_push(Stack *stack, void *elem) {
  if(stack != NULL && !is_full(stack)) {
    stack->top++;
    stack->elems[stack->top] = elem;
    return 1;
  }
  else {
    return 0;
  }
}

/* Pops an element and returns it */
void *stack_pop(Stack *stack) {
  void *elem = NULL;
  if(stack != NULL && !is_empty(stack)) {
    elem = stack->elems[stack->top];
    stack->elems[stack->top] = NULL;
    stack->top--;
    return elem;
  }
  else {
    return NULL;
  }
}

/* Returns the first element in the stack (FRONT) */
void *stack_peek(Stack *stack) {
  if(stack != NULL && !is_empty(stack)) {
    return stack->elems[stack->top];
  }
  else {
    return NULL;
  }
}

/* Returns the length of the stack */
int stack_get_length(Stack *stack) {
  if(stack != NULL && !is_empty(stack)) {
    return stack->top + 1; // Index 0 would mean 1 element is in the stack
  }
  else {
    return 0;
  }
}

/* Destroys the stack */
void stack_destroy(Stack *stack) {
  free(stack);
  stack = NULL;
}

/* Prints the stack using the element print function */
void stack_print(Stack *stack, void (*elem_print)(void *elem)) {
  if(stack == NULL || elem_print == NULL) {
    printf("Stack Not Initialized\n");
    return;
  }

  if(is_empty(stack)) {
    printf("Stack: [ 0 fns] Empty\n");
  }
  else {
    printf("Stack: [%2d fns] (%2d)", 
           stack_get_length(stack), stack->top);
    int index = 0;
    while(index <= stack->top) {
      (*elem_print)(stack->elems[index]);
      if(index != stack->top) {
        printf(", ");
      } 
      index = (index + 1) % MAX_STACK;
    }
    printf("\n");
  }
}

