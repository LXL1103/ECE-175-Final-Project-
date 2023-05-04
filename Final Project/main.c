//
//  main.c
//  Final Project
//
//  Created by Man Doan and Emilio Landetta on 4/21/23.
//
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define TOTAL 108




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


//FUNCTION
//-------------------------------------------------------------------------------------------------

void create_deck(card x[], int size); //sets up the deck by initializing the array
void shuffledeck(card d[], card s[], int sizeVal); //shuffle deck by randomizing the order and copying it into a shuffle array
void pass_out_card(node **p, card s[], int *dt); // pass out 7 cards to player.
void pass_out_card_to_centerline(node **p, card s[], int *dt);
void display(node *d);
void scanFDeck(card cardInfo[]);

bool player1Action(node **p1, node **p2, node **c, card s[], int *dt);
bool player2Action(node **p2, node **p1, node **c, card s[], int *dt);

int counter(node *p);

void center(card s[]); //center function will displayed the card in the centerline. (Full function is tbd)
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
        int decktracker = 0;

        card deck[size];
        card shuffleD[size]; //shuffle decked array
        node *player1_Hand = NULL;
        node *player2_Hand= NULL;
        node *centerline = NULL;
        
        bool isPlayer1Empty = false, isPlayer2Empty = false;
        
        
        create_deck(deck, size); // a function to help initialize the deck
        
        /*for (int z = 0; z < 108; ++z) {
         printf("%d %s %s %d\n", deck[z].value, deck[z].color, deck[z].action, z);
         }
         */
        
        shuffledeck(deck, shuffleD, size); //shuffle from the deck list
        
        /*
         //For Loop Used for debugging. Prints out ShuffleD array.
         for (int l = 0; l < 16; ++l) {
         printf("%d %s %s %d\n", shuffleD[l].value, shuffleD[l].color, shuffleD[l].action, l);
         }
         */
        
        printf("The deck is shuffled. Are both players ready to start? (y/n) ");
        scanf(" %c", &userinp);
        while (userinp == 'n') {
            printf("Press y when both players are ready\n");
            scanf(" %c", &userinp);
        }
        
        
        
        printf("Start:\n");
        
        pass_out_card(&player1_Hand, shuffleD, &decktracker); //pass seven cards to player
        //display(player1_Hand);
        
        pass_out_card(&player2_Hand, shuffleD, &decktracker);
        //display(player2_Hand);
        pass_out_card_to_centerline(&centerline, shuffleD, &decktracker);
        
        //display(centerline);
        
        while ((isPlayer1Empty == false) || (isPlayer2Empty == false)) {
            
            isPlayer1Empty = player1Action(&player1_Hand, &player2_Hand, &centerline, shuffleD, &decktracker); //a function to request player 1 action.
            isPlayer2Empty = player2Action(&player2_Hand, &player1_Hand, &centerline, shuffleD, &decktracker);
            
        }
        
        //function to determine the points based on player1 and player 2 hand and who ever has the highest point would return an id number (id = 1 is player 1 and id = 2 is player 2)
        
        
        
        
        
    }
    else if (usercommand == 2) {
        
        //function to scan file into list
                char userinp;
        
                int decktracker = 0;
                card deck[108];
                card shuffleD[108]; //shuffle decked array
                node* player1_Hand = NULL;
                node* player2_Hand = NULL;
                node* centerline = NULL;
                FILE *inp = NULL;;
                int size = 108;

                bool isPlayer1Empty = false, isPlayer2Empty = false;


                scanFDeck(deck); //shuffle from the deck file
                /*
                for (int z = 0; z < 108; ++z) {
                 printf("%d %s %s %d\n", deck[z].value, deck[z].color, deck[z].action, z);
                 }
                 */
                shuffledeck(deck, shuffleD, size);
                

                /*
                 //For Loop Used for debugging. Prints out ShuffleD array.
                 for (int l = 0; l < 16; ++l) {
                 printf("%d %s %s %d\n", shuffleD[l].value, shuffleD[l].color, shuffleD[l].action, l);
                 }
                 */

                printf("The deck is shuffled. Are both players ready to start? (y/n) ");
                scanf(" %c", &userinp);
                while (userinp == 'n') {
                    printf("Press y when both players are ready\n");
                    scanf(" %c", &userinp);
                }
                pass_out_card(&player1_Hand, shuffleD, &decktracker); //pass seven cards to player
        //display(player1_Hand);
        
                pass_out_card(&player2_Hand, shuffleD, &decktracker);
        //display(player2_Hand);
                pass_out_card_to_centerline(&centerline, shuffleD, &decktracker);


                printf("Start:\n");

                pass_out_card(&player1_Hand, shuffleD, &decktracker); //pass seven cards to player
                //display(player1_Hand);

                pass_out_card(&player2_Hand, shuffleD, &decktracker);
                //display(player2_Hand);
                pass_out_card_to_centerline(&centerline, shuffleD, &decktracker);

                //display(centerline);

                while ((isPlayer1Empty == false) || (isPlayer2Empty == false)) {
                    /*
                    printf("Centerline: ");
                    display(centerline);

                    printf("Player 1 Hand: ");
                    display(player1_Hand);
                     */
                    isPlayer1Empty = player1Action(&player1_Hand, &player2_Hand, &centerline, shuffleD, &decktracker);



                }


               


            }
        
        
        
    }


