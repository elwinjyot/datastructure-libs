#define PADDING 5
#define MIN_HEIGHT 3

struct Stack
{
  int top;
  int height;
  int totalHeight;
  int fixed;
  int *blocks;
};

void initStack(struct Stack *);
void pushStack(struct Stack *, int);
void popStack(struct Stack *);
void reverseStack(struct Stack *);
int getAtStack(struct Stack *, int index);
void grow(struct Stack *);
void shrink(struct Stack *);
void displayStack(struct Stack *stack);
void destroyStack(struct Stack *);