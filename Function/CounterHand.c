//
//  CounterHand.c
//  Final Project
//
//  Created by Man Doan on 5/2/23.
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
    struct node_s *prev;
    
}node;


int counter(node p) {
    
    
    int z = 0;
    node * current =NULL;
    
    current = (node*) malloc(sizeof(node));
        *current = p; //change to p1/p2/centerline
        //printf("Player 1 \n");
        while(current != NULL) {
            current = current->next;
            ++z;
            if (z == 50) {
                break;
            }
        }
    return z;
    
    
    
}

