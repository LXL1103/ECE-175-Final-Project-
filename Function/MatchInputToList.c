//
//  MatchInputToList.c
//  Final Project
//
//  Created by Man Doan on 4/29/23.
//

#include <stdio.h>
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
}node;




bool match_input_to_list(node *p, card userinp[], int size) {
    
    node *temp = NULL;
    temp = p;
    int i;
    int counter = 0;
    
    while(temp!= NULL) {
        for (i= 0; i < size; ++i) {
            if ((temp->player.value == userinp[i].value) && (strcmp(temp->player.color, userinp[i].color) == 0)) {
                ++counter;
            }
        }
        temp = temp->next;
    }
    
    
    if (counter == size) {
        return true;
    }
    
    
    return false;
    
    
}
