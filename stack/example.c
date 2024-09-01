#include <stack.h>

int main()
{
  struct Stack numbers;
  initStack(&numbers);
  pushStack(&numbers, 100);
  pushStack(&numbers, 200);
  pushStack(&numbers, 300);
  pushStack(&numbers, 400);

  popStack(&numbers);
  displayStack(&numbers);
  reverseStack(&numbers);
  displayStack(&numbers);

  destroyStack(&numbers);
  return 0;
}