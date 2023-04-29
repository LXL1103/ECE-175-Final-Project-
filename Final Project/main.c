//
//  main.c
//  Final Project
//
//  Created by Man Doan on 4/21/23.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TOTAL 108




typedef struct card_s {
char color[10];
int value;
char action[15];
struct card_s *pt;
} card;
typedef struct player_s {
    card player[54];
    struct player_s *next;
}player;
typedef struct node_s {
    card player;
    
    struct node_s *next;
    struct node_s *prev;
    
}node;


//FUNCTION
//-------------------------------------------------------------------------------------------------

void create_deck(card x[], int size); //sets up the deck by initializing the array
void shuffledeck(card d[], card s[], int sizeVal); //shuffle deck by randomizing the order and copying it into a shuffle array
node *pass_out_card(node *p, card s[], int *dt); // pass out 7 cards to player.
node *centerline_F(node *c, card s[], int *dt); //a link list for centerline
void display(node *d);//displayer link list


void p_draw(card s[], card *ptr); //function that will help get cards from the deck at random order.





//-------------------------------------------------------------------------------------------------
int main(void) {
    
    int usercommand; //user input to determine whether card is loaded from file or not
    
    
    printf("Let’s Play a Game of DOS\n");
    printf("Press 1 to shuffle the DOS deck or 2 to load a deck from a file: ");
    scanf("%d", &usercommand);// scans userinput
    
    
   
    
    if ((usercommand != 1) && (usercommand !=2)) { //when usercommand is not 1 or 2
        
        while (usercommand != 1 || usercommand != 2) { //while loop that will repeat error message until user type in a valid number. DO NOT type a character as it will go in a infinite loop.
            
            printf("Invalid command\n");
            printf("Press 1 to shuffle the DOS deck or 2 to load a deck from a file:");
            scanf("%d", &usercommand);
            
            if (usercommand == 1 || usercommand == 2) { //breaks out of for loop when user enters a valid input.
                break;
            }
        }
    }
    
    if (usercommand == 1) {
        char userinp;
        int size = TOTAL;
        card deck[size];
        card shuffleD[size]; //shuffle decked array
        int decktrack = 0;
        node * p1 = NULL, * p2 = NULL, *centerline = NULL;// p1 is player 1, p2 is player 2, and centerline are cards at the middle.
        node *current = NULL;
        
        create_deck(deck, size); // a function to help initialize the deck
        
        /*for (int z = 0; z < 108; ++z) {
            printf("%d %s %s %d\n", deck[z].value, deck[z].color, deck[z].action, z);
        }
        */
        
        shuffledeck(deck, shuffleD, size); //shuffle from the deck list
        
        /*
         //For Loop Used for debugging. Prints out ShuffleD array.
        for (int l = 0; l < size; ++l) {
            printf("%d %s %s %d\n", shuffleD[l].value, shuffleD[l].color, shuffleD[l].action, l);
        }
        */
         
        printf("The deck is shuffled. Are both players ready to start? (y/n) ");
        scanf(" %c", &userinp);
        while (userinp == 'n') {
            printf("Press y when both players are ready\n");
            scanf(" %c", &userinp);
        }
       /*
        //Prints shuffledeck 16 times. DEBUGGING PURPOSES
        for (int l = 0; l < 16; ++l) {
            if (l < 7) {
                printf("player 1: %d\n", shuffleD[l].value);
                continue;
            }
            
            else if (l < 14) {
                printf("player 2: %d\n", shuffleD[l].value);
                continue;
            }
            else if (l >=14) {
                printf("centerline: %d\n", shuffleD[l].value);
            }
        }
        */
        
        printf("Start:\n");
        
        p1 = pass_out_card(p1, shuffleD, &decktrack);//deals card to player 1
        
        p2 = pass_out_card(p2, shuffleD, &decktrack);// deals card to player 2
        
        centerline = centerline_F(centerline, shuffleD, &decktrack); //adds card from shuffle deck to centerline as link list
        
        printf("Center: ");
        display(centerline);
        printf("\n");
        
        printf("Player 1 Hand: ");
        display(p1);
        printf("\n");
        
        printf("Player 1 Hand: ");
        display(p2);
        printf("\n");
        
        /*
        //printing out p1/p2/centerline link list. DEBUGGING PURPOSES
        int i = 0;
        current = p1;
        printf("Player 1 \n");
        while(current != NULL) {
            printf("%d\n", current->player.value);
            current = current->next;
            ++i;
            if (i == 50) {
                break;
            }
        }
        i = 0;
        current = p2;
        printf("Player 2 \n");
        while(current != NULL) {
            printf("%d\n", current->player.value);
            current = current->next;
            ++i;
            if (i == 50) {
                break;
            }
        }
        i = 0;
        current = centerline;
        printf("centerline \n");
        while(current != NULL) {
            printf("%d\n", current->player.value);
            current = current->next;
            ++i;
            if (i == 50) {
                break;
            }
        }
        */
        
        
        //while loop for when player1/2 has no card left in their deck or *||||||||||
        
        //a function to store player1's deck, display it, and request action
        
        //a function to display center card (Might be in main or in player1/2 function)
        
        //function to store player2's  deck, display it, and request action
        //                                                                *||||||||||
       
    }
    else if (usercommand == 2) {
       
        
        //function to scan file into list
        printf("2");
        
    }
    return 0;
}
