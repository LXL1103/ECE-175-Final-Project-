//
//  PassOutCard.c
//  Final Project
//
// 
//

#include <stdio.h>

typedef struct card_s {
char color[10];
int value;
char action[15];
struct card_s *pt;
} card;
typedef struct player_s {
    card player;
}player;




void pass_out_card(player p[], card s[]) {
    
    
    //send card from shuffle deck onto player hand and making sure to set the card collected from the shuffled deck to be "free" (deleting).
    
    
    
}



