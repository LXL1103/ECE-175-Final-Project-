//
//  ShuffleDeck.c
//  Final Project
//
//  
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


typedef struct card_s {
char color[10];
int value;
char action[15];
struct card_s *pt;
} card;

void shuffledeck(card d[], card s[], int sizeVal) {
    
    //sizeVal is defined as the total number of card

    int j;
    int k = 0;
    int l;

    

    for (l = 0; l < sizeVal; l++) { //initializing the shuffle array to 999 to help identify if the array is empty later in the code
        s[l].value = 999;
    }
    
    
    
    srand((unsigned int)time(0)); //makes sure the rand function will generate a different number every time the code is run
    
    while (k < sizeVal) { //initialize the deck array into the shuffle array and will exit while loop until all the card from deck array is loaded into shuffle array
    
        j = rand() % sizeVal; //generate random number from 0-107.
    
        if (s[j].value == 999) { //checks if the shuffle array is empty or not
            s[j] = d[k];
            ++k;
        }
    }
    
    /* For Loop used for printing out the s[] array; for debugging purposes.
    for (l = 0; l < sizeVal; ++l) {
        printf("%d %s %s %d\n", s[l].value, s[l].color, s[l].action, l);
    }
 */
    
}
