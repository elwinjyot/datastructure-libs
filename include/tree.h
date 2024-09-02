struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct BinaryTree {
  struct Node *root;
  int nodeCount;
};

void initTree(struct BinaryTree *);
struct Node *createNode(struct BinaryTree *);