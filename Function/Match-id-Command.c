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


void match_id_command(node **p_turn, node **p_affected, node **c, int *dt, card s[], int numbcard, int numbhand, int userinp[], int id) {
    node *current = NULL;
    node *temp = NULL;
    int i = 0, j = 0;
    
    
    switch (id) {
        case 1:
            break;
        case 2:
            current = *p_turn;
            for (i = 0; i < numbcard ; ++i) {
                current = *p_turn;
                for (j = 0; j < userinp[i] - 1; ++j) {
                    current = current->next;
                }
                if ((userinp[i] - 1) == 0) {
                    current = current->next;
                    current->prev = NULL;
                }
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            
            display(*p_turn);
            
            
            
            
            
            
            
    }
    
    
}
