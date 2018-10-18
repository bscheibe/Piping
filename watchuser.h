
struct Node_User
{
  char* user;
  int loggedin;
  struct Node_User *next;
};
struct Node_User* userRemove(struct Node_User*, char*); // need to implement
struct Node_User* userFind(struct Node_User*, char*);
struct Node_User* userAdd(struct Node_User*, char*);
void userFreeNode(struct Node_User*);
void userFreeAll(struct Node_User*);
