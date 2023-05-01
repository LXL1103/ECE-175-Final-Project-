//
//  DetermineTypeMatch.c
//  Final Project
//
//  Created by Man Doan on 4/30/23.
//

#include <stdio.h>

#include <stdlib.h>
#include <string.h>




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


int determine_type_match(card userinp[], node *c, int numcard) {
    
    int totvalue = 0;
    int id = 0;
    char test[10];
    int i;
    int samecolorcounter = 0;
    
    strcpy(test, "AnyNumber");
    
    for (int i = 0; i < numcard; ++i) { //get total value from user input array
        totvalue = totvalue + userinp[i].value;
    }
    
    
    
    //function to check for action card
    
    if (totvalue == c->player.value) {
        for (i = 0; i < numcard; ++i) {
            if (strcmp(c->player.color , userinp[i].color) == 0) {
                ++samecolorcounter;
            }
        }
        
        if (samecolorcounter == numcard) {
            id = 2;
            return id;
        }
    }
    if (totvalue == c->player.value) {
        id = 1;
        return id;
    }
    
    
    
    return id;
    
}



