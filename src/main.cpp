#include "game_texture.h"
#include "player.h"
#include "game.h"

#include <raylib.h>
#include <iostream>

int main() {
    Player player = Player::load_stats();

    InitWindow(WIDTH, HEIGHT, "Bee Keeping");

    GameTexture textures = GameTexture();
    Game game = Game(MainMenu, player, textures, GetTime(), {});

    std::cout << player;
    while (!WindowShouldClose()) {
        BeginDrawing();
        game.draw_state();
        EndDrawing();
    }

    CloseWindow();
}
