#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "game_action.h"
#include "upgrade.h"
#include "asset_manager.h"
#include "field.h"

#include <sstream>
#include <string>
#include <raylib.h>
#include <random>
#include <memory>

#define WIDTH 1024
#define HEIGHT 800

enum GameState {
    StrawberryField,
    SunflowerField,
    CloverField,
    CactusField,
    CherryField,
    OrangeField,
    BlueberryField,
    MainMenu,
    Lobby,
    Upgrades,
    FieldSelection,
    Stats,
};

class Game {
    GameState state;
    Player player;
    std::shared_ptr<AssetManager> assets;
    std::vector<GameAction> actions;

    void game_main_menu();
    void game_lobby();
    void game_field();
    void game_upgrades();
    void game_stats();

public:
    Game(
        GameState state,
        Player instance,
        std::shared_ptr<AssetManager> textures,
        std::vector<GameAction> actions
    );

    void draw_state();
};

#endif // GAME_H
