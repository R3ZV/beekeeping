#include "raylib.h"
#include "player.h"

#include <cstring>
#include <iostream>

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

// TODO: add destructors to unload textures
class GameTexture {
    Texture2D background;
public:
    GameTexture (Texture2D game_background) : background(game_background) {}
    Texture2D get_background() {
        return background;
    }
};

class Game {
    GameState state;
    Player player;
    GameTexture textures;

    void game_main_menu() {
        ClearBackground(RAYWHITE);
        DrawTexture(textures.get_background(), 0, 0, RAYWHITE);
        DrawText("BEE KEEPER", WIDTH / 2 - 275, 5, 90, RAYWHITE);
        DrawText("Press ENTER", WIDTH / 2 - 120, 100, 30, DARKGRAY);

        if (IsKeyPressed(KEY_ENTER)) {
            state = GameState::Lobby;
        }
    }

    void game_lobby() {
        const int NORMAL_FONT_SIZE = 20;
        ClearBackground(BLUE);
        DrawText("LOBBY", WIDTH / 2 - 3 * NORMAL_FONT_SIZE, 100, 2 * NORMAL_FONT_SIZE, RAYWHITE);

        char buffer[50];
        std::sprintf(buffer, "Pollen: %d / %d", player.get_pollen(), player.get_backpack_capacity());
        DrawText(buffer, WIDTH - strlen(buffer) * 12, 20, NORMAL_FONT_SIZE, RAYWHITE);

        std::sprintf(buffer, "Honey: %d", player.get_honey());
        DrawText(buffer, 2 * NORMAL_FONT_SIZE, 20, NORMAL_FONT_SIZE, RAYWHITE);

        const int AVERAGE_LETTERS = 12;
        const int GAP = 50;
        DrawText("[U]pgrades", WIDTH - NORMAL_FONT_SIZE * AVERAGE_LETTERS, HEIGHT - 100 - 4 * GAP, NORMAL_FONT_SIZE, RAYWHITE);
        DrawText("[S]tats", WIDTH - NORMAL_FONT_SIZE * AVERAGE_LETTERS, HEIGHT - 100 - 3 * GAP, NORMAL_FONT_SIZE, RAYWHITE);
        DrawText("Sell [H]oney", WIDTH - NORMAL_FONT_SIZE * AVERAGE_LETTERS, HEIGHT - 100 - 2 * GAP, NORMAL_FONT_SIZE, RAYWHITE);
        DrawText(state == GameState::FieldSelection ? "[B]ack" : "[F]ields", WIDTH - NORMAL_FONT_SIZE * AVERAGE_LETTERS, HEIGHT - 100 - GAP, NORMAL_FONT_SIZE, RAYWHITE);

        // TODO:
        // make it so after you press F a flag is turned on and the player
        // can select the field using vim keys
        // when the flag is selected no other shorcut works
        // When you have a field selected you press enter and go to the field
        // Or it can be like Vimium where you press F and for each
        // field a text will appear in the corner denoting what button to press
        // to go to it
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

    void game_upgrades() {
        const int NORMAL_FONT_SIZE = 20;
        ClearBackground(ORANGE);
        DrawText("UPGRADES:", WIDTH / 2 - 5 * NORMAL_FONT_SIZE, 100, 2 * NORMAL_FONT_SIZE, RAYWHITE);
        DrawText("[B]ack", WIDTH / 2 - 3 * NORMAL_FONT_SIZE, HEIGHT - 100, NORMAL_FONT_SIZE, RAYWHITE);

        if (IsKeyPressed(KEY_B)) {
            state = GameState::Lobby;
        }
    }

    void game_stats() {
        ClearBackground(RED);
        const int FONT_SIZE = 20;
        DrawText("STATS:", WIDTH / 2 - 3 * FONT_SIZE, 30, 2 * FONT_SIZE, RAYWHITE);
        DrawText("[B]ack", WIDTH / 2 - 3 * FONT_SIZE, HEIGHT - 30, FONT_SIZE, RAYWHITE);

        const int GAP = 24;
        const int BASE = 100;
        const int NORMAL_FONT_SIZE = 18;
        int row = 1;

        char buffer[50];

        std::sprintf(buffer, "Total honey: %d", player.get_total_honey());
        DrawText(buffer, 224, BASE + row * GAP, NORMAL_FONT_SIZE, RAYWHITE);
        row++;

        std::sprintf(buffer, "Total bees: %d", player.get_total_bees());
        DrawText(buffer, 224, BASE + row * GAP, NORMAL_FONT_SIZE, RAYWHITE);
        row++;

        std::sprintf(buffer, "Red bees: %d", player.get_total_bees_of_type(BeeColor::Red));
        DrawText(buffer, 224, BASE + row * GAP, NORMAL_FONT_SIZE, RAYWHITE);
        row++;

        std::sprintf(buffer, "Blue bees: %d", player.get_total_bees_of_type(BeeColor::Blue));
        DrawText(buffer, 224, BASE + row * GAP, NORMAL_FONT_SIZE, RAYWHITE);
        row++;

        std::sprintf(buffer, "White bees: %d", player.get_total_bees_of_type(BeeColor::White));
        DrawText(buffer, 224, BASE + row * GAP, NORMAL_FONT_SIZE, RAYWHITE);
        row++;

        std::sprintf(buffer, "Red pollen multiplier: %d", player.get_red_pollen_multiplier());
        DrawText(buffer, 224, BASE + row * GAP, NORMAL_FONT_SIZE, RAYWHITE);
        row++;

        std::sprintf(buffer, "Blue pollen multiplier: %d", player.get_blue_pollen_multiplier());
        DrawText(buffer, 224, BASE + row * GAP, NORMAL_FONT_SIZE, RAYWHITE);
        row++;

        std::sprintf(buffer, "White pollen multiplier: %d", player.get_blue_pollen_multiplier());
        DrawText(buffer, 224, BASE + row * GAP, NORMAL_FONT_SIZE, RAYWHITE);
        row++;

        std::sprintf(buffer, "Honey per pollen: %d", player.get_honey_per_pollen());
        DrawText(buffer, 224, BASE + row * GAP, NORMAL_FONT_SIZE, RAYWHITE);
        row++;

        std::sprintf(buffer, "Collect amount: %d", player.get_collect_amount());
        DrawText(buffer, 224, BASE + row * GAP, NORMAL_FONT_SIZE, RAYWHITE);
        row++;

        std::sprintf(buffer, "Backpack upgrades: %d", player.get_backpack_upgrades());
        DrawText(buffer, 224, BASE + row * GAP, NORMAL_FONT_SIZE, RAYWHITE);
        row++;

        std::sprintf(buffer, "Collect amount upgrades: %d", player.get_collect_amount_upgrades());
        DrawText(buffer, 224, BASE + row * GAP, NORMAL_FONT_SIZE, RAYWHITE);
        row++;

        std::sprintf(buffer, "Honey per pollen upgrades: %d", player.get_honey_per_pollen_upgrades());
        DrawText("Honey per pollen upgrades: []", 224, BASE + row * GAP, NORMAL_FONT_SIZE, RAYWHITE);
        row++;

        if (IsKeyPressed(KEY_B)) {
            state = GameState::Lobby;
        }
    }

public:
    Game(GameState initial_state, Player player_instance, GameTexture game_textures)
        :
        state(initial_state),
        player(player_instance),
        textures(game_textures)
    {}

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
            game_upgrades();
            break;

        case Stats:
            game_stats();
            break;
        }
    }
};

int main() {
    Player player = Player::load_stats();
    InitWindow(WIDTH, HEIGHT, "Bee Keeping");

    Texture2D background = LoadTexture("./assets/background.png");
    GameTexture textures = GameTexture(background);
    Game game = Game(MainMenu, player, textures);

    std::cout << player;
    while (!WindowShouldClose()) {
        BeginDrawing();
        game.draw_state();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
