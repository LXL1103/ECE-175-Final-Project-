//
//  Display.c
//  Final Project
//
//  Created by Man Doan on 4/28/23.
//

#include <stdio.h>


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



void display(node *d) {
    int i = 0;
    node *current = d;
    while(current != NULL) {
        printf("|%s %d %s|", current->player.color, current->player.value,current->player.action);
        current = current->next;
        ++i;
        if (i == 50) {
            break;
        }
    }
}
