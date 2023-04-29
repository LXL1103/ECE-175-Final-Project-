//
//  PassOutCard.c
//  Final Project
//
// 
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
    
}node;



node *pass_out_card(node *p, card s[], int *dt) {
    node *temp = NULL;
    p = NULL;
    node *head = NULL;
    int i;
    
    
    for (i = *dt; i < 7 + *dt; ++i) {
        temp = (node*) malloc(sizeof(node));
        temp->player = s[i];
        temp->next = NULL;
        
        if (head == NULL) {
            head = temp;
        }
        else {
            p = (node*) malloc(sizeof(node));
            p = head;
            
            while (p->next != NULL) {
                
                p = p->next;
            }
            p->next = (node*) malloc(sizeof(node));
            p->next = temp;
        }
        
    }
    *dt = i;
    
    p = head;
    
    return p;
    
}



