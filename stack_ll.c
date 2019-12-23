#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack_ll.h"

/* Local Functions */
static int is_full(Stack *stack) {
  int count = stack_get_length(stack);
  if(count >= MAX_STACK) {
    return 1;
  }
  else {
    return 0;
  }
}

static int is_empty(Stack *stack) {
  if(stack == NULL || stack->top == NULL) {
    return 1;
  }
  else {
    return 0;
  }
}

static Node *create_node(void *elem) {
  Node *new_node = malloc(sizeof(Node));
  if(new_node != NULL) {
    new_node->elem = elem;
    new_node->next = NULL;
  }
  return new_node;
}

/* Initialize a new Linked List Based Stack */
Stack *stack_initialize() {
  Stack *new_stack = malloc(sizeof(Stack));
  if(new_stack != NULL) {
    new_stack->count = 0;
    new_stack->top = NULL;
  }

  return new_stack;
}

/* Adds a new element into the stack, return 0 if full */
int stack_push(Stack *stack, void *elem) {
  Node *node = NULL;
  if(stack == NULL || is_full(stack)) {
    return 0;
  }

  node = create_node(elem);
  if(node != NULL) {
    if(is_empty(stack)) {
      stack->top = node;
      stack->count = 1; 
      return 1;
    }
    else {
      node->next = stack->top;
      stack->top = node;
      stack->count++;
      return 1; // Node inserted
    }
  }
  else {
    return 0; // Failed to create node
  }
}

/* Pops an element and returns it */
void *stack_pop(Stack *stack) {
  void *elem = NULL;
  Node *reaper = NULL;
  
  if(stack == NULL || is_empty(stack)) {
    return NULL;
  }
  else {
    elem = stack->top->elem;
    reaper = stack->top;
    stack->top = stack->top->next;
    free(reaper);
    reaper = NULL;
    stack->count--;
    return elem;
  }
}

/* Returns the first element in the stack (FRONT) */
void *stack_peek(Stack *stack) {
  if(stack == NULL || is_empty(stack)) {
    return NULL;
  }
  else {  
    return stack->top->elem;
  }
}

/* Prints the stack using the element print function */
void stack_print(Stack *stack, void (*elem_print)(void *elem)) {
  Node *walker = NULL;
  if(stack == NULL || elem_print == NULL) {
    printf("Stack Not Initialized\n");
    return;
  }

  if(is_empty(stack)) {
    printf("Stack: [ 0 functions] Empty\n");
  }
  else {
    printf("Stack: [%2d functions]", stack_get_length(stack));
    for(walker = stack->top; walker != NULL; walker = walker->next) {
      elem_print(walker->elem);
      if(walker->next != NULL) {
        printf(", ");
      }
    }
    printf("\n");
  }
}

/* Returns the length of the stack */
int stack_get_length(Stack *stack) {
  if(stack != NULL) {
    return stack->count;
  }
  else {
    return 0;
  }
}

/* Destroys the stack */
void stack_destroy(Stack *stack) {
  Node *walker = NULL;
  Node *reaper = NULL;

  if(stack == NULL) {
    return;
  }
  else {
    walker = stack->top;
    while(walker != NULL) {
      reaper = walker;
      walker = walker->next;
      free(reaper);
      reaper = NULL;
    }

    free(stack);
    stack = NULL;
  }
  return;
}
