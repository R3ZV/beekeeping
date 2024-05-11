#ifndef UPGRADE_H
#define UPGRADE_H

#include "player.h"

#include <raylib.h>

class Upgrade {
protected:
    int price;
    int get_upgrades() const;
private:
    int calculate_price(int upgrades) const;
    int upgrades;
    Texture2D icon;
public:
    Upgrade(
        int price,
        int upgrades,
        Texture2D icon
    );
    Texture2D get_icon() const;

    virtual int get_price() const;
    virtual void purchase(Player& player) const = 0;
};

class CollectAmountUpgrade : public Upgrade {
public:
    CollectAmountUpgrade(
        int price,
        int upgrades,
        Texture2D icon
    );
    void purchase(Player& player) const;
};

class BackpackUpgrade : public Upgrade {
public:
    BackpackUpgrade(
        int price,
        int upgrades,
        Texture2D icon
    );
    void purchase(Player& player) const;
};

class HoneyPerPollenUpgrade : public Upgrade {
public:
    HoneyPerPollenUpgrade(
        int price,
        int upgrades,
        Texture2D icon
    );
    void purchase(Player& player) const;
};

class BeeUpgrade : public Upgrade {
    int red_bees;
    int blue_bees;
    int white_bees;
public:
    BeeUpgrade(
        int price,
        int upgrades,
        Texture2D icon,
        int red_bees,
        int blue_bees,
        int white_bees
    );
    virtual int get_price() const;
    void purchase(Player& player) const;
};

#endif // UPGRADE_H
