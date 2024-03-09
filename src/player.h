#ifndef PLAYER_H
#define PLAYER_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "nlohmann/json.hpp"
#include "bee.h"

class Player {
    const std::string name;

    uint32_t honey;
    uint32_t backpack_capacity;
    uint32_t pollen;

    uint8_t backpack_upgrades;
    uint8_t collect_amount_upgrades;
    uint8_t honey_per_pollen_upgrades;

    std::vector<Bee> bees;

    /// save_player_stats saves the player information inside a
    /// json file and returns wheather or not
    /// the save was successfully terminated.
    bool save_player_stats();
    friend std::ostream &operator<<(std::ostream &out, const Player &player);

public:
    Player(
        std::string player_name,
        uint32_t player_honey,
        uint32_t player_backpack_capacity,
        uint32_t player_pollen,
        uint8_t player_backpack_upgrades,
        uint8_t player_collect_amount_upgrades,
        uint8_t player_honey_per_pollen_upgrades,
        std::vector<Bee> player_bees
    );

    /// load_player_stats reads the player_stats.json file
    /// and returns a Player object with its appropriate data
    static Player load_player_stats();
};

#endif // PLAYER_H
