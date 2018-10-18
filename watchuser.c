#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "watchuser.h"

struct Node_User* userAdd(struct Node_User* h, char* user){
    struct Node_User* curr = h;

    if(h != NULL){
        while(curr->next != NULL){
            curr = curr->next;
        }
    }
    struct Node_User* new = (struct Node_User*)malloc(sizeof(struct Node_User));
    new->user = user;
    new->loggedin = 0;
    new->next = NULL;

    strcpy(new->user, user);

    if(h != NULL){
        curr->next = new;
    }else{
        h = new;
    }
    return h;
}

struct Node_User* userListRemoveNode(struct Node_User* h, char* user){
    struct Node_User* curr = h;
    if(strcmp(curr->user, user) == 0){
        h = curr->next;
        userFreeNode(curr);
        return h;
    }

    while(curr!=NULL){
        struct Node_User* next = curr->next;

        if(next != NULL){
            if(strcmp(next->user, user) == 0){
                curr->next = next->next;
                userFreeNode(next);
            }
        }

        curr = next;
    }

    return h;
}

struct Node_User* userFind(struct Node_User* h, char* user){
    struct Node_User* curr = h;
    while(curr != NULL){
        if(strcmp(user, curr->user) == 0){
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}



void userFreeNode(struct Node_User* node){
    free(node->user);
    free(node);
}

void userFreeAll(struct Node_User* h){
    struct Node_User* curr = h;
    while(curr != NULL){
        struct Node_User* temp = curr;
        curr = curr->next;
        free(temp->user);
        free(temp);
    }
}
