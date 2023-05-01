//
//  IsValidWithCenter.c
//  Final Project
//
//  Created by Man Doan on 4/30/23.
//

#include <stdio.h>
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
}node;



bool isValidWithCenter(card userinp[], node *c, int numcard) {
    int totvalue = 0;
    
    
    
    for (int i = 0; i < numcard; ++i) { //get total value from user input array
        totvalue = totvalue + userinp[i].value;
    }
    
    
    if (totvalue == c->player.value) {
        return true;
    }
    
    return false;
}
