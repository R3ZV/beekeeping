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

    auto assets = std::make_shared<AssetManager>();
    Game game = Game(MainMenu, player, assets, {});
    std::cout << "DBG:\n";
    std::cout << game << "\n";

    bool is_playing = false;
    double start_timer;
    while (!WindowShouldClose()) {
        if (!is_playing) {
            start_timer = GetTime();
            PlaySound(assets->get_ambient());
            SetSoundVolume(assets->get_ambient(), 0.2);
            is_playing = true;
        }
        if (GetTime() - start_timer > 74) {
            is_playing = false;
        }
        BeginDrawing();
        game.draw_state();
        EndDrawing();
    }

    CloseWindow();
}
