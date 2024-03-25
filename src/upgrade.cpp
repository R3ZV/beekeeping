#include "upgrade.h"

Upgrade::Upgrade(
    int price,
    int upgrades,
    PlayerUpgrade upgrade_type,
    Texture2D icon
) :
    price(price),
    upgrades(upgrades),
    upgrade_type(upgrade_type),
    icon(icon)
{}

int Upgrade::get_price() const {
    int current_price = price + price * upgrades * upgrades;
    return current_price;
}

int Upgrade::get_upgrades() const {
    return upgrades;
}

PlayerUpgrade Upgrade::get_upgrade_type() const {
    return upgrade_type;
}

Texture2D Upgrade::get_icon() const {
    return icon;
}
