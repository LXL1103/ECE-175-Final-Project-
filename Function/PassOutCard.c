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
typedef struct player_s {
    card player;
}player;


typedef struct node_s {
    card player;
    struct node_s *next;
    struct node_s *prev;
    
}node;




void pass_out_card(node **p, card s[], int *dt) { 
    node *temp = NULL;
    node *current = NULL;
    node **head = (node**) malloc(sizeof(node));
    
    
    
    int i = 0;
    
    for (i = *dt; i < 7 + *dt; ++i) { //for loop for transfering shuffle deck and dealing 7 cards to player 1 hand.
        temp = (node*) malloc(sizeof(node));
        temp->player = s[i];
        temp->next = NULL;
        temp->prev = NULL;
       
       
        
        if (i >= (1 + *dt) ) {
            temp->prev = (node*) malloc(sizeof(node));
            temp->prev->player = s[i - 1];
            temp->next = NULL;
            
        }
        
        if (i == *dt) { //adds card in front of linked list
            *head = (node*) malloc(sizeof(node));
            *head = temp;
            
            
            
           
            
            
            //head->player = temp->player;
        }
        
       
        else { //adds card after
            
            *p = (node*) malloc(sizeof(node));
            
            *p = *head;
            
          
            while ((*p)->next!= NULL) {
                
                *p = (*p)->next;
               
            }
            
            (*p)->next= (node*) malloc(sizeof(node));
            (*p)->next = temp;
            
           
            (*p)= temp->prev;
            
        }
    }
    
    
     
    
        
    
        int z = 0;
        *p = *head;
    
            current = *p; //change to p1/p2/centerline
            //printf("Player 1 \n");
            while(current != NULL) {
                printf("%d\n", current->player.value);
                current = current->next;
                ++z;
                if (z == 50) {
                    break;
                }
            }
        
        //send card from shuffle deck onto player hand and making sure to set the card collected from the shuffled deck to be "free" (deleting).
        
        *dt = i;//returns dt to decktracker in main.
       
        
        
    }
    
    

