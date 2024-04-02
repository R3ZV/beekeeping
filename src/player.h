#ifndef PLAYER_H
#define PLAYER_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <random>

#include "bee.h"
#include "nlohmann/json.hpp"

class PollenCollection {
    int red_pollen;
    int blue_pollen;
    int white_pollen;
public:
    PollenCollection(int red_pollen, int blue_pollen, int white_pollen);

    int get_red_pollen() const;
    int get_blue_pollen() const;
    int get_white_pollen() const;
};

class FileNotFound : public std::exception {
    std::string message;
public:
    FileNotFound(const std::string& message = "");
    const char * what () const throw ();
};

enum PlayerUpgrade {
    CollectAmount,
    BackpackCapacity,
    HoneyPerPollen,
    NewBee
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

    double calculate_collect_amount();
    int calculate_honey_per_pollen();
    int calculate_backpack_capacity();

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
    int get_pollen() const;
    int get_honey() const;

    int get_total_honey() const;
    int get_total_bees() const;

    int get_total_bees_of_type(BeeColor type) const;

    int get_red_pollen_multiplier() const;
    int get_blue_pollen_multiplier() const;
    int get_white_pollen_multiplier() const;

    std::vector<Bee> get_bees() const;

    int get_backpack_capacity();
    int get_honey_per_pollen();
    int get_collect_amount();

    short int get_collect_amount_upgrades() const;
    short int get_backpack_upgrades() const;
    short int get_honey_per_pollen_upgrades() const;
    short int get_total_upgrades(PlayerUpgrade upgrade_type);
    short int get_max_upgrades() const;

    void set_pollen(int amount);
    void set_honey(int amount);
    void set_total_honey(int amount);
    void set_collect_amount_upgrades(int amount);
    void set_backpack_upgrades(int amount);
    void set_honey_per_pollen_upgrades(int amount);
    void set_bees(Bee bee);

    void set_red_pollen_multiplier(int amount);
    void set_blue_pollen_multiplier(int amount);
    void set_white_pollen_multiplier(int amount);

    int calculate_pollen(PollenCollection collected_pollen);
    PollenCollection collect(int red_flowers, int blue_flowers, int white_flowers);
};
#endif // PLAYER_H
