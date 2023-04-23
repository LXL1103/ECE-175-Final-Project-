//
//  main.c
//  Final Project
//
//  Created by Man Doan on 4/21/23.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct card_s {
char color[10];
int value;
char action[15];
struct card_s *pt;
} card;


int main(int argc, const char * argv[]) {
    
    int usercommand; //user input to determine whether card is loaded from file or not
    
    
    
    printf("Let’s Play a Game of DOS\n");
    
    printf("Press 1 to shuffle the DOS deck or 2 to load a deck from a file: \n");
    scanf("%d", &usercommand);// scans userinput
    
    
   
    
    if (usercommand != 1 || usercommand != 2) { //when usercommand is not 1 or 2
        
        
        while ((usercommand != 1) || (usercommand != 2)) {
            
            printf("Invalid command\n");
            printf("Press 1 to shuffle the DOS deck or 2 to load a deck from a file: ");
            scanf(" %d", &usercommand);
            
            if (usercommand == 1 || usercommand == 2) {
                break;
            }
            
        }
        
        
    }
    
    if (usercommand == 1) {
        int anykeynum;
        int anykeyletter;
        
        
        // function to load and shuffle deck
        printf("The deck is shuffled. Press any key to deal cards");
        scanf("%d %c", &anykeynum, &anykeyletter);
        
        if
        
        
        
        
        
        
        
        
    }
    else if (usercommand == 2) {
        
        
        
        //function to scan file into list
        
    }
    
    
    
    
    
    
    
    
    return 0;
}
