#include <tree.h>
#include <stddef.h>
#include <stdlib.h>

void initTree(struct BinaryTree *tree)
{
  tree->root = NULL;
  tree->nodeCount = 0;
}

struct Node *createNode(struct BinaryTree *tree)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  return newNode;
}