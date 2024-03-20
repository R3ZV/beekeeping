#include "game_texture.h"
#include "player.h"
#include "game.h"

#include <memory>
#include <raylib.h>
#include <iostream>

int main() {
    Player player = Player::load_stats();

    InitWindow(WIDTH, HEIGHT, "Bee Keeping");

    auto textures = std::make_shared<GameTexture>();
    Game game = Game(MainMenu, player, textures, {});

    std::cout << player;
    while (!WindowShouldClose()) {
        BeginDrawing();
        game.draw_state();
        EndDrawing();
    }

    CloseWindow();
}
