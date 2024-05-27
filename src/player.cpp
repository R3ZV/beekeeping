#include "player.h"

PollenCollection::PollenCollection(int red_pollen, int blue_pollen, int white_pollen) :
    red_pollen(red_pollen), blue_pollen(blue_pollen), white_pollen(white_pollen) {}

int PollenCollection::get_red_pollen() const {
    return red_pollen;
}
int PollenCollection::get_blue_pollen() const {
    return blue_pollen;
}
int PollenCollection::get_white_pollen() const {
    return white_pollen;
}

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
{
    max_upgrades = 20;
}

/// save_player_stats saves the player information inside a
/// json file and returns wheather or not
/// the save was successfully terminated.
bool Player::save_player_stats() {
    // TODO: save to JSON file
    return true;
}

FileNotFound::FileNotFound(const std::string& message) : message(message) {}
const char * FileNotFound::what () const throw () {
    return "file not found";
}

/// load_player_stats reads the player_stats.json file
/// and returns a Player object with its appropriate data
Player Player::load_stats() {
    const std::string stats_file_path = "player_stats.json";
    using json = nlohmann::json;

    std::ifstream file(stats_file_path);

    if (!file.is_open()) {
        throw FileNotFound("Couldn't find file");
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

int Player::get_pollen() const {
    return pollen;
}

int Player::get_backpack_capacity() {
    return calculate_backpack_capacity();
}

int Player::get_honey() const {
    return honey;
}

int Player::get_total_honey() const {
    return total_honey;
}

int Player::get_total_bees() const {
    return bees.size();
}

int Player::get_total_bees_of_type(BeeColor type) const {
    int total = 0;
    for (Bee bee : bees) {
        total += bee.get_type() == type;
    }
    return total;
}

int Player::get_red_pollen_multiplier() const {
    return red_pollen_multiplier;
}

int Player::get_blue_pollen_multiplier() const {
    return blue_pollen_multiplier;
}

int Player::get_white_pollen_multiplier() const {
    return white_pollen_multiplier;
}

int Player::get_honey_per_pollen() {
    return calculate_honey_per_pollen();
}

int Player::get_collect_amount() {
    return calculate_collect_amount();
}

short int Player::get_backpack_upgrades() const {
    return backpack_upgrades;
}

short int Player::get_collect_amount_upgrades() const {
    return collect_amount_upgrades;
}

short int Player::get_honey_per_pollen_upgrades() const {
    return honey_per_pollen_upgrades;
}

short int Player::get_max_upgrades() const {
    return max_upgrades;
}

std::vector<Bee> Player::get_bees() const {
    return bees;
}

void Player::set_pollen(int amount) {
    pollen = amount;
    int capacity = calculate_backpack_capacity();
    pollen = std::min(pollen, capacity);
    assert(pollen <= capacity);
}

void Player::set_total_honey(int amount) {
    total_honey += amount;
}

void Player::set_honey(int amount) {
    honey = amount;
}

double Player::calculate_collect_amount() {
    return collect_amount + collect_amount_upgrades * 0.04;
}

int Player::calculate_pollen(PollenCollection collected_pollen) {
    int red_pollen = collected_pollen.get_red_pollen();
    int blue_pollen = collected_pollen.get_blue_pollen();
    int white_pollen = collected_pollen.get_white_pollen();

    int total_pollen = 0;
    total_pollen += red_pollen + blue_pollen + white_pollen;

    total_pollen += red_pollen * 0.01 * red_pollen_multiplier;
    total_pollen += blue_pollen * 0.01 * blue_pollen_multiplier;
    total_pollen += white_pollen * 0.01 * white_pollen_multiplier;
    return total_pollen;
}

PollenCollection Player::collect(int red_flowers, int blue_flowers, int white_flowers) {
    assert(red_flowers + blue_flowers + white_flowers == 32);

    double player_collect_amount = calculate_collect_amount();
    int red_pollen = red_flowers * player_collect_amount;
    int blue_pollen = blue_flowers * player_collect_amount;
    int white_pollen = white_flowers * player_collect_amount;
    return PollenCollection(red_pollen, blue_pollen, white_pollen);
}

short int Player::get_total_upgrades(PlayerUpgrade upgrade_type) {
    switch(upgrade_type) {
    case PlayerUpgrade::CollectAmount:
        return collect_amount_upgrades;
        break;

    case PlayerUpgrade::BackpackCapacity:
        return backpack_upgrades;
        break;

    case PlayerUpgrade::HoneyPerPollen:
        return honey_per_pollen_upgrades;
        break;

    case PlayerUpgrade::NewBee:
        return bees.size();
        break;
    }
    // TODO: remove this
    return 0;
}

int Player::calculate_honey_per_pollen() {
    int h_per_pollen = honey_per_pollen + honey_per_pollen_upgrades;
    std::for_each(bees.begin(), bees.end(), [&](Bee& bee) {
        h_per_pollen += bee.get_honey_per_pollen();
    });
    return h_per_pollen;
}

int Player::calculate_backpack_capacity() {
    int capacity = backpack_capacity + backpack_capacity * backpack_upgrades;
    return capacity;
}

void Player::set_red_pollen_multiplier(int amount) {
    red_pollen_multiplier = amount;
}

void Player::set_blue_pollen_multiplier(int amount) {
    blue_pollen_multiplier = amount;
}

void Player::set_white_pollen_multiplier(int amount) {
    white_pollen_multiplier = amount;
}

void Player::set_collect_amount_upgrades(int amount) {
    assert(amount <= max_upgrades);
    collect_amount_upgrades = amount;
}

void Player::set_backpack_upgrades(int amount) {
    assert(amount <= max_upgrades);
    backpack_upgrades = amount;
}

void Player::set_honey_per_pollen_upgrades(int amount) {
    assert(amount <= max_upgrades);
    honey_per_pollen_upgrades = amount;
}

void Player::set_bees(Bee bee) {
    if ((int)bees.size() == max_upgrades) {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> index(0, (int)bees.size() - 1);
        int idx = index(generator);
        bees.erase(bees.begin() + idx);
    }
    bees.push_back(bee);
}
