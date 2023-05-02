//
//  Determineplay.c
//  Final Project
//
//  Created by Man Doan on 5/2/23.
//


#include <stdio.h>
#include <stdbool.h>
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
    struct node_s *prev;
    
}node;

int determineplay(node *p, node *c, int userinp[], int numcard, int numhand) {
    
    node *temp;
    int i = 0, j = 0;
    int tempnum;
    int totval = 0;
    int colormatch = 0;
    int anynumbermatch = 0;
 
    
    for (i = 0; i < numcard; ++i) {
        temp = p;
        for(j = 0; j < userinp[i] - 1; ++j) {
            temp = temp->next;
        }
        if (strcmp(temp->player.action, "AnyNumber") == 0) {
            ++anynumbermatch;
            continue;
        }
        totval = totval + temp->player.value;
        
        if ((strcmp(temp->player.color, c->player.color)==0) || (strcmp(temp->player.action, "AnyColor") == 0)) {
            ++colormatch;
        }
        
    }
    
    if (anynumbermatch > 0) { //if a any number card is played, the if statement will match the desire number the user want to play. Note that this assume that the max card the player will play is 2 on a centerline.
        if (anynumbermatch == 1) {
            tempnum = c->player.value - totval;
        }
        if (anynumbermatch == 2) {
            totval = c->player.value;
        }
    }
    
    
    if ((colormatch == numcard) && ((totval == c->player.value) || (strcmp(c->player.action, "AnyNumber") ==0)) && (numcard == 2)) {
        printf("Double Color Match\n");
        tempnum = 1;
        return tempnum;
    }
    else if ((colormatch == numcard) && ((totval == c->player.value) || (strcmp(c->player.action, "AnyNumber") ==0)) && (numcard == 1)) {
        printf("Single Color Match\n");
        tempnum = 2;
        return tempnum;
    }
    else if (((totval == c->player.value) || (strcmp(c->player.action, "AnyNumber") == 0)) && (numcard == 2)) {
        printf("Double Match\n");
        tempnum = 3;
        return tempnum;
    }
    else if (((totval == c->player.value) || (strcmp(c->player.action, "AnyNumber") == 0)) && (numcard == 1)) {
        printf("Single Match\n");
        tempnum = 4;
        return tempnum;
             }
    else {
        printf("error");
        tempnum = 0;
        return tempnum;
    }
    
    
}





