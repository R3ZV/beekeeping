#include "asset_manager.h"
#include "player.h"
#include "game.h"

#include <memory>
#include <raylib.h>
#include <iostream>

int main() {
    Player player = Player::load_stats();

    InitWindow(WIDTH, HEIGHT, "Bee Keeping");
    InitAudioDevice();

    auto textures = std::make_shared<AssetManager>();
    Game game = Game(MainMenu, player, textures, {});
    Music ambient = LoadMusicStream("./assets/ambient.mp3");
    std::cout << "DBG:\n";
    std::cout << game << "\n";
    while (!WindowShouldClose()) {
        PlayMusicStream(ambient);
        BeginDrawing();
        game.draw_state();
        EndDrawing();
    }

    CloseWindow();
}
