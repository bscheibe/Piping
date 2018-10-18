#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "watchuser.h"

struct UserNode* userAppend(struct UserNode* h, char* user){
    struct UserNode* curr = h;


    if(h != NULL){
        while(curr->next != NULL){
            curr = curr->next;
        }
    }

    struct UserNode* new = (struct UserNode*)malloc(sizeof(struct UserNode));

    new->user = user;
    new->logged_on = 0;

    new->next = NULL;
    strcpy(new->user, user);

    if(h != NULL){
        curr->next = new;
    }else{
        h = new;
    }

    return h;
}

struct UserNode* findUser(struct UserNode* h, char* user){
    struct UserNode* curr = h;

    while(curr != NULL){
        if(strcmp(user, curr->user) == 0){
            return curr;
        }
        curr = curr->next;
    }

    return NULL;
}

struct UserNode* userListRemoveNode(struct UserNode* h, char* user){
    struct UserNode* curr = h;

    //At h of list
    if(strcmp(curr->user, user) == 0){
        h = curr->next;
        freeNode(curr);
        return h;
    }

    while(curr!=NULL){
        struct UserNode* next = curr->next;

        if(next != NULL){
            if(strcmp(next->user, user) == 0){
                curr->next = next->next;
                freeNode(next);
            }
        }

        curr = next;
    }

    return h;
}

void freeNode(struct UserNode* node){
    free(node->user);
    free(node);
}

void userFreeAll(struct UserNode* h){
    struct UserNode* curr = h;
    while(curr != NULL){
        struct UserNode* temp = curr;
        curr = curr->next;
        free(temp->user);
        free(temp);
    }
}
