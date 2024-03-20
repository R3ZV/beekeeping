#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "game_action.h"
#include "game_texture.h"

#include <queue>
#include <raylib.h>
#include <random>

#define WIDTH 1024
#define HEIGHT 800

enum GameState {
    MainMenu,
    Lobby,
    Upgrades,
    Field,
    FieldSelection,
    Stats,
};

class Game {
    GameState state;
    Player player;
    std::shared_ptr<GameTexture> textures;
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
        std::shared_ptr<GameTexture> textures,
        std::vector<GameAction> actions
    );
    void draw_state();
};

#endif // GAME_H
