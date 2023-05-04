//
//  DeleteCard.c
//  Final Project
//
//  Created by Man Doan on 5/2/23.
//

#include <stdio.h>
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
    struct node_s *prev;
    
}node;





void deletecard(node **p_turn, node *current)  {
    
    if (current == *p_turn) {
        *p_turn = current;
    }
    
    else {
        
        current->prev->next = current->next;
        //*p_turn = current->prev->next;
    }
    
    if (current->next == NULL) {
        current = current->prev;
        
        while ((*p_turn)->next != NULL) {
            *p_turn = (*p_turn)->next;
        }
        if((*p_turn)->next != NULL) {
            *p_turn = current;
        }
        free(current->next);
    }
    else {
        current->next->prev = current->prev;
        *p_turn = current->next->prev;
    }
    
    
    
    
    free(current);
    
    
    
}
