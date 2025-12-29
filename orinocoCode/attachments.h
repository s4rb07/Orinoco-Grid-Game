#include <iostream>

using namespace std;

class Coin {

public:

    Coin();
    Coin(int x, int y);

    int getCoinXcoordinate() const;
    int getCoinYcoordinate() const;

private:

    int coinXcoordinate;
    int coinYcoordinate;

};

class PowerUp {

public:

    PowerUp();
    PowerUp(int x, int y);

    int getPowerUpXcoordinate() const;
    int getPowerUpYcoordinate() const;

private:

    int powerupXcoordinate;
    int powerupYcoordinate;

};

class PowerUpRemover {

public:

    PowerUpRemover();
    PowerUpRemover(int x, int y);

    int getPowerUpRemoverXCoordinate() const;
    int getPowerUpRemoverYCoordinate() const;

private:

    int powerupremoverXcoordinate;
    int powerupremoverYcoordinate;

};