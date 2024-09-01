#include <stack.h>
#include <stdlib.h>
#include <stdio.h>

void initStack(struct Stack *stack)
{
  stack->height = 0;
  stack->totalHeight = PADDING;
  stack->blocks = (int *)calloc(stack->totalHeight, sizeof(int));
  stack->top = stack->height - 1;
}

void pushStack(struct Stack *stack, int data)
{
  if (stack->totalHeight < 0)
  {
    exit(EXIT_FAILURE);
  }

  if ((stack->height + 1) >= stack->totalHeight)
  {
    grow(stack);
  }

  stack->blocks[stack->top + 1] = data;
  stack->height++;
  stack->top++;
}

void popStack(struct Stack *stack)
{
  if (stack->top >= 0)
  {
    stack->blocks[stack->top] = 0;
    stack->top--;
    stack->height--;
    if ((stack->totalHeight - stack->height > PADDING) && stack->height > MIN_HEIGHT)
    {
      shrink(stack);
    }
  }
}

void reverseStack(struct Stack *stack)
{
  int *reversedStack = (int *)calloc(stack->totalHeight, sizeof(int));
  int j = 0;
  for (int i = stack->top; i >= 0; --i)
  {
    reversedStack[j] = stack->blocks[i];
    j++;
  }

  free(stack->blocks);
  stack->blocks = reversedStack;
}

void displayStack(struct Stack *stack)
{
  if (stack == NULL || stack->top == -1)
  {
    destroyStack(stack);
    exit(EXIT_FAILURE);
  }
  printf("+-----+\n");
  for (int i = stack->top; i >= 0; --i)
  {
    printf("| %d |\n", stack->blocks[i]);
    printf("+-----+\n");
  }
}

void grow(struct Stack *stack)
{
  stack->totalHeight += PADDING;
  int *newBlocks = (int *)realloc(stack->blocks, stack->totalHeight * sizeof(int));
  if (newBlocks == NULL)
  {
    fprintf(stderr, "Couldn't resize stack!");
    destroyStack(stack);
    exit(EXIT_FAILURE);
  }

  stack->blocks = newBlocks;
}

void shrink(struct Stack *stack)
{
  stack->totalHeight -= PADDING;
  int *newBlocks = (int *)realloc(stack->blocks, stack->totalHeight * sizeof(int));
  if (newBlocks == NULL)
  {
    fprintf(stderr, "Couldn't resize stack!");
    destroyStack(stack);
    exit(EXIT_FAILURE);
  }

  stack->blocks = newBlocks;
}

void destroyStack(struct Stack *stack)
{
  free(stack->blocks);
  stack->height = 0;
  stack->totalHeight = -1;
  stack->blocks = NULL;
}