#include "player.h"

Player::Player (
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
) :
    name(name),
    total_honey(total_honey),
    total_bees(total_bees),
    red_bees(red_bees),
    blue_bees(blue_bees),
    white_bees(white_bees),
    red_pollen_multiplier(red_pollen_multiplier),
    blue_pollen_multiplier(blue_pollen_multiplier),
    white_pollen_multiplier(white_pollen_multiplier),
    honey_per_pollen(honey_per_pollen),
    collect_amount(collect_amount),
    honey(honey),
    backpack_capacity(backpack_capacity),
    pollen(pollen),
    backpack_upgrades(backpack_upgrades),
    collect_amount_upgrades(collect_amount_upgrades),
    honey_per_pollen_upgrades(honey_per_pollen_upgrades),
    bees(bees)
{}

/// save_player_stats saves the player information inside a
/// json file and returns wheather or not
/// the save was successfully terminated.
bool Player::save_player_stats() {
    // TODO: save to JSON file
    return true;
}

/// load_player_stats reads the player_stats.json file
/// and returns a Player object with its appropriate data
Player Player::load_stats() {
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
    int total_honey = stats["total_honey"];
    int total_bees = stats["total_bees"];
    int red_bees = stats["red_bees"];
    int blue_bees = stats["blue_bees"];
    int white_bees = stats["white_bees"];
    int red_pollen_multiplier = stats["red_pollen_multiplier"];
    int blue_pollen_multiplier = stats["blue_pollen_multiplier"];
    int white_pollen_multiplier = stats["white_pollen_multiplier"];
    int honey_per_pollen = stats["honey_per_pollen"];
    int collect_amount = stats["collect_amount"];
    int honey = stats["honey"];
    int backpack_capacity = stats["backpack_capacity"];
    int pollen = stats["pollen"];

    short int backpack_upgrades = stats["backpack_upgrades"];
    short int collect_amount_upgrades = stats["collect_amount_upgrades"];
    short int honey_per_pollen_upgrades = stats["honey_per_pollen_upgrades"];

    std::vector<Bee> bees;
    for (auto bee_stats : stats["bees"]) {
        BeeColor type = bee_stats["type"];
        short int color_multiplier = bee_stats["color_multiplier"];
        short int honey_per_pollen = bee_stats["honey_per_pollen"];
        bees.push_back(Bee(type, color_multiplier, honey_per_pollen));
    }

    return Player (
               name,
               total_honey,
               total_bees,
               red_bees,
               blue_bees,
               white_bees,
               red_pollen_multiplier,
               blue_pollen_multiplier,
               white_pollen_multiplier,
               honey_per_pollen,
               collect_amount,
               honey,
               backpack_capacity,
               pollen,
               backpack_upgrades,
               collect_amount_upgrades,
               honey_per_pollen_upgrades,
               bees
           );
}

std::ostream &operator<<(std::ostream &out, const Player &player) {
    out << "Name: " << player.name << std::endl;
    out << "Total honey: " << player.total_honey << std::endl;
    out << "Total bees: " << player.total_bees << std::endl;
    out << "Red bees: " << player.red_bees << std::endl;
    out << "Blue bees: " << player.blue_bees << std::endl;
    out << "White bees: " << player.white_bees << std::endl;
    out << "Red pollen multiplier: " << player.red_pollen_multiplier << std::endl;
    out << "Blue pollen multiplier: " << player.blue_pollen_multiplier << std::endl;
    out << "White pollen multiplier: " << player.white_pollen_multiplier << std::endl;
    out << "Honey per pollen: " << player.honey_per_pollen << std::endl;
    out << "Collect amount: " << player.collect_amount << std::endl;
    out << "Honey: " << player.honey << std::endl;
    out << "Backpack capacity: " << player.backpack_capacity << std::endl;
    out << "Pollen: " << player.pollen << std::endl;
    out << "Backpack upgrades: " << player.backpack_upgrades << std::endl;
    out << "Collect amount upgrades: " << player.collect_amount_upgrades << std::endl;
    out << "Honey per pollen upgrades: " << player.honey_per_pollen_upgrades << std::endl;
    out << "Honey per pollen upgrades: " << player.honey_per_pollen_upgrades << std::endl;

    out << "The player has the following bees:\n";

    for (Bee bee : player.bees) {
        std::cout << bee << std::endl;
    }
    return out;
}

int Player::get_pollen() {
    return pollen;
}

int Player::get_backpack_capacity() {
    return backpack_capacity;
}

int Player::get_honey() {
    return honey;
}

int Player::get_total_honey() {
    return total_honey;
}

int Player::get_total_bees() {
    return bees.size();
}

int Player::get_total_bees_of_type(BeeColor type) {
    int total = 0;
    for (Bee bee : bees) {
        total += bee.get_type() == type;
    }
    return total;
}

int Player::get_red_pollen_multiplier() {
    return red_pollen_multiplier;
}

int Player::get_blue_pollen_multiplier() {
    return blue_pollen_multiplier;
}

int Player::get_white_pollen_multiplier() {
    return white_pollen_multiplier;
}

int Player::get_honey_per_pollen() {
    return honey_per_pollen;
}

int Player::get_collect_amount() {
    return collect_amount;
}

short int Player::get_backpack_upgrades() {
    return backpack_upgrades;
}

short int Player::get_collect_amount_upgrades() {
    return collect_amount_upgrades;
}

short int Player::get_honey_per_pollen_upgrades() {
    return honey_per_pollen_upgrades;
}

void Player::set_pollen(int red_pollen, int blue_pollen, int white_pollen) {
    pollen += red_pollen * red_pollen_multiplier;
    pollen += blue_pollen * blue_pollen_multiplier;
    pollen += white_pollen * white_pollen_multiplier;
    pollen = std::min(pollen, backpack_capacity);
    assert(pollen <= backpack_capacity);
}

void Player::set_honey() {
    honey += pollen * honey_per_pollen;
    pollen = 0;
}
