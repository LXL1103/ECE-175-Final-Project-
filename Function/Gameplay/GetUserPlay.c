//
//  GetUserPlay.c
//  Final Project
//
//  Created by Man Doan on 4/29/23.
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





void getuserplay(card s[], int num) {
    for (int i = 0; i < num; ++i) {
        printf("Type in Card #%d that you want to play. Include color, number, and action as shown in your hand: ", i + 1);
        scanf("%s%d%s", s[i].color, &s[i].value, s[i].action);
        /*
        scanf("%s ",s[i].color);
        scanf(" %d ", &s[i].value);
        scanf(" %s",s[i].action);
         */
    }
    
    
    
    
}
