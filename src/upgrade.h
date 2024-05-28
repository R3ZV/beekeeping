#ifndef UPGRADE_H
#define UPGRADE_H

#include "player.h"

#include <raylib.h>

// using Template Method design pattern
//
// can_purchase and set_prop need
// to be implemented by derivate classes

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

    void purchase(Player& player) const;
    Texture2D get_icon() const;

    virtual int get_price() const;
    virtual bool can_purchase(Player& player) const = 0;
    virtual void set_prop(Player& player) const = 0;

};

class CollectAmountUpgrade : public Upgrade {
public:
    CollectAmountUpgrade(
        int price,
        int upgrades,
        Texture2D icon
    );
    bool can_purchase(Player& player) const;
    void set_prop(Player& player) const;
};

class BackpackUpgrade : public Upgrade {
public:
    BackpackUpgrade(
        int price,
        int upgrades,
        Texture2D icon
    );
    bool can_purchase(Player& player) const;
    void set_prop(Player& player) const;
};

class HoneyPerPollenUpgrade : public Upgrade {
public:
    HoneyPerPollenUpgrade(
        int price,
        int upgrades,
        Texture2D icon
    );
    bool can_purchase(Player& player) const;
    void set_prop(Player& player) const;
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
    bool can_purchase(Player& player) const;
    void set_prop(Player& player) const;
};

#endif // UPGRADE_H
