#ifndef UPGRADE_H
#define UPGRADE_H

#include "player.h"

#include <raylib.h>

class Upgrade {
    int price;
    int upgrades;
    PlayerUpgrade upgrade_type;
    Texture2D icon;

    int calculate_price(int upgrades) const;
public:
    Upgrade(
        int price,
        int upgrades,
        PlayerUpgrade upgrade_type,
        Texture2D icon
    );
    int get_upgrades() const;
    int get_price() const;
    PlayerUpgrade get_upgrade_type() const;
    Texture2D get_icon() const;
};

#endif // UPGRADE_H
