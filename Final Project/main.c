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
#define TOTAL 22



typedef struct card_s {
char color[10];
int value;
char action[15];
struct card_s *pt;
} card;
typedef struct player_s {
    card player[54];
}player;


//FUNCTION
//-------------------------------------------------------------------------------------------------

void create_deck(card x[], int size); //sets up the deck by initializing the array
void pass_out_card(player p[], card s[]); // pass out 7 cards to player.
void center(card s[]); //center function will displayed the card in the centerline. (Full function is tbd)
void player_draw(card s[], card *ptr); //function that will help get cards from the deck at random order.













//-------------------------------------------------------------------------------------------------
int main(void) {
    
    int usercommand; //user input to determine whether card is loaded from file or not
    
    
    
    printf("Let’s Play a Game of DOS\n");
    
    printf("Press 1 to shuffle the DOS deck or 2 to load a deck from a file:");
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
        int size = 108;
        card deck[108];
        card shuffledeck[108];
        player player_hands[2];
        
       
        create_deck(deck, size); // a function to help initialize the deck
    
        
        
        
         
        printf("The deck is shuffled. Are both players ready to start? (y/n) ");
        scanf(" %c", &userinp);
        while (userinp == 'n') {
            printf("Press y when both players are ready\n");
            scanf(" %c", &userinp);
        }
       
        
        
        printf("Start:\n");
        
        pass_out_card(player_hands, shuffledeck); //pass seven cards to player
        
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

