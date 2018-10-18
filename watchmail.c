#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "watchmail.h"
#include <pthread.h>

struct Node_Mail* mailAdd(struct Node_Mail* head, char* filepath, pthread_t id){
    struct Node_Mail* current = head;


    if(head != NULL){
        while(current->next != NULL){
            current = current->next;
        }
    }

    struct Node_Mail* new = (struct Node_Mail*)malloc(sizeof(struct Node_Mail));
    new->filepath = filepath;
    new->next = NULL;
    strcpy(new->filepath, filepath);
    new->thread_id = id;
    if(head != NULL){
        current->next = new;
    }else{
        head = new;
    }
    return head;
}

void mailTraverse(struct Node_Mail* head){
    struct Node_Mail* current = head;

    while(current->next != NULL){
        printf("File: %s Id: %i\n", current->filepath, (int)current->thread_id);
        current = current->next;
    }
}

struct Node_Mail* mailRemoveNode(struct Node_Mail* head, char* filepath){
    struct Node_Mail* current = head;
    if(strcmp(current->filepath, filepath) == 0){
        head = current->next;
        mailFreeNode(current);
        return head;
    }

    while(current!=NULL){
        struct Node_Mail* next = current->next;

        if(next != NULL){
            if(strcmp(next->filepath, filepath) == 0){
                current->next = next->next;
                mailFreeNode(next);
            }
        }
        current = next;
    }
    return head;
}

void mailFreeNode(struct Node_Mail* node){
    printf("%i, %s\n",(int)node->thread_id,node->filepath);
    pthread_cancel(node->thread_id);
    pthread_join(node->thread_id, NULL);
    free(node->filepath);
    free(node);
}




void mailFreeAll(struct Node_Mail* head){
    struct Node_Mail* current = head;
    while(current != NULL){
        struct Node_Mail* toDelete = current;
        current = current->next;
        pthread_cancel(toDelete->thread_id);
        pthread_join(toDelete->thread_id, NULL);
        free(toDelete->filepath);
        free(toDelete);
    }
}
