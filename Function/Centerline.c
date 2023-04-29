//
//  Centerline.c
//  Final Project
//
//  Created by Man Doan on 4/28/23.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct card_s {
char color[10];
int value;
char action[15];
struct card_s *pt;
} card;

typedef struct node_s {
    card player;
    
    struct node_s *next;
    struct node_s *prev;
    
}node;


node *centerline_F(node *c, card s[], int *dt) {
    node *temp = NULL;
    c = NULL;
    node *head = NULL;
    int i;
    
    
    for (i = *dt; i < 2 + *dt; ++i) {
        temp = (node*) malloc(sizeof(node));
        temp->player = s[i];
        temp->next = NULL;
        
        if (head == NULL) {
            head = temp;
        }
        else {
            c = (node*) malloc(sizeof(node));
            c = head;
            
            while (c->next != NULL) {
                c = c->next;
            }
            c->next = (node*) malloc(sizeof(node));
            c->next = temp;
        }
        
    }
    *dt = i;
    
    c = head;
    
    return c;
    
}
    
    
    
    
    
    
    
    
