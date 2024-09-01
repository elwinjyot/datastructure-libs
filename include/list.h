struct List
{
  struct Node *head;
  struct Node *tail;
  int length;
};

struct Node
{
  int data;
  int index;
  struct Node *next;
  struct Node *prev;
};

void initList(struct List *);
struct Node *pushList(struct List *, int);
void popList(struct List *);
int getAtList(struct List *, int);
struct List *reverseList(struct List *);
void displayList(struct List *);
void destroyList(struct List *);