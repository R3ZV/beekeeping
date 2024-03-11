#include "raylib.h"
#include "player.h"

#include <iostream>

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

    void game_main_menu() {
        ClearBackground(RAYWHITE);
        DrawText("Main Menu", 190, 200, 20, LIGHTGRAY);
        DrawText("Press ENTER to start", 190, 300, 20, LIGHTGRAY);

        if (IsKeyPressed(KEY_ENTER)) {
            state = GameState::Lobby;
        }
    }

    void game_lobby() {
        ClearBackground(RAYWHITE);
        DrawText("This is lobby", 190, 200, 20, LIGHTGRAY);
        DrawText("Press U to go to the Upgrades", 190, 300, 20, LIGHTGRAY);
        DrawText("Press S to go to the Stats", 190, 400, 20, LIGHTGRAY);
        DrawText("Press H to sell pollen", 190, 500, 20, LIGHTGRAY);

        // TODO:
        // make it so after you press F a flag is turned on and the player
        // can select the field using vim keys
        // when the flag is selected no other shorcut works
        // When you have a field selected you press enter and go to the field
        // Or it can be like Vimium where you press F and for each
        // field a text will appear in the corner denoting what button to press
        // to go to it
        DrawText("Press F to focus FIELDS", 190, 600, 20, LIGHTGRAY);

        if (state == GameState::FieldSelection) {
            // TODO: add overlay for each field with
            // numbers from 1 to 7 to select which field to go to
            if (IsKeyPressed(KEY_B)) {
                state = GameState::Lobby;
            } else if (IsKeyPressed(KEY_ENTER)) {
                // go to the field
            }
        } else {
            if (IsKeyPressed(KEY_U)) {
                state = GameState::Upgrades;
            } else if (IsKeyPressed(KEY_S)) {
                state = GameState::Stats;
            } else if (IsKeyPressed(KEY_H)) {
                // TODO: sell the pollen for honey
                // player.set_honey(player.get_pollen());
                // taking into account upgrades and bees buff
            } else if (IsKeyPressed(KEY_F)) {
                state = GameState::FieldSelection;
            }
        }
    }

    void game_field() {
        ClearBackground(RAYWHITE);
        DrawText("This is field", 190, 200, 20, LIGHTGRAY);
        DrawText("Press B to go back", 190, 300, 20, LIGHTGRAY);

        if (IsKeyPressed(KEY_B)) {
            state = GameState::Lobby;
        }
    }

    void game_shop() {
        ClearBackground(RAYWHITE);
        DrawText("This is upgrades", 190, 200, 20, LIGHTGRAY);
        DrawText("Press B to go back", 190, 300, 20, LIGHTGRAY);

        if (IsKeyPressed(KEY_B)) {
            state = GameState::Lobby;
        }
    }

    void game_stats() {
        ClearBackground(RAYWHITE);
        DrawText("This is stats", 190, 200, 20, LIGHTGRAY);
        DrawText("Press B to go back", 190, 300, 20, LIGHTGRAY);

        if (IsKeyPressed(KEY_B)) {
            state = GameState::Lobby;
        }
    }

public:
    Game(GameState initial_state, Player player_instance) : state(initial_state), player(player_instance) {}

    void draw_state() {
        switch (state) {
        case MainMenu:
            game_main_menu();
            break;

        case Lobby:
            game_lobby();
            break;

        case FieldSelection:
            game_lobby();
            break;

        case Field:
            game_field();
            break;

        case Upgrades:
            game_shop();
            break;

        case Stats:
            game_stats();
            break;
        }
    }
};

int main() {
    Player player = Player::load_player_stats();
    std::cout << player;

    const int WIDTH = 1024;
    const int HEIGHT = 800;
    InitWindow(WIDTH, HEIGHT, "Bee Keeping");

    Game game = Game(MainMenu, player);
    while (!WindowShouldClose()) {
        BeginDrawing();
        game.draw_state();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
