#include "player.h"

Player::Player(std::string player_name, uint32_t player_honey,
               uint32_t player_backpack_capacity, uint32_t player_pollen,
               uint8_t player_backpack_upgrades,
               uint8_t player_collect_amount_upgrades,
               uint8_t player_honey_per_pollen_upgrades,
               std::vector<Bee> player_bees)
    : name(player_name), honey(player_honey),
      backpack_capacity(player_backpack_capacity), pollen(player_pollen),
      backpack_upgrades(player_backpack_upgrades),
      collect_amount_upgrades(player_collect_amount_upgrades),
      honey_per_pollen_upgrades(player_honey_per_pollen_upgrades),
      bees(player_bees) {}

/// save_player_stats saves the player information inside a
/// json file and returns wheather or not
/// the save was successfully terminated.
bool save_player_stats() {
    // TODO: save to JSON file
    return true;
}

/// load_player_stats reads the player_stats.json file
/// and returns a Player object with its appropriate data
Player Player::load_player_stats() {
    const std::string stats_file_path = "player_stats.json";
    using json = nlohmann::json;

    std::ifstream file(stats_file_path);

    if (!file.is_open()) {
        std::cerr << "[ERROR]: Failed to open json file: " << stats_file_path
                  << std::endl;
        exit(0);
    }

    json stats;
    file >> stats;

    file.close();

    std::string name = stats["name"];
    uint32_t honey = stats["honey"];
    uint32_t backpack_capacity = stats["backpack_capacity"];
    uint32_t pollen = stats["pollen"];

    uint32_t backpack_upgrades = stats["backpack_upgrades"];
    uint32_t collect_amount_upgrades = stats["collect_amount_upgrades"];
    uint32_t honey_per_pollen_upgrades = stats["honey_per_pollen_upgrades"];

    std::vector<Bee> bees;
    for (auto bee_stats : stats["bees"]) {
        Color type = bee_stats["type"];
        uint8_t color_multiplier = bee_stats["color_multiplier"];
        uint8_t honey_per_pollen = bee_stats["honey_per_pollen"];
        bees.push_back(Bee(type, color_multiplier, honey_per_pollen));
    }

    return Player(name, honey, backpack_capacity, pollen, backpack_upgrades,
                  collect_amount_upgrades, honey_per_pollen_upgrades, bees);
}

std::ostream &operator<<(std::ostream &out, const Player &player) {
    out << "Player's name: " << player.name << std::endl;
    out << "Player's honey: " << player.honey << std::endl;
    out << "Player's backpack capacity: " << player.backpack_capacity
        << std::endl;
    out << "Player's pollen: " << player.pollen << std::endl;

    out << "The player has: {" << player.backpack_upgrades
        << "} backpack upgrades" << std::endl;
    out << "The player has: {" << player.collect_amount_upgrades
        << "} collect amount upgrades" << std::endl;
    out << "The player has: {" << player.honey_per_pollen_upgrades
        << "} honey per pollen upgrades" << std::endl;

    out << "The player has the following bees:\n";

    for (Bee bee : player.bees) {
        std::cout << bee << std::endl;
    }
    return out;
}
