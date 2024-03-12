#ifndef PLAYER_H
#define PLAYER_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "bee.h"
#include "nlohmann/json.hpp"

class Player {
    const std::string name;

    int honey;
    int backpack_capacity;
    int pollen;

    short int backpack_upgrades;
    short int collect_amount_upgrades;
    short int honey_per_pollen_upgrades;

    std::vector<Bee> bees;

    /// save_player_stats saves the player information inside a
    /// json file and returns wheather or not
    /// the save was successfully terminated.
    bool save_player_stats();
    friend std::ostream &operator<<(std::ostream &out, const Player &player);

public:
    Player(std::string player_name, int player_honey,
           int player_backpack_capacity,
           int player_pollen,
           short int player_backpack_upgrades,
           short int player_collect_amount_upgrades,
           short int player_honey_per_pollen_upgrades,
           std::vector<Bee> player_bees);

    /// load_player_stats reads the player_stats.json file
    /// and returns a Player object with its appropriate data
    static Player load_stats();
    int get_pollen();
    int get_backpack_capacity();
    int get_honey();
};

#endif // PLAYER_H
