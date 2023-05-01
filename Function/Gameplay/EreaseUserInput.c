//
//  EreaseUserInput.c
//  Final Project
//
//  Created by Man Doan on 4/29/23.
//

#include <stdio.h>
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


void ereaseinp(card userinp[]) {
    for (int i = 0; i < 10; ++i) {
        userinp[i].value = 999;
        strcpy(userinp[i].color,"Empty");
        strcpy(userinp[i].action,"Empty");
    }
}
