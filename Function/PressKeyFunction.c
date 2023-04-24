//
//  PressKeyFunction.c
//  Final Project
//
//  Created by Man Doan on 4/23/23.
//

#include <stdio.h>
#include <stdio.h>
#include <ncurses.h>
#include <termios.h>            //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>
#include <stdlib.h>

void pressKey(void)
{
    //the struct termios stores all kinds of flags which can manipulate the I/O Interface
    static struct termios oldt, newt;

    //tcgetattr gets the parameters of the current terminal
    //STDIN_FILENO will tell tcgetattr that it should write the settings
    // of stdin to oldt
    tcgetattr(STDIN_FILENO, &oldt);
    //now the settings will be copied
    newt = oldt;

    //two of the c_lflag will be turned off
    //ECHO which is responsible for displaying the input of the user in the terminal
    //ICANON is the essential one! Normally this takes care that one line at a time will be processed
    //that means it will return if it sees a "\n" or an EOF or an EOL
    newt.c_lflag &= ~(ICANON | ECHO );

    //Those new settings will be set to STDIN
    //TCSANOW tells tcsetattr to change attributes immediately.
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);

    //now the char wil be requested
    getchar();

    //the old settings will be written back to STDIN
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);

}

