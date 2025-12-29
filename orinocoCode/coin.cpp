#include <iostream>
#include "attachments.h"

int Coin::getCoinXcoordinate() const {

    return coinXcoordinate;

}

int Coin::getCoinYcoordinate() const {

    return coinYcoordinate;

}

int PowerUp::getPowerUpYcoordinate() const {

    return powerupYcoordinate;

}

int PowerUp::getPowerUpXcoordinate() const {

    return powerupXcoordinate;

}

Coin::Coin(int x, int y) {

    coinXcoordinate = x;
    coinYcoordinate = y;

}

PowerUp::PowerUp(int x, int y) {

    powerupXcoordinate = x;
    powerupYcoordinate = y;

}

Coin::Coin() {

    coinXcoordinate = -1;
    coinYcoordinate = -1;

}

PowerUp::PowerUp() {

    powerupXcoordinate = -1;
    powerupYcoordinate = -1;

}

int PowerUpRemover::getPowerUpRemoverXCoordinate() const {

    return powerupremoverXcoordinate;

}

int PowerUpRemover::getPowerUpRemoverYCoordinate() const {

    return powerupremoverYcoordinate;

}

PowerUpRemover::PowerUpRemover() {

    powerupremoverXcoordinate = -1;
    powerupremoverYcoordinate = -1;

}

PowerUpRemover::PowerUpRemover(int x, int y) {

    powerupremoverXcoordinate = x;
    powerupremoverYcoordinate = y;

}