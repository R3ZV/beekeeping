#ifndef PLAYER_H
#define PLAYER_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "bee.h"
#include "nlohmann/json.hpp"

class PollenCollection {
    int red_pollen;
    int blue_pollen;
    int white_pollen;
public:
    PollenCollection(int red_pollen, int blue_pollen, int white_pollen);

    int get_red_pollen();
    int get_blue_pollen();
    int get_white_pollen();
};

class Player {
    const std::string name;

    int total_honey;
    int total_bees;

    int red_bees;
    int blue_bees;
    int white_bees;

    int red_pollen_multiplier;
    int blue_pollen_multiplier;
    int white_pollen_multiplier;

    int honey_per_pollen;
    int collect_amount;

    int honey;
    int backpack_capacity;
    int pollen;

    short int backpack_upgrades;
    short int collect_amount_upgrades;
    short int honey_per_pollen_upgrades;
    short int max_upgrades;

    std::vector<Bee> bees;

    /// save_player_stats saves the player information inside a
    /// json file and returns wheather or not
    /// the save was successfully terminated.
    bool save_player_stats();
    friend std::ostream &operator<<(std::ostream &out, const Player &player);

    int calculate_honey_per_pollen();
    int calculate_backpack_capacity();
    int calculate_collect_amount();

public:
    Player (
        std::string name,
        int total_honey,
        int total_bees,
        int red_bees,
        int blue_bees,
        int white_bees,
        int red_pollen_multiplier,
        int blue_pollen_multiplier,
        int white_pollen_multiplier,
        int honey_per_pollen,
        int collect_amount,
        int honey,
        int backpack_capacity,
        int pollen,
        short int backpack_upgrades,
        short int collect_amount_upgrades,
        short int honey_per_pollen_upgrades,
        std::vector<Bee> bees
    );

    /// load_player_stats reads the player_stats.json file
    /// and returns a Player object with its appropriate data
    static Player load_stats();
    int get_pollen();
    int get_backpack_capacity();
    int get_honey();

    int get_total_honey();
    int get_total_bees();

    int get_total_bees_of_type(BeeColor type);

    int get_red_pollen_multiplier();
    int get_blue_pollen_multiplier();
    int get_white_pollen_multiplier();

    int get_honey_per_pollen();
    int get_collect_amount();

    short int get_backpack_upgrades();
    short int get_collect_amount_upgrades();
    short int get_honey_per_pollen_upgrades();
    short int get_max_upgrades();

    void set_pollen(int amount);
    void set_honey(int amount);
    void set_collect_amount_upgrades(int amount);
    void set_backpack_upgrades(int amount);
    void set_honey_per_pollen_upgrades(int amount);
    int calculate_pollen(PollenCollection collected_pollen);
    PollenCollection collect(int red_flowers, int blue_flowers, int white_flowers);
};

#endif // PLAYER_H
