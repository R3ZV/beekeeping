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

void CollectAmountUpgrade::purchase(Player& player) const {
    if (player.get_honey() >= get_price() && get_upgrades() < player.get_max_upgrades()) {
        player.set_honey(player.get_honey() - get_price());
        player.set_collect_amount_upgrades(get_upgrades() + 1);
    }
}

void BackpackUpgrade::purchase(Player& player) const {
    if (player.get_honey() >= get_price() && get_upgrades() < player.get_max_upgrades()) {
        player.set_honey(player.get_honey() - get_price());
        player.set_backpack_upgrades(get_upgrades() + 1);
    }
}

void HoneyPerPollenUpgrade::purchase(Player& player) const {
    if (player.get_honey() >= get_price() && get_upgrades() < player.get_max_upgrades()) {
        player.set_honey(player.get_honey() - get_price());
        player.set_honey_per_pollen_upgrades(get_upgrades() + 1);
    }
}

void BeeUpgrade::purchase(Player& player) const {
    if (player.get_honey() >= get_price() && get_upgrades() < player.get_max_upgrades()) {
        player.set_honey(player.get_honey() - get_price());

        std::default_random_engine generator;
        std::uniform_int_distribution<int> type_distibution(0, 2);
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
    }
}
