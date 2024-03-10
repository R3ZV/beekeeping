#include "player.h"
#include <iostream>

int main() {
    Player player = Player::load_player_stats();
    std::cout << player;
    return 0;
}
