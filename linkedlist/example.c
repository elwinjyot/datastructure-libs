#include <stdio.h>
#include <list.h>

int main()
{
  struct List numbers;
  initList(&numbers);

  pushList(&numbers, 20);
  pushList(&numbers, 40);
  pushList(&numbers, 50);
  pushList(&numbers, 10);

  displayList(&numbers);
  printf("\nItem at index 4: %d\n", getAtList(&numbers, 4));

  reverseList(&numbers);

  displayList(&numbers);
  printf("\nItem at index 4: %d\n", getAtList(&numbers, 4));

  printf("\nLength of list: %d\n", numbers.length);

  destroyList(&numbers);

  return 0;
}