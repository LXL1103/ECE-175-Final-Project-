//
//  Player1Action.c
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


int counter(node p);
void display(node *d);
int determineplay(node *p, node *c, int userinp[], int numcard, int numhand);
bool isValidWithCenter(node *p, node *c, int userinp[], int sizeinp);
void match_id_command(node **p_turn,node **p_affected, node **c, int *dt, card s[], int numbcard, int numbhand,int userinp[], int id);



bool player1Action(node **p1, node **p2, node **c, card s[], int *dt) {
    int numberhand = 0; //total number of cards in players hand
    int numbercard = 0;//how many card the user want to play
    int userinp[3];
    int i;
    int match_id = 0;
    int playerturn = 0;
    int centercount = 0;
    
    bool isValidCenter = false;
    node *current = NULL;
    
    numberhand = counter(**p1); //counts how many is in player hand
    
    
    current = *c;
    
    while (current != NULL) {
        printf("Centerline: ");
        display(*c); //display centerline
        
        printf("Player 1 Hand: ");
        display(*p1);
        
        //printf("Please choose from 1 to %d", numberhand);
        printf("Select the NUMBER of card you want to play for %s %d %s (Select between 1-2 or press 0 to move onto the next card in centerline): ", current->player.color, current->player.value , current->player.action);
        scanf("%d", &numbercard);
        
        if (numbercard == 0) {
            current = current->next;
            continue;
        }
        
        while (numbercard > 3) { //error message for when user type in a card number higher than 10
            printf("Not possible to add using more than 2 cards, Please try to type a number of card between 1-2 or 0 if you are unable to make a play.");
            scanf("%d", &numbercard);
        }
        
        
        for (i = 0; i < numbercard; ++i) { //scans for player
            printf("Choose from 1 to %d (Left to Right) on your hand for Card #%d\n", numberhand, i + 1);
            printf("(Note: if you want to go back to number of card prompt, press 11): ");
            
            scanf("%d", &userinp[i]);
            if (userinp[i] == 11) {//breaks out of for loop
                break;
            }
            
        }
        if (userinp[i] == 11) {//returns prompt for numbercard
            continue;
        }
        
        match_id = determineplay(*p1, current, userinp, numbercard, numberhand);
        
        while (match_id == 0)  { //error message if the player makes a play that doesn;t match centerline
            printf("Invalid play, please try again.\n");
            for (i = 0; i < numbercard; ++i) { //scans for player
                printf("Choose from 1 to %d (Left to Right) on your hand for Card #%d\n", numberhand, i + 1);
                printf("Note: if you want to go back to number of card prompt, press 11): ");
                scanf("%d", &userinp[i]);
                if (userinp[i] == 11) {
                    break;
                }
                
            }
            if (userinp[i] == 11) {
                break;
            }
            match_id = determineplay(*p1, current, userinp, numbercard, numberhand);
        }
        if (userinp[i] == 11) {
            continue;
        }
        
        match_id_command(&(*p1),&(*p2), &(*c), &(*dt), s, numbercard, numberhand, userinp, match_id);
        
        display(*p1);
        current = current->next;
        
    }
    
    
    
    
    
    
    
    
    
    
    
    return NULL;
    
}
