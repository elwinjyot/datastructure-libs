#include <list.h>
#include <stdlib.h>
#include <stdio.h>

void initList(struct List *list)
{
  list->head = NULL;
  list->tail = NULL;
  list->length = 0;
}

struct Node *pushList(struct List *list, int data)
{
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  list->length++;

  if (list->head == NULL || list->tail == NULL)
  {
    newNode->index = 0;
    list->head = newNode;
    list->tail = newNode;
    return newNode;
  }

  list->tail->next = newNode;
  newNode->index = list->tail->index + 1;
  newNode->prev = list->tail;
  list->tail = newNode;
  return newNode;
}

void popList(struct List *list)
{
  list->tail->prev->next = NULL;
}

int getAtList(struct List *list, int index)
{
  if (index >= list->length)
  {
    return -1;
  }

  struct Node *curr = list->head;
  while (curr != NULL)
  {
    if (curr->index == index)
    {
      return curr->data;
    }
    curr = curr->next;
  }
}

struct List *reverseList(struct List *list)
{
  struct Node *curr = list->tail;
  list->head = curr;
  while (curr != NULL)
  {
    curr->index = (list->length - 1) - curr->index;
    curr->next = curr->prev;
    curr = curr->next;
  }

  list->tail = curr;
  return list;
}

void displayList(struct List *list)
{
  struct Node *head = list->head;
  printf("[");
  while (head != NULL)
  {
    printf("{%d: %d}", head->index, head->data);
    head = head->next;
    if (head != NULL)
    {
      printf(", ");
    }
  }
  printf("]");
}

void destroyList(struct List *list)
{
  if (list == NULL || list->head == NULL)
  {
    exit(EXIT_FAILURE);
  }

  struct Node *curr = list->tail;
  while (curr != NULL)
  {
    struct Node *prev = curr->prev;
    free(curr);
    list->tail = prev;
    curr = list->tail;
  }

  list = NULL;
}