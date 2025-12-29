#include <iostream>
#include "game.h"
#include <cstdlib>
#include <conio.h>

using namespace std;

bool continuelevelAsk(int numLevel) {

    char answercontinue;
  

    while (true) {
        
            cout << "Continue to level " << numLevel << "? (Y / N) : ";
            cin >> answercontinue;

        if (answercontinue == 'Y' || answercontinue == 'y') {
            return true;
            break;
        }
        else if (answercontinue == 'N' || answercontinue == 'n') {
            cout << "Thanks for playing!" << endl;
            return false;
        }
        else {
            cout << "I don't understand. Please enter Y or N." << endl;
        }
    }
} //ask user to continue level

void welcomeMsg() {
    cout << "Welcome to Project Orinoco! Please select a game mode (enter the gamemode number e.g. 1):" << endl;
    cout << "1. Main Levels" << endl;
    cout << "2. Custom Levels" << endl;
    cout << "3. Daily Level" << endl;
} //welcome message to the user

void tutorialMessagelvl1() {

    cout << "Welcome to level 1!" << endl;
    cout << "Before starting the game please read through this guide." << endl;
    cout << endl;
    cout << "- To win in Orinoco you have to collect all the coins on the board represented by a '*'" << endl;
    cout << "- Each position on the board is represnted by a '.'" << endl;
    cout << "- You are only able to move one space at a time" << endl;
    cout << "- You have a limited amount of time for each level, if you don't finish, game over (pending...)" << endl;

}

void tutorialMessagelvl2() {

    cout << "Welcome to level 2!" << endl;
    cout << "The following has been added to the game:" << endl;
    cout << "- You now have a maximum speed of 2 which increases whenever you pick up a '+'" << endl;;

}

int main() {

    welcomeMsg();
    
    char gameMode;
    cin >> gameMode;
    system("cls");

    switch (gameMode) {
    case '1': {

        tutorialMessagelvl1();
        cout << endl;
        cout << "Press any key to continue: ";
        char continuemessage1 = _getch();
        cout << endl;

        Player player1;

        player1.tutoriallevel1(player1, 10); //level 1 (10x10, 10 coins)

        if (!continuelevelAsk(2)) return 0;

        system("cls");

        tutorialMessagelvl2();
        cout << endl;
        cout << "Press any key to continue: ";
        char continuemessage3 = _getch();
        cout << endl;

        player1.tutoriallevel2(player1, 10, 5); //level 2 (10x10, 10 coins, 5 powerups) COIN AND POWERUP CAN BE IN SAME TILE SO FIX IT!!!!!

        if (!continuelevelAsk(3)) return 0;

        cout << "Moving on to level 3..." << endl;;
            player1.normallevels(player1, 20, 10, 10); //level 3 (15x15, 20 coins, 10 powerups, 10 removers)


        if (!continuelevelAsk(4)) return 0;

            cout << "Moving on to level 4..." << endl;
            player1.normallevels(player1, 20, 10, 10); //level 4 (same as lvl 3)

            cout << "Thanks for playing!" << endl;

        break;
    }

    case '2': {

        cout << "This gamemode is unavailable...";

        break;
    }

    case '3': {

        Player player1;

        player1.randomDailylevel(player1); //random level (change every 24 hrs pending...)

        break;
    }

    } //switch statement ending

    return 0;
}