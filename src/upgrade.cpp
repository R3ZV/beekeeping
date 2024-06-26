#include "upgrade.h"
#include <random>

Upgrade::Upgrade(
    int price,
    int upgrades,
    Texture2D icon
) :
    price(price),
    upgrades(upgrades),
    icon(icon)
{}

void Upgrade::purchase(Player& player) const {
    if (can_purchase(player)) {
        set_prop(player);
    }
}

CollectAmountUpgrade::CollectAmountUpgrade(
    int price,
    int upgrades,
    Texture2D icon
) :
    Upgrade(price, upgrades, icon)
{}

BackpackUpgrade::BackpackUpgrade(
    int price,
    int upgrades,
    Texture2D icon
) :
    Upgrade(price, upgrades, icon)
{}

HoneyPerPollenUpgrade::HoneyPerPollenUpgrade(
    int price,
    int upgrades,
    Texture2D icon
) :
    Upgrade(price, upgrades, icon)
{}

BeeUpgrade::BeeUpgrade(
    int price,
    int upgrades,
    Texture2D icon,
    int red_bees,
    int blue_bees,
    int white_bees

) :
    Upgrade(price, upgrades, icon),
    red_bees(red_bees),
    blue_bees(blue_bees),
    white_bees(white_bees)
{}

int Upgrade::get_price() const {
    int current_price = price + price * upgrades * upgrades;
    return current_price;
}

int Upgrade::get_upgrades() const {
    return upgrades;
}

Texture2D Upgrade::get_icon() const {
    return icon;
}

bool CollectAmountUpgrade::can_purchase(Player& player) const {
    return player.get_honey() >= get_price() && get_upgrades() < player.get_max_upgrades();
}

void CollectAmountUpgrade::set_prop(Player& player) const {
    player.set_honey(player.get_honey() - get_price());
    player.set_collect_amount_upgrades(get_upgrades() + 1);
}

bool BackpackUpgrade::can_purchase(Player& player) const {
    return player.get_honey() >= get_price() && get_upgrades() < player.get_max_upgrades();
}

void BackpackUpgrade::set_prop(Player& player) const {
    player.set_honey(player.get_honey() - get_price());
    player.set_backpack_upgrades(get_upgrades() + 1);
}

bool HoneyPerPollenUpgrade::can_purchase(Player& player) const {
    return player.get_honey() >= get_price() && get_upgrades() < player.get_max_upgrades();
}

void HoneyPerPollenUpgrade::set_prop(Player& player) const {
    player.set_honey(player.get_honey() - get_price());
    player.set_honey_per_pollen_upgrades(get_upgrades() + 1);
}


int BeeUpgrade::get_price() const {
    int upgrades = get_upgrades();
    int current_price = price + price * upgrades * upgrades * upgrades / 2;
    return current_price;
}

bool BeeUpgrade::can_purchase(Player& player) const {
    return player.get_honey() >= get_price() && get_upgrades() < player.get_max_upgrades();
}

void BeeUpgrade::set_prop(Player& player) const {
    player.set_honey(player.get_honey() - get_price());

    std::random_device generator;
    int left_type = 0, right_type = 2;
    if (red_bees > blue_bees && red_bees > white_bees) {
        left_type = 1;
    }

    if (white_bees > blue_bees && white_bees > red_bees) {
        right_type = 1;
    }

    std::uniform_int_distribution<int> type_distibution(left_type, right_type);
    std::uniform_int_distribution<int> stats_distibution(1, 5);

    BeeColor bee_type = BeeColor::Red;
    int bee_type_id = type_distibution(generator);

    if (bee_type_id == 1) {
        bee_type = BeeColor::Blue;
    } else if (bee_type_id == 2) {
        bee_type = BeeColor::White;
    }

    int bee_honey_per_pollen = stats_distibution(generator);
    int bee_color_multiplier = stats_distibution(generator);

    Bee bee = Bee(bee_type, bee_honey_per_pollen, bee_color_multiplier);
    player.set_bees(bee);

    if (bee_type == 1) {
        player.set_blue_pollen_multiplier(player.get_blue_pollen_multiplier() + bee_color_multiplier);
    } else if (bee_type == 2) {
        player.set_white_pollen_multiplier(player.get_white_pollen_multiplier() + bee_color_multiplier);
    } else {
        player.set_red_pollen_multiplier(player.get_red_pollen_multiplier() + bee_color_multiplier);
    }
}
