#include "game.h"

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

void Game::game_main_menu() {
    ClearBackground(RAYWHITE);
    DrawTexture(assets->get_background(), 0, 0, RAYWHITE);

    DrawText("BEEKEEPER", WIDTH / 2 - MeasureText("BEEKEEPER", 90) / 2, 5, 90, RAYWHITE);
    DrawText("Press ENTER", WIDTH / 2 - MeasureText("Press ENTER", 30) / 2, 100, 30, DARKGRAY);

    if (IsKeyPressed(KEY_ENTER)) {
        state = GameState::Lobby;
    }
}

void Game::game_lobby() {
    const int NORMAL_FONT_SIZE = 20;
    ClearBackground(BLUE);
    DrawText("LOBBY", WIDTH / 2 - MeasureText("LOBBY", 2 * NORMAL_FONT_SIZE) / 2, 100, 2 * NORMAL_FONT_SIZE, RAYWHITE);

    std::ostringstream oss;
    oss << "Pollen: " << player.get_pollen() << " / " << player.get_backpack_capacity();
    DrawText(oss.str().c_str(), WIDTH - oss.str().size() * 12, 20, NORMAL_FONT_SIZE, RAYWHITE);
    oss.str("");

    oss << "Honey: " << player.get_honey();
    DrawText(oss.str().c_str(), 2 * NORMAL_FONT_SIZE, 20, NORMAL_FONT_SIZE, RAYWHITE);

    std::vector<std::string> buttons;
    buttons.push_back("[U]pgrades");
    buttons.push_back("[S]tats");
    buttons.push_back("Sell [H]oney");
    buttons.push_back(state == GameState::FieldSelection ? "[B]ack" : "[F]ields");

    const int AVERAGE_LETTERS = 10, GAP = 50;
    for (int i = 0; i < (int)buttons.size(); ++i) {
        DrawText(buttons[i].c_str(), WIDTH - NORMAL_FONT_SIZE * AVERAGE_LETTERS, HEIGHT - 250 + i * GAP, NORMAL_FONT_SIZE, RAYWHITE);
    }

    std::vector<Texture2D> fields_icons;
    fields_icons.push_back(assets->get_strawberry_icon());
    fields_icons.push_back(assets->get_sunflower_icon());
    fields_icons.push_back(assets->get_clover_icon());

    fields_icons.push_back(assets->get_cactus_icon());
    fields_icons.push_back(assets->get_cherry_icon());
    fields_icons.push_back(assets->get_orange_icon());

    fields_icons.push_back(assets->get_blueberry_icon());

    // display fields
    const int X_GAP = 116;
    const int Y_GAP = 80;
    const int TEXT_OFFSET = 5;

    for (int i = 0; i < (int)fields_icons.size(); ++i) {
        int field_icon_x = 350 + X_GAP * (i % 3);
        int field_icon_y = 200 + Y_GAP * (i / 3);

        DrawTexture(fields_icons[i], field_icon_x, field_icon_y, WHITE);
        if (state == GameState::FieldSelection) {
            DrawText(std::to_string(i + 1).c_str(),
                     field_icon_x + TEXT_OFFSET,
                     field_icon_y + TEXT_OFFSET,
                     20, BLACK);
        }
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
        return;
    }

    if (IsKeyPressed(KEY_U)) {
        state = GameState::Upgrades;
    } else if (IsKeyPressed(KEY_S)) {
        state = GameState::Stats;
    } else if (IsKeyPressed(KEY_H)) {
        PlaySound(assets->get_honey_sold_sound());

        int honey = player.get_pollen() * player.get_honey_per_pollen();
        player.set_total_honey(honey);
        player.set_honey(player.get_honey() + honey);
        player.set_pollen(0);
    } else if (IsKeyPressed(KEY_F)) {
        state = GameState::FieldSelection;
    }
}

void Game::game_field() {
    ClearBackground(BLUE);

    std::ostringstream oss;
    oss << "Pollen: " << player.get_pollen() << " / " << player.get_backpack_capacity();
    DrawText(oss.str().c_str(), WIDTH / 2 - oss.str().size() * 10, 20, 30, RAYWHITE);
    DrawText("SPACE to collect pollen", WIDTH / 2 - MeasureText("SPACE to collect pollen", 20) / 2, HEIGHT - 100, 20, WHITE);
    DrawText("[B]ack", WIDTH / 2 - MeasureText("[B]ack", 20) / 2, HEIGHT - 50, 20, WHITE);

    const int FIELD_X = 100;
    const int FIELD_Y = 120;
    const int FIELD_WIDTH = 512;
    const int FILED_HEIGHT = 256;
    std::vector<Field> fields = Field::all_fields(assets);
    Field current_field = fields[state];
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

    std::ostringstream oss;
    oss << "Honey: " << player.get_honey();
    DrawText(oss.str().c_str(), 2 * NORMAL_FONT_SIZE, 20, NORMAL_FONT_SIZE, RAYWHITE);

    DrawText("UPGRADES:", WIDTH / 2 - MeasureText("UPGRADES:", 2 * NORMAL_FONT_SIZE) / 2, 100, 2 * NORMAL_FONT_SIZE, RAYWHITE);
    DrawText("[B]ack", WIDTH / 2 - MeasureText("[B]ack", NORMAL_FONT_SIZE) / 2, HEIGHT - 100, NORMAL_FONT_SIZE, RAYWHITE);

    const int CARD_WIDTH = 128;
    const int CARD_HEIGHT = 64;
    const int POS_X_MARGIN = 50;
    const int POS_Y_MARGIN = 100;
    const int gap = 10;
    const int COLS = 2;

    std::array<std::unique_ptr<Upgrade>, 4> upgrades;
    upgrades[0] = std::make_unique<CollectAmountUpgrade>(100,
                  player.get_total_upgrades(PlayerUpgrade::CollectAmount),
                  assets->get_collect_amount_upgrade_icon());
    upgrades[1] = std::make_unique<BackpackUpgrade>(100,
                  player.get_total_upgrades(PlayerUpgrade::BackpackCapacity),
                  assets->get_backpack_upgrade_icon());
    upgrades[2] = std::make_unique<HoneyPerPollenUpgrade>(100,
                  player.get_total_upgrades(PlayerUpgrade::HoneyPerPollen),
                  assets->get_honey_per_pollen_upgrade_icon());
    upgrades[3] = std::make_unique<BeeUpgrade>(100,
                  player.get_total_upgrades(PlayerUpgrade::NewBee),
                  assets->get_bee_egg_icon(),
                  player.get_total_bees_of_type(BeeColor::Red),
                  player.get_total_bees_of_type(BeeColor::Blue),
                  player.get_total_bees_of_type(BeeColor::White));

    const int POS_X = WIDTH / 2 - CARD_WIDTH - POS_X_MARGIN / 2, POS_Y = 200;
    for (int i = 0; i < (int)upgrades.size(); ++i) {
        int pos_x = POS_X + (CARD_WIDTH + POS_X_MARGIN) * (i % COLS);
        int pos_y = POS_Y + (CARD_HEIGHT + POS_Y_MARGIN) * (i / COLS);

        DrawTexture(upgrades[i]->get_icon(), pos_x, pos_y, WHITE);

        DrawText(std::to_string(i + 1).c_str(),
                 pos_x + gap,
                 pos_y + gap,
                 20, BLACK);

        // dynamic dispatch
        std::ostringstream oss;
        oss << upgrades[i]->get_price() << " H";
        DrawText(oss.str().c_str(),
                 pos_x + CARD_WIDTH / 2 - MeasureText(oss.str().c_str(), 20),
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

                // dynamic dispatch
                upgrades[i]->purchase(player);
            }
        }
    }
}

void Game::game_stats() {
    ClearBackground(RED);
    const int FONT_SIZE = 22;
    DrawText("STATS:", WIDTH / 2 - MeasureText("STATS:", FONT_SIZE), 30, 2 * FONT_SIZE, RAYWHITE);
    DrawText("[B]ack", WIDTH / 2 - MeasureText("[B]ack:", FONT_SIZE), HEIGHT - 30, FONT_SIZE, RAYWHITE);

    std::vector<std::pair<std::string, int>> stats;
    stats.push_back({"Total honey: ", player.get_total_honey()});
    stats.push_back({"Total bees: ", player.get_total_bees()});
    stats.push_back({"Red bees: ", player.get_total_bees_of_type(BeeColor::Red)});
    stats.push_back({"Blue bees: ", player.get_total_bees_of_type(BeeColor::Blue)});
    stats.push_back({"White bees: ", player.get_total_bees_of_type(BeeColor::White)});
    stats.push_back({"Red pollen multiplier: ", player.get_red_pollen_multiplier()});
    stats.push_back({"Blue pollen multiplier: ", player.get_blue_pollen_multiplier()});
    stats.push_back({"White pollen multiplier: ", player.get_blue_pollen_multiplier()});
    stats.push_back({"Honey per pollen: ", player.get_honey_per_pollen()});
    stats.push_back({"Collect amount: ", player.get_collect_amount()});
    stats.push_back({"Backpack upgrades: ", player.get_total_upgrades(PlayerUpgrade::BackpackCapacity)});
    stats.push_back({"Collect amount upgrades: ", player.get_total_upgrades(PlayerUpgrade::CollectAmount)});
    stats.push_back({"Honey per pollen upgrades: ", player.get_total_upgrades(PlayerUpgrade::HoneyPerPollen)});

    const int GAP = 24;
    const int BASE = 100;
    const int NORMAL_FONT_SIZE = 20;

    for (int row = 0; row < (int)stats.size(); ++row) {
        std::ostringstream oss;
        oss << stats[row].first << stats[row].second;
        std::string fmt = oss.str();
        DrawText(fmt.c_str(), 224, BASE + (row + 1) * GAP, NORMAL_FONT_SIZE, RAYWHITE);
    }

    if (IsKeyPressed(KEY_B)) {
        state = GameState::Lobby;
    }
}

void Game::draw_state() {
    // this assumes the flower fields will be always first in the enum
    if (state <= BlueberryField) {
        game_field();
    } else if (state == MainMenu) {
        game_main_menu();
    } else if (state == Lobby || state == FieldSelection) {
        game_lobby();
    } else if (state == Upgrades) {
        game_upgrades();
    } else if (state == Stats) {
        game_stats();
    }
}
