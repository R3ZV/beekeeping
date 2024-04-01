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

    auto textures = std::make_shared<AssetManager>();
    Game game = Game(MainMenu, *player, textures, {});
    Music ambient = LoadMusicStream("./assets/ambient.mp3");
    while (!WindowShouldClose()) {
        PlayMusicStream(ambient);
        BeginDrawing();
        game.draw_state();
        EndDrawing();
    }

    CloseWindow();
}
