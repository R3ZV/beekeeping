#include "game.h"

std::ostream &operator<<(std::ostream& out, const Game& game) {
    out << "Game state: \n" << game.state;
    out << "\n";

    out << "Player: \n" << game.player;
    out << "\n";

    out << "Assets:\n " << *game.assets;
    return out;
}

void Game::game_main_menu() {
    ClearBackground(RAYWHITE);
    DrawTexture(assets->get_background(), 0, 0, RAYWHITE);
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
    const int X_GAP = 116;
    const int Y_GAP = 80;
    const int TEXT_OFFSET = 5;
    int field_icon_x = 350;
    int field_icon_y = 200;

    // First 3
    DrawTexture(assets->get_strawberry_icon(), field_icon_x, field_icon_y, WHITE);
    if (state == GameState::FieldSelection) {
        DrawText("1", field_icon_x + TEXT_OFFSET, field_icon_y + TEXT_OFFSET, 20, BLACK);
    }
    field_icon_x += X_GAP;

    DrawTexture(assets->get_sunflower_icon(), field_icon_x, field_icon_y, WHITE);
    if (state == GameState::FieldSelection) {
        DrawText("2", field_icon_x + TEXT_OFFSET, field_icon_y + TEXT_OFFSET, 20, BLACK);
    }
    field_icon_x += X_GAP;

    DrawTexture(assets->get_clover_icon(), field_icon_x, field_icon_y, WHITE);
    if (state == GameState::FieldSelection) {
        DrawText("3", field_icon_x + TEXT_OFFSET, field_icon_y + TEXT_OFFSET, 20, BLACK);
    }

    // Next 3
    field_icon_y += Y_GAP;
    field_icon_x = 350;

    DrawTexture(assets->get_cactus_icon(), field_icon_x, field_icon_y, WHITE);
    if (state == GameState::FieldSelection) {
        DrawText("4", field_icon_x + TEXT_OFFSET, field_icon_y + TEXT_OFFSET, 20, BLACK);
    }
    field_icon_x += X_GAP;

    DrawTexture(assets->get_cherry_icon(), field_icon_x, field_icon_y, WHITE);
    if (state == GameState::FieldSelection) {
        DrawText("5", field_icon_x + TEXT_OFFSET, field_icon_y + TEXT_OFFSET, 20, BLACK);
    }
    field_icon_x += X_GAP;

    DrawTexture(assets->get_orange_icon(), field_icon_x, field_icon_y, WHITE);
    if (state == GameState::FieldSelection) {
        DrawText("6", field_icon_x + TEXT_OFFSET, field_icon_y + TEXT_OFFSET, 20, BLACK);
    }

    field_icon_y += Y_GAP;
    field_icon_x = 350 + X_GAP;

    // Last
    DrawTexture(assets->get_blueberry_icon(), field_icon_x, field_icon_y, WHITE);
    if (state == GameState::FieldSelection) {
        DrawText("7", field_icon_x + TEXT_OFFSET, field_icon_y + TEXT_OFFSET, 20, BLACK);
    }

    if (state == GameState::FieldSelection) {
        if (IsKeyPressed(KEY_B)) {
            state = GameState::Lobby;
        } else {
            int key_pressed = GetKeyPressed();
            if (key_pressed >= KEY_ONE && key_pressed <= KEY_SEVEN) {
                key_pressed -= KEY_ONE;
                GameState new_state = static_cast<GameState>(key_pressed);
                state = new_state;
            }
        }
    } else {
        if (IsKeyPressed(KEY_U)) {
            state = GameState::Upgrades;
        } else if (IsKeyPressed(KEY_S)) {
            state = GameState::Stats;
        } else if (IsKeyPressed(KEY_H)) {
            PlaySound(assets->get_honey_sold_sound());
            int honey = player.get_honey() + player.get_pollen() * player.get_honey_per_pollen();
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
    std::vector<Field> fields = Field::all_fields(assets);
    Field current_field = fields[state];
    std::cout << "Field has following properties: \n" << current_field << "\n";
    DrawTexture(current_field.get_field(), FIELD_X, FIELD_Y, WHITE);

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

    // bees
    std::vector<Bee> bees = player.get_bees();
    const int GAP = 20;
    const int SPRITE_WIDTH = 64;
    const int SPRITE_HEIGHT = 88;
    const int COLS = 4;
    for (int i = 0; i < (int)bees.size(); ++i) {
        if (bees[i].get_type() == BeeColor::Red) {
            DrawTexture(
                assets->get_red_bee_face(),
                WIDTH - 364 + (SPRITE_WIDTH + GAP) * (i % COLS),
                100 + (SPRITE_HEIGHT + GAP) * (i / COLS),
                WHITE);
        } else if (bees[i].get_type() == BeeColor::Blue) {
            DrawTexture(
                assets->get_blue_bee_face(),
                WIDTH - 364 + (SPRITE_WIDTH + GAP) * (i % COLS),
                100 + (SPRITE_HEIGHT + GAP) * (i / COLS),
                WHITE);
        } else {
            DrawTexture(
                assets->get_white_bee_face(),
                WIDTH - 364 + (SPRITE_WIDTH + GAP) * (i % COLS),
                100 + (SPRITE_HEIGHT + GAP) * (i / COLS),
                WHITE);
        }
    }

    if (IsKeyPressed(KEY_B)) {
        state = GameState::Lobby;
    } else if (IsKeyPressed(KEY_SPACE)) {
        PlaySound(assets->get_collect_sound());
        std::random_device rd;
        std::mt19937 mt(rd());
        double POLLEN_TEXT_X = std::uniform_real_distribution<>(FIELD_X, FIELD_X + FIELD_WIDTH - 10)(mt);
        double POLLEN_TEXT_Y = std::uniform_real_distribution<>(FIELD_Y, FILED_HEIGHT - 10)(mt);

        PollenCollection collected = player.collect(
                                         current_field.get_red_flowers(),
                                         current_field.get_blue_flowers(),
                                         current_field.get_white_flowers()
                                     );
        std::cout << "From the field with: " << current_field << "\n";
        std::cout << "Collected: " << collected << "\n";
        std::string total_pollen = "+" + std::to_string(
                                       collected.get_red_pollen()
                                       + collected.get_blue_pollen()
                                       + collected.get_white_pollen());
        GameAction pollen_text = GameAction(3, GetTime(), GameActionType::DisplayText,
                                            total_pollen.c_str(), POLLEN_TEXT_X, POLLEN_TEXT_Y, 20, WHITE, 0);
        actions.push_back(pollen_text);

        player.set_pollen(player.get_pollen() + player.calculate_pollen(collected));
    }
}

void Game::game_upgrades() {
    const int NORMAL_FONT_SIZE = 20;
    ClearBackground(ORANGE);

    char buffer[50];
    std::sprintf(buffer, "Honey: %d", player.get_honey());
    DrawText(buffer, 2 * NORMAL_FONT_SIZE, 20, NORMAL_FONT_SIZE, RAYWHITE);

    DrawText("UPGRADES:", WIDTH / 2 - 5 * NORMAL_FONT_SIZE, 100, 2 * NORMAL_FONT_SIZE, RAYWHITE);
    DrawText("[B]ack", WIDTH / 2 - MeasureText("[B]ack", NORMAL_FONT_SIZE), HEIGHT - 100, NORMAL_FONT_SIZE, RAYWHITE);

    const int CARD_WIDTH = 128;
    const int CARD_HEIGHT = 64;
    const int POS_X_MARGIN = 50;
    const int POS_Y_MARGIN = 100;
    const int gap = 10;
    const int COLS = 2;

    std::vector<std::unique_ptr<Upgrade>> upgrades;
    upgrades.push_back(std::make_unique<CollectAmountUpgrade>(100,
                       player.get_total_upgrades(PlayerUpgrade::CollectAmount),
                       assets->get_collect_amount_upgrade_icon()));
    upgrades.push_back(std::make_unique<BackpackUpgrade>(100,
                       player.get_total_upgrades(PlayerUpgrade::BackpackCapacity),
                       assets->get_backpack_upgrade_icon()));
    upgrades.push_back(std::make_unique<HoneyPerPollenUpgrade>(100,
                       player.get_total_upgrades(PlayerUpgrade::HoneyPerPollen),
                       assets->get_honey_per_pollen_upgrade_icon()));
    upgrades.push_back(std::make_unique<BeeUpgrade>(100,
                       player.get_total_upgrades(PlayerUpgrade::NewBee),
                       assets->get_bee_egg_icon()));

    const int POS_X = WIDTH / 2 - CARD_WIDTH - POS_X_MARGIN / 2, POS_Y = 200;
    for (int i = 0; i < (int)upgrades.size(); ++i) {
        int pos_x = POS_X + (CARD_WIDTH + POS_X_MARGIN) * (i % COLS);
        int pos_y = POS_Y + (CARD_HEIGHT + POS_Y_MARGIN) * (i / COLS);

        DrawTexture(upgrades[i]->get_icon(), pos_x, pos_y, WHITE);

        char buffer[50];
        sprintf(buffer, "%d", i + 1);
        DrawText(buffer,
                 pos_x + gap,
                 pos_y + gap,
                 20, BLACK);

        sprintf(buffer, "%d H", upgrades[i]->get_price());
        DrawText(buffer,
                 pos_x + CARD_WIDTH / 2 - MeasureText(buffer, 20),
                 pos_y + CARD_HEIGHT + gap,
                 20, BLACK);
    }

    if (IsKeyPressed(KEY_B)) {
        state = GameState::Lobby;
    } else {
        for (int i = 0; i < (int)upgrades.size(); ++i) {
            if (IsKeyPressed(KEY_ONE + i)) {
                if (IsKeyPressed(KEY_FOUR)) {
                    PlaySound(assets->get_egg_hatch_sound());
                } else {
                    PlaySound(assets->get_purchase_sound());
                }
                upgrades[i]->purchase(player);
            }
        }
    }
}

void Game::game_stats() {
    ClearBackground(RED);
    const int FONT_SIZE = 22;
    DrawText("STATS:", WIDTH / 2 - 3 * FONT_SIZE, 30, 2 * FONT_SIZE, RAYWHITE);
    DrawText("[B]ack", WIDTH / 2 - 3 * FONT_SIZE, HEIGHT - 30, FONT_SIZE, RAYWHITE);

    const int GAP = 24;
    const int BASE = 100;
    const int NORMAL_FONT_SIZE = 20;
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

    std::sprintf(buffer, "Backpack upgrades: %d", player.get_total_upgrades(PlayerUpgrade::BackpackCapacity));
    DrawText(buffer, 224, BASE + row * GAP, NORMAL_FONT_SIZE, RAYWHITE);
    row++;

    std::sprintf(buffer, "Collect amount upgrades: %d", player.get_total_upgrades(PlayerUpgrade::CollectAmount));
    DrawText(buffer, 224, BASE + row * GAP, NORMAL_FONT_SIZE, RAYWHITE);
    row++;

    std::sprintf(buffer, "Honey per pollen upgrades: %d", player.get_total_upgrades(PlayerUpgrade::HoneyPerPollen));
    DrawText(buffer, 224, BASE + row * GAP, NORMAL_FONT_SIZE, RAYWHITE);
    row++;

    if (IsKeyPressed(KEY_B)) {
        state = GameState::Lobby;
    }
}

Game::Game(
    GameState state,
    Player instance,
    std::shared_ptr<AssetManager> textures,
    std::vector<GameAction> actions
) :
    state(state),
    player(instance),
    assets(textures),
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

    case StrawberryField:
        game_field();
        break;

    case SunflowerField:
        game_field();
        break;

    case CloverField:
        game_field();
        break;

    case CactusField:
        game_field();
        break;

    case CherryField:
        game_field();
        break;

    case OrangeField:
        game_field();
        break;

    case BlueberryField:
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
