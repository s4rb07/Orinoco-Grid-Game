#include <iostream>

using namespace std;

class Player {

    friend ostream& operator<<(ostream& o, const Player& player);

public:

    Player();

    int getXcoordinate() const;
    int getYcoordinate() const;

    int getSpeed() const;
    void MoveUp();
    void MoveDown();
    void MoveRight();
    void MoveLeft();

    int getCoinCount() const;
    void pickupCoin();

    void pickupPowerUp();
    void removePowerUp();

    void tutoriallevel1(Player& player, int needCoins);
    void tutoriallevel2(Player& player, int needCoins, int needPowerups);
    void normallevels(Player& player, int needCoins, int needPowerups, int needPowerupremovers);
    void randomDailylevel(Player& player);

private:

    int Xcoordinate;
    int Ycoordinate;
    int CoinCount;
    int playerSpeed;

};