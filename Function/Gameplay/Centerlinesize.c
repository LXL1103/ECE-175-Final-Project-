//
//  Centerlinesize.c
//  Final Project
//
//  Created by Man Doan on 4/30/23.
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
}node;





void centerlinesize(node *c, int * size) {
    node *current = c;
    int i = 0;
   
    while(current != NULL) {
        current = current->next;
        ++i;
        if (i == 50) {
            break;
        }
    }
    *size = i;
}
