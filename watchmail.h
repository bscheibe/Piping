#include <pthread.h>

struct Node_Mail
{
  char* filepath;
  pthread_t thread_id;
  struct Node_Mail *next;
};
struct Node_Mail* mailAdd(struct Node_Mail*, char*, pthread_t);
struct Node_Mail* mailRemoveNode(struct Node_Mail*, char*);
void mailTraverse(struct Node_Mail*);
void mailFreeNode(struct Node_Mail*);
void mailFreeAll(struct Node_Mail*);
