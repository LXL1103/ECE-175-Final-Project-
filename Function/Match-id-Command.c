//
//  Match-id-Command.c
//  Final Project
//
//  Created by Man Doan on 5/2/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

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

void display(node *d);
void deletecard(node **p_turn, node *current);


void match_id_command(node **p_turn, node **p_affected, node **c, int *dt, card s[], int numbcard, int numbhand, int userinp[], int id) {
    //p_turn is the player who's currently making a play
    //p_affected is the player that's going to get their deck alter if p_turn makes a double or single clor match play.
    
    node *current = NULL;
    node *head = NULL;
    
   
    
    int i = 0, j = 0;
    
    
    switch (id) {
        case 1:
            // A function to help make player_affected draw a card.
            //A function to help discard one card from p_turn card
            //a function to add a card to centerline.
            break;
        case 2:
            // A function to help make player_affected draw a card.
            //A function to help discard two card from p_turn card
            //a function to add a card to centerline.
            break;
        case 3:
        case 4:
            //current = *p_turn;
            head = *p_turn;
            
            for (i = 0; i < numbcard ; ++i) {
                
                
                
                for (j = 0; j < userinp[i]; ++j) {
                    if (j==0) {
                        current = head;
                    }
                    current = current->next;
                    
                }
                deletecard(p_turn, current);
                
            }
            
            display(*p_turn);
            
            
            
    }
    
}
