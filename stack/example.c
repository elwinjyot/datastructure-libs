#include <stack.h>
#include <stdio.h>

int main()
{
  struct Stack numbers;
  initStack(&numbers);
  pushStack(&numbers, 100);
  pushStack(&numbers, 200);
  pushStack(&numbers, 300);
  pushStack(&numbers, 400);
  pushStack(&numbers, 500);

  popStack(&numbers);
  displayStack(&numbers);

  printf("Reversed stack\n");
  reverseStack(&numbers);
  displayStack(&numbers);

  printf("Element at index 0: %d\n", getAtStack(&numbers, 0));

  destroyStack(&numbers);
  return 0;
}