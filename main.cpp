#include <cstdlib>
#include <iostream>
#include <fstream>

#include <string>
#include "nlohmann/json.hpp"

enum BeeType {
    Red,
    Blue,
    White
};

class Bee {
    std::string name;
    BeeType type;
};

class Player {
    const std::string name;
    uint64_t honey;
    uint64_t pollen;

    Player(std::string player_name, uint64_t player_honey, uint64_t player_pollen) :
        name(player_name),
        honey(player_honey),
        pollen(player_pollen)
    {}

    /// save_player_stats saves the player information inside a
    /// json file and returns wheather or not
    /// the save was successfully terminated.
    bool save_player_stats() {
        // TODO: save to JSON file
        return true;
    }

public:
    /// load_player_stats reads the player_stats.json file
    /// and returns a Player object with its appropriate data
    static Player load_player_stats() {
        const std::string stats_file_path = "player_stats.json";
        using json = nlohmann::json;

        std::ifstream file(stats_file_path);

        if (!file.is_open()) {
            std::cerr << "[ERROR]: Failed to open json file: " << stats_file_path << std::endl;
            exit(0);
        }

        json stats;
        file >> stats;

        file.close();

        std::string name = stats["name"];
        uint64_t honey = stats["honey"];
        uint64_t pollen = stats["pollen"];

        return Player(name, honey, pollen);
    }

    void debug() {
        std::cout << "PLAYER INFO:" << std::endl;
        std::cout << "Player name: " << name << std::endl;
        std::cout << "Player honey: " << honey << std::endl;
        std::cout << "Player pollen: " << pollen << std::endl;
    }
};

int main() {
    Player player = Player::load_player_stats();
    player.debug();
    return 0;
}
