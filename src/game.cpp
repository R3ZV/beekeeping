#include "game.h"
#include "player.h"
#include <string>

void Game::game_main_menu() {
    ClearBackground(RAYWHITE);
    DrawTexture(textures->get_background(), 0, 0, RAYWHITE);
    DrawText("BEEKEEPER", WIDTH / 2 - 275, 5, 90, RAYWHITE);
    DrawText("Press ENTER", WIDTH / 2 - 120, 100, 30, DARKGRAY);

    if (IsKeyPressed(KEY_ENTER)) {
        state = GameState::Lobby;
    }
}

void Game::game_lobby() {
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

    // display fields
    // TODO: add tag to each corner
    const int X_GAP = 116;
    const int Y_GAP = 80;
    const int TEXT_OFFSET = 5;
    int field_icon_x = 350;
    int field_icon_y = 200;

    // First 3
    DrawTexture(textures->get_strawberry_icon(), field_icon_x, field_icon_y, WHITE);
    if (state == GameState::FieldSelection) {
        DrawText("1", field_icon_x + TEXT_OFFSET, field_icon_y + TEXT_OFFSET, 20, BLACK);
    }
    field_icon_x += X_GAP;

    DrawTexture(textures->get_strawberry_icon(), field_icon_x, field_icon_y, WHITE);
    if (state == GameState::FieldSelection) {
        DrawText("2", field_icon_x + TEXT_OFFSET, field_icon_y + TEXT_OFFSET, 20, BLACK);
    }
    field_icon_x += X_GAP;

    DrawTexture(textures->get_strawberry_icon(), field_icon_x, field_icon_y, WHITE);
    if (state == GameState::FieldSelection) {
        DrawText("3", field_icon_x + TEXT_OFFSET, field_icon_y + TEXT_OFFSET, 20, BLACK);
    }

    // Next 3
    field_icon_y += Y_GAP;
    field_icon_x = 350;

    DrawTexture(textures->get_strawberry_icon(), field_icon_x, field_icon_y, WHITE);
    if (state == GameState::FieldSelection) {
        DrawText("4", field_icon_x + TEXT_OFFSET, field_icon_y + TEXT_OFFSET, 20, BLACK);
    }
    field_icon_x += X_GAP;

    DrawTexture(textures->get_strawberry_icon(), field_icon_x, field_icon_y, WHITE);
    if (state == GameState::FieldSelection) {
        DrawText("5", field_icon_x + TEXT_OFFSET, field_icon_y + TEXT_OFFSET, 20, BLACK);
    }
    field_icon_x += X_GAP;

    DrawTexture(textures->get_strawberry_icon(), field_icon_x, field_icon_y, WHITE);
    if (state == GameState::FieldSelection) {
        DrawText("6", field_icon_x + TEXT_OFFSET, field_icon_y + TEXT_OFFSET, 20, BLACK);
    }

    field_icon_y += Y_GAP;
    field_icon_x = 350 + X_GAP;

    // Last
    DrawTexture(textures->get_strawberry_icon(), field_icon_x, field_icon_y, WHITE);
    if (state == GameState::FieldSelection) {
        DrawText("7", field_icon_x + TEXT_OFFSET, field_icon_y + TEXT_OFFSET, 20, BLACK);
    }

    // TODO:
    // make it so after you press F a flag is turned on and the player
    // can select from 7 fields
    // A field number will appear in the corner denoting what button to press
    // to go to it
    if (state == GameState::FieldSelection) {
        if (IsKeyPressed(KEY_B)) {
            state = GameState::Lobby;
        } else if (IsKeyPressed(KEY_ONE)) {
            state = GameState::Field;
        } else if (IsKeyPressed(KEY_TWO)) {
            state = GameState::Field;
        } else if (IsKeyPressed(KEY_THREE)) {
            state = GameState::Field;
        } else if (IsKeyPressed(KEY_FOUR)) {
            state = GameState::Field;
        } else if (IsKeyPressed(KEY_FIVE)) {
            state = GameState::Field;
        } else if (IsKeyPressed(KEY_SIX)) {
            state = GameState::Field;
        } else if (IsKeyPressed(KEY_SEVEN)) {
            state = GameState::Field;
        }

    } else {
        if (IsKeyPressed(KEY_U)) {
            state = GameState::Upgrades;
        } else if (IsKeyPressed(KEY_S)) {
            state = GameState::Stats;
        } else if (IsKeyPressed(KEY_H)) {
            int honey = player.get_honey() + player.get_pollen() * player.calculate_honey_per_pollen();
            player.set_honey(honey);
            player.set_pollen(0);
        } else if (IsKeyPressed(KEY_F)) {
            state = GameState::FieldSelection;
        }
    }
}

void Game::game_field() {
    ClearBackground(BLUE);
    char buffer[50];
    sprintf(buffer, "Pollen: %d / %d", player.get_pollen(), player.get_backpack_capacity());
    DrawText(buffer, WIDTH / 2 - strlen(buffer) * 10, 20, 30, RAYWHITE);
    DrawText("SPACE to collect pollen", WIDTH / 2 - 130, HEIGHT - 100, 20, WHITE);
    DrawText("[B]ack", WIDTH / 2 - 50, HEIGHT - 50, 20, WHITE);

    const int FIELD_X = 100;
    const int FIELD_Y = 120;
    const int FIELD_WIDTH = 512;
    const int FILED_HEIGHT = 256;
    DrawRectangle(FIELD_X, FIELD_Y, FIELD_WIDTH, FILED_HEIGHT, GREEN);

    for (int i = 0; i < (int)actions.size(); ++i) {
        GameAction &action = actions[i];
        action.decrees_opacity(0.3);
        action.move_y(0.1);
        action.start_action();

        if (GetTime() - action.get_timer() >= action.get_deelay()) {
            actions.erase(actions.begin() + i);
            i--;
        }
    }

    if (IsKeyPressed(KEY_B)) {
        state = GameState::Lobby;
    } else if (IsKeyPressed(KEY_SPACE)) {
        std::random_device rd;
        std::mt19937 mt(rd());
        double POLLEN_TEXT_X = std::uniform_real_distribution<>(FIELD_X, FIELD_X + FIELD_WIDTH - 10)(mt);
        double POLLEN_TEXT_Y = std::uniform_real_distribution<>(FIELD_Y, FILED_HEIGHT - 10)(mt);

        PollenCollection collected = player.collect(10, 2, 4);
        std::string total_pollen = "+" + std::to_string(
                                       collected.get_red_pollen()
                                       + collected.get_blue_pollen()
                                       + collected.get_white_pollen());
        actions.push_back(GameAction(3, GetTime(), GameActionType::DisplayText,
                                     total_pollen.c_str(), POLLEN_TEXT_X, POLLEN_TEXT_Y, 20, WHITE, 0));

        player.set_pollen(player.get_pollen() + player.calculate_pollen(collected));
    }
}

void Game::game_upgrades() {
    const int NORMAL_FONT_SIZE = 20;
    ClearBackground(ORANGE);
    DrawText("UPGRADES:", WIDTH / 2 - 5 * NORMAL_FONT_SIZE, 100, 2 * NORMAL_FONT_SIZE, RAYWHITE);
    DrawText("[B]ack", WIDTH / 2 - 3 * NORMAL_FONT_SIZE, HEIGHT - 100, NORMAL_FONT_SIZE, RAYWHITE);

    int pos_x = 100, pos_y = 200;
    const int CARD_WIDTH = 128;
    const int CARD_HEIGHT = 64;
    const int POS_X_MARGIN = 100;
    const int POS_Y_MARGIN = 100;
    const int gap = 10;

    DrawRectangle(pos_x, pos_y, CARD_WIDTH, CARD_HEIGHT, WHITE);
    DrawText("1", pos_x + gap, pos_y + gap, 20, BLACK);
    // TODO: make it based on string length
    DrawText("100 H", pos_x + CARD_WIDTH / 2 - 2 * 20, pos_y + CARD_HEIGHT + gap, 20, BLACK);
    std::cout << "Player has: " << player.get_collect_amount_upgrades() << " upgrades\n";
    if (IsKeyPressed(KEY_B)) {
        state = GameState::Lobby;
    } else if (IsKeyPressed(KEY_ONE)) {
        if (player.get_honey() > 100) {
            player.set_collect_amount_upgrades();
            player.set_honey(player.get_honey() - 100);
            // COME
        }
    } else if (IsKeyPressed(KEY_TWO)) {
        std::cout << "TODO\n";
    } else if (IsKeyPressed(KEY_THREE)) {
        std::cout << "TODO\n";
    } else if (IsKeyPressed(KEY_FOUR)) {
        std::cout << "TODO\n";
    }
}

void Game::game_stats() {
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
    DrawText(buffer, 224, BASE + row * GAP, NORMAL_FONT_SIZE, RAYWHITE);
    row++;

    if (IsKeyPressed(KEY_B)) {
        state = GameState::Lobby;
    }
}

Game::Game(
    GameState state,
    Player instance,
    std::shared_ptr<GameTexture> textures,
    std::vector<GameAction> actions
) :
    state(state),
    player(instance),
    textures(textures),
    actions(actions)
{}

void Game::draw_state() {
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
