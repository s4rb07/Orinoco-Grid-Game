#include "game.h"
#include <iostream>
#include <chrono>
#include "attachments.h"

using namespace std;
using namespace std::chrono;

void Player::randomDailylevel(Player& player) {

    srand(time(nullptr));

    Player player1;
    int gridSize = rand() % 11 + 5;

    int numCoins = gridSize;
    Coin* coinarray = new Coin[numCoins];

    int numPowerups = rand() % 5 + 1;
    PowerUp* poweruparray = new PowerUp[numPowerups];

    int numPowerupRemovers = numPowerups;
    PowerUpRemover* powerupremoverarray = new PowerUpRemover[numPowerupRemovers];

    int min = 0;

        for (int i = 0; i < numCoins; i++) {

            int x = rand() % numCoins;
            int y = rand() % numCoins;
            coinarray[i] = Coin(x, y);

        }

    for (int i = 0; i < 2; i++) {

        int x = rand() % 10;
        int y = rand() % 10;
        poweruparray[i] = PowerUp(x, y);

    }

    for (int i = 0; i < numPowerupRemovers; i++) {

        int x = rand() % 10;
        int y = rand() % 10;
        powerupremoverarray[i] = PowerUpRemover(x, y);

    }

    auto start = steady_clock::now();

    while (player1.getCoinCount() < numCoins) {

        cout << "Choose a move:" << endl;
        cout << "W. Move up" << endl;
        cout << "S. Move down" << endl;
        cout << "A. Move left" << endl;
        cout << "D. Move right" << endl;

        cout << "Your position is: " << player1 << endl;
        cout << "Your speed is: " << player1.getSpeed() << endl;
        cout << "Your total coins collected: " << player1.getCoinCount() << endl;

        cout << "Coin positions: ";
        for (int i = 0; i < numCoins; i++) {
            if (coinarray[i].getCoinXcoordinate() != -1 && coinarray[i].getCoinYcoordinate() != -1) {

                cout << "(" << coinarray[i].getCoinXcoordinate() << ", " << coinarray[i].getCoinYcoordinate() << ") ";

            }
        }

        cout << "\nPowerup positions: ";
        for (int i = 0; i < numPowerups; i++) {
            if (poweruparray[i].getPowerUpXcoordinate() != -1 && poweruparray[i].getPowerUpYcoordinate() != -1) {

                cout << "(" << poweruparray[i].getPowerUpXcoordinate() << ", " << poweruparray[i].getPowerUpYcoordinate()
                    << ") ";

            }
        }

        cout << "\nPowerup Remover positions: ";
        for (int i = 0; i < 2; i++) {
            if (powerupremoverarray[i].getPowerUpRemoverXCoordinate() != -1 &&
                powerupremoverarray[i].getPowerUpRemoverYCoordinate() != -1) {

                cout << "(" << powerupremoverarray[i].getPowerUpRemoverXCoordinate() << ", "
                    << powerupremoverarray[i].getPowerUpRemoverYCoordinate() << ") ";

            }
        }

        cout << "\nEnter move: ";
        char choice;
        cin >> choice;

        int move = player1.getSpeed();
        for (int i = 0; i < move; i++) {

            switch (choice) {
            case 'A':
            case 'a':
                if (player1.getXcoordinate() - 1 >= min) {
                    player1.MoveLeft();
                }
                break;
            case 'W':
            case 'w':
                if (player1.getYcoordinate() + 1 <= gridSize)
                    player1.MoveUp();
                break;
            case 'S':
            case 's':
                if (player1.getYcoordinate() - 1 >= min) {
                    player1.MoveDown();
                }
                break;
            case 'D':
            case 'd':
                if (player1.getXcoordinate() + 1 <= gridSize) {
                    player1.MoveRight();
                }
                break;
            default:
                cout << "Sorry, I don't understand." << endl;

            }

            for (int i = 0; i < numCoins; i++) {
                if (player1.getXcoordinate() == coinarray[i].getCoinXcoordinate() &&
                    player1.getYcoordinate() == coinarray[i].getCoinYcoordinate()) {
                    player1.pickupCoin();
                    coinarray[i] = Coin(-1, -1);

                }
            }

            for (int i = 0; i < numPowerups; i++) {
                if (player1.getXcoordinate() == poweruparray[i].getPowerUpXcoordinate() &&
                    player1.getYcoordinate() == poweruparray[i].getPowerUpYcoordinate()) {

                    player1.pickupPowerUp();
                    poweruparray[i] = PowerUp(-1, -1);

                }
            }

            for (int i = 0; i < numPowerupRemovers; i++) {
                if (player1.getXcoordinate() == powerupremoverarray[i].getPowerUpRemoverXCoordinate() &&
                    player1.getYcoordinate() == powerupremoverarray[i].getPowerUpRemoverYCoordinate() &&
                    player1.getSpeed() > 1) {

                    player1.removePowerUp();
                    powerupremoverarray[i] = PowerUpRemover(-1, -1);

                }
            }
        }
    }

    auto end = steady_clock::now();
    auto totalTime = duration_cast<seconds>(end - start).count();

    cout << "Victory!" << endl;
    cout << "You finished this level in " << totalTime << " seconds!" << endl;

    delete[] coinarray;
    delete[] poweruparray;
    delete[] powerupremoverarray;

}