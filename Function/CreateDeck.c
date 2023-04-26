//
//  CreateDeck.c
//  Final Project
//
//  Created by Man Doan on 4/24/23.
//

#include <stdio.h>
#include <string.h>
#define numcolor 6



typedef struct card_s {
char color[10];
int value;
char action[15];
struct card_s *pt;
} card;
typedef struct color_s {
    char name[15];
}color;


void create_deck(card x[], int size) {
    
    int i,j,k,l,m,n;
    int sizecolor = numcolor;
    color c[sizecolor]; //list for naming color/action cards
    int placehold = 0; //variable that will increment inside for loop
    int counter = 0; //variable used to determine where the index of the array is
    
    
    strcpy(c[0].name, "Yellow");
    strcpy(c[1].name, "Red");
    strcpy(c[2].name, "Green");
    strcpy(c[3].name, "Blue");
    strcpy(c[4].name, "Anycolor");
    strcpy(c[5].name, "Anynumber");
    
    for (i = 0; i < sizecolor - 2; ++i) { //initializing numbered colors
        for (j = 1; j < 11; ++j) {
            if (j == 2) {
                continue;
            }
            
            if (j < 6) {
                placehold = 0;
                for (k = counter; k < 3 + counter; ++k) { //making 3 copies for card number 1-5
                    x[k].value = j;
                    strcpy(x[k].color, c[i].name);
                    strcpy(x[k].action, "None");
                    ++placehold;
                    
                }
                counter = counter + placehold;
                
            }
            
            if (j >= 6) {
                placehold = 0;
                for (k = counter; k < 2 + counter; ++k) {//making 2 copies for card number 6-10
                    x[k].value = j;
                    strcpy(x[k].color, c[i].name);
                    strcpy(x[k].action, "None");
                    ++placehold;
                    
                }
                counter = counter + placehold;//determines where the "x" array is in the list
                
            }
            
        }
    }
    
    for (l = counter ; l < counter + 12; ++l) { //initializing any color card 2
        placehold = 0;
        strcpy(x[l].action, c[4].name);
        strcpy(x[l].color, "Black");
        x[l].value = 2;
        ++placehold;
    }
    counter = counter + 11 + placehold;
    
    //counter = counter - 1;
    for (m = 0; m < sizecolor - 2 ; ++m) { //initializing any number card #
        placehold = 0;
        for (n = counter; n < counter + 2; ++n) {
            strcpy(x[n].color, c[m].name);
            strcpy(x[n].action, "AnyNumber");
            x[n].value = 11;
            ++placehold;
        }
        counter = counter + placehold;
 
    }
   
    
    
    
}
    

