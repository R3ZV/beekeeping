#ifndef UPGRADE_H
#define UPGRADE_H

#include "player.h"

#include <raylib.h>

class Upgrade {
    int price;
    int upgrades;
    Texture2D icon;

    int calculate_price(int upgrades) const;
public:
    Upgrade(
        int price,
        int upgrades,
        Texture2D icon
    );
    int get_upgrades() const;
    int get_price() const;
    Texture2D get_icon() const;

    virtual void purchase(Player& player) const = 0;
};

class CollectAmountUpgrade : public Upgrade {
public:
    using Upgrade::Upgrade;
    void purchase(Player& player) const;
};

class BackpackUpgrade : public Upgrade {
public:
    using Upgrade::Upgrade;
    void purchase(Player& player) const;
};

class HoneyPerPollenUpgrade : public Upgrade {
public:
    using Upgrade::Upgrade;
    void purchase(Player& player) const;
};

class BeeUpgrade : public Upgrade {
public:
    using Upgrade::Upgrade;
    void purchase(Player& player) const;
};

#endif // UPGRADE_H
