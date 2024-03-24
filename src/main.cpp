#include "asset_manager.h"
#include "player.h"
#include "game.h"

#include <memory>
#include <raylib.h>
#include <iostream>

int main() {
    Player player = Player::load_stats();

    InitWindow(WIDTH, HEIGHT, "Bee Keeping");

    auto textures = std::make_shared<AssetManager>();
    Game game = Game(MainMenu, player, textures, {});
    std::cout << "DBG:\n";
    std::cout << game << "\n";
    while (!WindowShouldClose()) {
        BeginDrawing();
        game.draw_state();
        EndDrawing();
    }

    CloseWindow();
}
