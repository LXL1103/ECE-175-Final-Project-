//
//  main.c
//  Final Project
//
//  Created by Man Doan on 4/21/23.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ncurses.h>
#include <termios.h>            //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>
#include <stdlib.h>

void pressKey(void);

typedef struct card_s {
char color[10];
int value;
char action[15];
struct card_s *pt;
} card;


int main(void) {
    
    int usercommand; //user input to determine whether card is loaded from file or not
    
    
    
    printf("Let’s Play a Game of DOS\n");
    
    printf("Press 1 to shuffle the DOS deck or 2 to load a deck from a file:");
    scanf(" %d", &usercommand);// scans userinput
    
    
   
    
    if ((usercommand != 1) && (usercommand !=2)) { //when usercommand is not 1 or 2
        
        while (usercommand != 1 || usercommand != 2) {
            
            printf("Invalid command\n");
            printf("Press 1 to shuffle the DOS deck or 2 to load a deck from a file:");
            scanf(" %d", &usercommand);
            
            if (usercommand == 1 || usercommand == 2) {
                break;
            }
        }
    }
    
    
    if (usercommand == 1) {
        
        fflush(stdin);
        printf("The deck is shuffled. Press any key to deal cards\n");
        pressKey(); //function to help read input w/out pressing enter (Source: https://stackoverflow.com/questions/1449324/how-to-simulate-press-any-key-to-continue)
        
        printf("start");
        
    
    }
    else if (usercommand == 2) {
        
        
        
        //function to scan file into list
        printf("2");
    }
    
    
    
    
    
    
    
    
    return 0;
}
