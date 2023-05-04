//
//  Determineplay.c
//  Final Project
//
//  Created by Man Doan on 5/2/23.
//


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include <math.h>

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
        for(j = 0; j < userinp[i] -1; ++j) {//traverse to card the player chose
            temp = temp->next;
           
    }
        if ((strcmp(temp->player.action, "AnyNumber") == 0) || (strcmp(c->player.action, "AnyNumber") == 0)) { //scans for attribute of the card the plyaer played
            ++anynumbermatch;
            continue;
        }
        totval = totval + temp->player.value;
        
        if (strcmp(c->player.color,temp->player.color) == 0) {
            ++colormatch;
        }
        else if ((strcmp(c->player.action, "AnyColor") == 0) || (strcmp(temp->player.action, "AnyColor") == 0)) {
            ++colormatch;
            break;
    }
        
}
    
        if (anynumbermatch >= 1) { //if a any number card is played, the if statement will match the desire number the user want to play. Note that this assume that the max card the player will play is 2 on a centerline.
            totval = c->player.value;
        }
        
    
    
    //the following determine what kind of play the player made
    if (((colormatch == numcard) && (totval == c->player.value) && (numcard == 2)) || ((strcmp(c->player.action, "AnyColor") ==0) && (numcard == 2))) {
        printf("Double Color Match\n");
        tempnum = 1;
        return tempnum;
    }
    
    else if (((colormatch == numcard) && (totval == c->player.value) && (numcard == 1)) || ((strcmp(c->player.action, "AnyColor") ==0) && (numcard == 1))) {
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





