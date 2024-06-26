#include "asset_manager.h"
#include "player.h"
#include "game.h"

#include <memory>
#include <raylib.h>

int main() {
    std::unique_ptr<Player> player;

    try {
        player = std::make_unique<Player>(Player::load_stats());
    } catch (FileNotFound &err) {
        std::cout << "[ERROR]: couldn't load stats due to: " << err.what() << std::endl;
        return 1;
    }

    InitWindow(WIDTH, HEIGHT, "Bee Keeping");
    InitAudioDevice();
    std::shared_ptr<AssetManager> assets = std::make_shared<AssetManager>();
    std::unique_ptr<Game> game(Game::get_instance(MainMenu, *player, assets, {}));

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
        game->draw_state();
        EndDrawing();
    }

    CloseWindow();
}
