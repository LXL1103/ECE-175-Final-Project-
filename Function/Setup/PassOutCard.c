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



void pass_out_card(node **p, card s[], int *dt) { //one way link list. This function was based on the video lecture on singly linked list from the video lecture.
    node *temp = NULL;
    
    
    node **head = (node**) malloc(sizeof(node));;
   
    int i;
    
    
    for (i = *dt; i < 7 + *dt; ++i) { //for loop for transfering shuffle deck and dealing 7 cards to player's hand.
        temp = (node*) malloc(sizeof(node));
        temp->player = s[i];
        temp->next = NULL;
        
        if (*head == NULL) { //adds card in front of linked list
            *head = (node*) malloc(sizeof(node));
            *head = temp;
            
            //head->player = temp->player;
        }
        else { //adds card after
            *p = (node*) malloc(sizeof(node));
            *p = *head;
            
            while ((*p)->next != NULL) {
                
                *p = (*p)->next;
            }
            (*p)->next = (node*) malloc(sizeof(node));
            (*p)->next = temp;
        }
        
    }
    *dt = i;//returns dt to decktracker in main.
    *p = *head;
    
    
}



