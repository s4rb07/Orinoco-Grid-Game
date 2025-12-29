#include "game.h"
#include <chrono>
#include "attachments.h"
#include <cstdlib>
#include <conio.h>

using namespace std::chrono;

Player::Player() {

    Xcoordinate = 0;
    Ycoordinate = 0;
    CoinCount = 0;
    playerSpeed = 1;

}

void Player::MoveUp() {

    Ycoordinate += 1;

}

void Player::MoveDown() {

    Ycoordinate -= 1;

}

void Player::MoveRight() {

    Xcoordinate += 1;

}

void Player::MoveLeft() {

    Xcoordinate -= 1;

}

int Player::getXcoordinate() const {

    return Xcoordinate;

}

int Player::getYcoordinate() const {

    return Ycoordinate;

}

int Player::getSpeed() const {

    return playerSpeed;

}

void Player::pickupCoin() {

    CoinCount++;

}

void Player::pickupPowerUp() {

    playerSpeed *= 2;

}

void Player::removePowerUp() {

    playerSpeed /= 2;

}

int Player::getCoinCount() const {

    return CoinCount;

}

ostream& operator<<(ostream& o, const Player& player) {

    o << "(" << player.Xcoordinate << ", " << player.Ycoordinate << ")";
    return o;

}

void Player::tutoriallevel1(Player& player, int needCoins) {

    srand(time(nullptr));

    Player player1;
    Coin coins[10];

    int min = 0;

    for (int i = 0; i < needCoins; i++) {

        int x = rand() % 9;
        int y = rand() % 9;
        coins[i] = Coin(x, y);

    }

    auto start = steady_clock::now();

    while (player1.getCoinCount() < needCoins) {

        cout << "Choose a move:" << endl;
        cout << "W. Move up" << endl;
        cout << "S. Move down" << endl;
        cout << "A. Move left" << endl;
        cout << "D. Move right" << endl;
        cout << endl;
        cout << "Your speed is: " << player1.getSpeed() << endl;
        cout << "Your total coins collected: " << player1.getCoinCount() << endl;

        int sizeofGrid = 10;
        char gridVisual[10][10];

        for (int i = 0; i < sizeofGrid; i++) {
            for (int j = 0; j < sizeofGrid; j++) {

                gridVisual[i][j] = '.';

            }
        }

        for (int i = 0; i < needCoins; i++) {
            int xCoincoordinate = coins[i].getCoinXcoordinate();
            int yCoincoordinate = coins[i].getCoinYcoordinate();

            if (xCoincoordinate < sizeofGrid && yCoincoordinate < sizeofGrid && xCoincoordinate >= 0 && yCoincoordinate >= 0) {
                gridVisual[yCoincoordinate][xCoincoordinate] = '*';
            }
        }

        int xPlayercoordinate = player1.getXcoordinate();
        int yPlayercoordinate = player1.getYcoordinate();
        if (xPlayercoordinate >= 0 && yPlayercoordinate >= 0 && xPlayercoordinate < sizeofGrid && yPlayercoordinate < sizeofGrid) {
            gridVisual[yPlayercoordinate][xPlayercoordinate] = 'P';
        }

        cout << "\nGame Grid: " << endl;
        for (int i = sizeofGrid - 1; i >= 0; i--) {
            for (int j = 0; j < sizeofGrid; j++) {
                cout << gridVisual[i][j] << ' ';
            }
            cout << endl;
        }

        cout << "\nEnter move: ";
        char choice = _getch();

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
                if (player1.getYcoordinate() + 1 < sizeofGrid)
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
                if (player1.getXcoordinate() + 1 < sizeofGrid) {
                    player1.MoveRight();
                }
                break;
            default:
                cout << "Sorry, I don't understand." << endl;

            }

            for (int i = 0; i < needCoins; i++) {
                if (player1.getXcoordinate() == coins[i].getCoinXcoordinate() &&
                    player1.getYcoordinate() == coins[i].getCoinYcoordinate()) {
                    player1.pickupCoin();
                    coins[i] = Coin(-1, -1);

                }
            }

        }

        system("cls");

    }

    auto end = steady_clock::now();
    auto totalTime = duration_cast<seconds>(end - start).count();

    cout << "Victory!" << endl;
    cout << "You finished this level in " << totalTime << " seconds!" << endl;

}

void Player::tutoriallevel2(Player& player, int needCoins, int needPowerups) {

    srand(time(nullptr));

    Player player1;
    Coin coins[10];
    PowerUp powerups[5];

    int min = 0;

    for (int i = 0; i < needCoins; i++) {

        int x = rand() % 9;
        int y = rand() % 9;
        coins[i] = Coin(x, y);

    }

    for (int i = 0; i < needPowerups; i++) {

        int x = rand() % 9;
        int y = rand() % 9;
        powerups[i] = PowerUp(x, y);

    }

    auto start = steady_clock::now();

    while (player1.getCoinCount() < needCoins) {

        cout << "Choose a move:" << endl;
        cout << "W. Move up" << endl;
        cout << "S. Move down" << endl;
        cout << "A. Move left" << endl;
        cout << "D. Move right" << endl;
        cout << endl;
        cout << "Your speed is: " << player1.getSpeed() << endl;
        cout << "Your total coins collected: " << player1.getCoinCount() << endl;

        int sizeofGrid = 10;
        char gridVisual[10][10];

        for (int i = 0; i < sizeofGrid; i++) {
            for (int j = 0; j < sizeofGrid; j++) {

                gridVisual[i][j] = '.';

            }
        }

        for (int i = 0; i < needCoins; i++) {
            int xCoincoordinate = coins[i].getCoinXcoordinate();
            int yCoincoordinate = coins[i].getCoinYcoordinate();

            if (xCoincoordinate < sizeofGrid && yCoincoordinate < sizeofGrid && xCoincoordinate >= 0 && yCoincoordinate >= 0) {
                gridVisual[yCoincoordinate][xCoincoordinate] = '*';
            }
        }

        for (int i = 0; i < needPowerups; i++) {
            int xPowerupcoordinate = powerups[i].getPowerUpXcoordinate();
            int yPowerupcoordinate = powerups[i].getPowerUpYcoordinate();

            if (xPowerupcoordinate < sizeofGrid && yPowerupcoordinate < sizeofGrid && xPowerupcoordinate >= 0 && yPowerupcoordinate >= 0) {
                gridVisual[yPowerupcoordinate][xPowerupcoordinate] = '+';
            }
        }

        int xPlayercoordinate = player1.getXcoordinate();
        int yPlayercoordinate = player1.getYcoordinate();
        if (xPlayercoordinate >= 0 && yPlayercoordinate >= 0 && xPlayercoordinate < sizeofGrid && yPlayercoordinate < sizeofGrid) {
            gridVisual[yPlayercoordinate][xPlayercoordinate] = 'P';
        }

        

        cout << "\nGame Grid: " << endl;
        for (int i = sizeofGrid - 1; i >= 0; i--) {
            for (int j = 0; j < sizeofGrid; j++) {
                cout << gridVisual[i][j] << ' ';
            }
            cout << endl;
        }

        cout << "\nEnter move: ";
        char choice = _getch();

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
                if (player1.getYcoordinate() + 1 < sizeofGrid)
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
                if (player1.getXcoordinate() + 1 < sizeofGrid) {
                    player1.MoveRight();
                }
                break;
            default:
                cout << "Sorry, I don't understand." << endl;

            }

            for (int i = 0; i < needCoins; i++) {
                if (player1.getXcoordinate() == coins[i].getCoinXcoordinate() &&
                    player1.getYcoordinate() == coins[i].getCoinYcoordinate()) {
                    player1.pickupCoin();
                    coins[i] = Coin(-1, -1);

                }
            }

            for (int i = 0; i < needPowerups; i++) {
                if (player1.getXcoordinate() == powerups[i].getPowerUpXcoordinate() &&
                    player1.getYcoordinate() == powerups[i].getPowerUpYcoordinate()) {

                    if (player1.getSpeed() == 1) {
                        player1.pickupPowerUp();
                        powerups[i] = PowerUp(-1, -1);
                    }
                    else {
                        powerups[i] = PowerUp(-1, -1);
                    }
                }
            }

        }

        system("cls");

    }

    auto end = steady_clock::now();
    auto totalTime = duration_cast<seconds>(end - start).count();

    cout << "Victory!" << endl;
    cout << "You finished this level in " << totalTime << " seconds!" << endl;

}

void Player::normallevels(Player&, int needCoins, int needPowerups, int needPowerupremovers) {

    srand(time(nullptr));

    Player player1;
    Coin coins[20];
    PowerUp powerups[10];
    PowerUpRemover powerupremover[10];

    int min = 0;

    for (int i = 0; i < needCoins; i++) {

        int x = rand() % 14;
        int y = rand() % 14;
        coins[i] = Coin(x, y);

    }

    for (int i = 0; i < needPowerups; i++) {

        int x = rand() % 14;
        int y = rand() % 14;
        powerups[i] = PowerUp(x, y);

    }

    for (int i = 0; i < needPowerupremovers; i++) {

        int x = rand() % 14;
        int y = rand() % 14;
        powerupremover[i] = PowerUpRemover(x, y);

    }

    auto start = steady_clock::now();

    while (player1.getCoinCount() < needCoins) {

        cout << "Choose a move:" << endl;
        cout << "W. Move up" << endl;
        cout << "S. Move down" << endl;
        cout << "A. Move left" << endl;
        cout << "D. Move right" << endl;
        cout << endl;
        cout << "Your speed is: " << player1.getSpeed() << endl;
        cout << "Your total coins collected: " << player1.getCoinCount() << endl;


        int sizeofGrid = 15;
        char gridVisual[15][15];

        for (int i = 0; i < sizeofGrid; i++) {
            for (int j = 0; j < sizeofGrid; j++) {

                gridVisual[i][j] = '.';

            }
        }

        for (int i = 0; i < needCoins; i++) {
            int xCoincoordinate = coins[i].getCoinXcoordinate();
            int yCoincoordinate = coins[i].getCoinYcoordinate();

            if (xCoincoordinate < sizeofGrid && yCoincoordinate < sizeofGrid && xCoincoordinate >= 0 && yCoincoordinate >= 0) {
                gridVisual[yCoincoordinate][xCoincoordinate] = '*';
            }
        }

        for (int i = 0; i < needPowerups; i++) {
            int xPowerupcoordinate = powerups[i].getPowerUpXcoordinate();
            int yPowerupcoordinate = powerups[i].getPowerUpYcoordinate();

            if (xPowerupcoordinate < sizeofGrid && yPowerupcoordinate < sizeofGrid && xPowerupcoordinate >= 0 && yPowerupcoordinate >= 0) {
                gridVisual[yPowerupcoordinate][xPowerupcoordinate] = '+';
            }
        }

        for (int i = 0; i < needPowerupremovers; i++) {
            int xPowerupremovercoordinate = powerupremover[i].getPowerUpRemoverXCoordinate();
            int yPowerupremovercoordinate = powerupremover[i].getPowerUpRemoverYCoordinate();

            if (xPowerupremovercoordinate < sizeofGrid && yPowerupremovercoordinate < sizeofGrid && xPowerupremovercoordinate >= 0 && yPowerupremovercoordinate >= 0) {
                gridVisual[yPowerupremovercoordinate][xPowerupremovercoordinate] = '-';
            }
        }

        int xPlayercoordinate = player1.getXcoordinate();
        int yPlayercoordinate = player1.getYcoordinate();
        if (xPlayercoordinate >= 0 && yPlayercoordinate >= 0 && xPlayercoordinate < sizeofGrid && yPlayercoordinate < sizeofGrid) {
            gridVisual[yPlayercoordinate][xPlayercoordinate] = 'P';
        }

        cout << "\nGame Grid: " << endl;
        for (int i = sizeofGrid - 1; i >= 0; i--) {
            for (int j = 0; j < sizeofGrid; j++) {
                cout << gridVisual[i][j] << ' ';
            }
            cout << endl;
        }

        cout << "\nEnter move: ";
        char choice = _getch();

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
                if (player1.getYcoordinate() + 1 < sizeofGrid)
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
                if (player1.getXcoordinate() + 1 < sizeofGrid) {
                    player1.MoveRight();
                }
                break;
            default:
                cout << "Sorry, I don't understand." << endl;

            }

            for (int i = 0; i < needCoins; i++) {
                if (player1.getXcoordinate() == coins[i].getCoinXcoordinate() &&
                    player1.getYcoordinate() == coins[i].getCoinYcoordinate()) {
                    player1.pickupCoin();
                    coins[i] = Coin(-1, -1);

                }
            }

            for (int i = 0; i < needPowerups; i++) {
                if (player1.getXcoordinate() == powerups[i].getPowerUpXcoordinate() &&
                    player1.getYcoordinate() == powerups[i].getPowerUpYcoordinate()) {

                    if (player1.getSpeed() == 1) {
                        player1.pickupPowerUp();
                        powerups[i] = PowerUp(-1, -1);
                    }
                    else {
                        powerups[i] = PowerUp(-1, -1);
                    }

                }
            }

            for (int i = 0; i < needPowerupremovers; i++) {
                if (player1.getXcoordinate() == powerupremover[i].getPowerUpRemoverXCoordinate() &&
                    player1.getYcoordinate() == powerupremover[i].getPowerUpRemoverYCoordinate() &&
                    player1.getSpeed() > 1) {

                    if (player1.getSpeed() == 2 || player1.getSpeed() == 4) {
                        player1.removePowerUp();
                        powerupremover[i] = PowerUpRemover(-1, -1);
                    }
                    else {
                        powerupremover[i] = PowerUpRemover(-1, -1);
                    }

                }
            }
        }

        system("cls");

    }

    auto end = steady_clock::now();
    auto totalTime = duration_cast<seconds>(end - start).count();

    cout << "Victory!" << endl;
    cout << "You finished this level in " << totalTime << " seconds!" << endl;

}

//grid = . ; coin = * ; powerup = + ; powerup remover = - ;