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
#include <stdbool.h>
#include <unistd.h>
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
}node;


//FUNCTION
//-------------------------------------------------------------------------------------------------

void create_deck(card x[], int size); //sets up the deck by initializing the array
void shuffledeck(card d[], card s[], int sizeVal); //shuffle deck by randomizing the order and copying it into a shuffle array
//node *pass_out_card(node *p, card s[], int *dt); // pass out 7 cards to player.
void pass_out_card(node **p, card s[], int *dt);
void centerline_F(node **c, card s[], int *dt); //a link list for centerline
void display(node *d);//displayer link list
void ereaseinp(card userinp[]);
void getuserplay(card s[], int num);



node *addcard(node *p, card s[]); //function to add card to a link list (p1/p2/centerline)
bool isPlayerHandEmpty(node *p); //function to check if player's hand is empty
bool match_input_to_list(node *p, card userinp[], int size);










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
        int decktrack = 0;
        int sleepseconds = 3000; //in miliseconds
        int numbercard = 0;
        int noplaycounter = 0;
        //int id; //if id = 1; Player1. if id = 2; Player2. if id = 3; Center.
        
        card deck[size];
        card shuffleD[size]; //shuffle decked array
        card usercardinp[10];
        
       
        node * p1 = NULL, *p2 = NULL, *centerline = NULL;// p1 is player 1, p2 is player 2, and centerline are cards at the middle.
        node *current = NULL;
        
        bool isPlayer1Empty = false, isPlayer2Empty = false;
        bool islistMatch1 = false;
        
        
        create_deck(deck, size); // a function to help initialize the deck
        
        /*for (int z = 0; z < 108; ++z) {
            printf("%d %s %s %d\n", deck[z].value, deck[z].color, deck[z].action, z);
        }
        */
        
        shuffledeck(deck, shuffleD, size); //shuffle from the deck list
        
        
         //For Loop Used for debugging. Prints out ShuffleD array.
        for (int l = 0; l < 16; ++l) {
            printf("%d %s %s %d\n", shuffleD[l].value, shuffleD[l].color, shuffleD[l].action, l);
        }
        
         
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
        
        printf("Dealing 7 cards to both players...\n\n");
        //sleep(3); //delays compile time for 3 second to simulate loading into the game
        
        pass_out_card(&p1, shuffleD, &decktrack);//deals card to player 1
        
        
        pass_out_card(&p2, shuffleD, &decktrack);// deals card to player 2
        
        centerline_F(&centerline, shuffleD, &decktrack); //adds card from shuffle deck to centerline as link list
        
        
        /*
        printf("Player 1 Hand: ");
        display(p1);
        printf("\n");
        
        
        printf("Player 2 Hand: ");
        display(p2);
        printf("\n");
        
        printf("Center: ");
        display(centerline);
        printf("\n");
        */
        
        //printing out p1/p2/centerline link list. DEBUGGING PURPOSES
        /*
        int i = 0;
         
        current = p1; //change to p1/p2/centerline
        printf("Player 1 \n");
        while(current != NULL) {
            printf("%d\n", current->player.value);
            current = current->next;
            ++i;
            if (i == 50) {
                break;
            }
        }
        */
        
        while ((isPlayer1Empty == false) || (isPlayer2Empty == false)) {
            current = centerline;
            printf("Centerline: ");
            display(centerline);
            printf("\n\n");
            
            printf("Player 1 Hand : ");
            display(p1);
            printf("\n\n");
            
            
            while (islistMatch1 == false) { //gets user input and determine if userinput exist in player's hand
                
                printf("How many cards do you want to play on %s %d %s (Type value between 1-10): ",current->player.color ,current->player.value, current->player.action);
                scanf("%d", &numbercard);
                printf("\n");
                
                if (numbercard == 0) {//Press Zero when no cards can be played and it will proceed to the next section in centerline
                    current = current->next;
                    if (current == NULL) {
                        break;
                    }
                    continue;
                }
                while (numbercard > 10) { //placed in a loop until user input is in range between 1-10
                    printf("Invalid, try again.\n\n");
                    printf("How many cards do you want to play on %s %d %s (Type value between 1-10): ",current->player.color ,current->player.value, current->player.action);
                    scanf("%d", &numbercard);
                }
                 
                ereaseinp(usercardinp);//ereases previous input
                getuserplay(usercardinp, numbercard); //gets user to type in card they want to play
                
                islistMatch1 = match_input_to_list(p1, usercardinp, numbercard); // checks if typed in card matches whats on player's hand
                
                if (islistMatch1 == false) {//Error message for when user types in invalid input.
                    printf("\n\n");
                    printf("Invalid, Please make sure both spelling, capatilization, and order is typed correctly\n\n");
                }
            }
            
            
            
            
           
            if (decktrack == 107) { //when deck is exhausted, if statement will execute to determine points from player hand
                
                //function to count player1/2 points and determine who has the most point
                break;
            }
         
        }
       
        
        
        
        //Make sure to use free function after game is completed.
       
    }
    else if (usercommand == 2) {
       
        
        //function to scan file into list
        printf("2");
        
        
        
        //make sure to add free function and fclose
        
    }
    return 0;
}
