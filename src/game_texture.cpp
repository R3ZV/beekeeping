#include "game_texture.h"

GameTexture::GameTexture() {
    background = LoadTexture("./assets/background.png");
    strawberry_icon = LoadTexture("./assets/strawberry_icon.png");
    sunflower_icon = LoadTexture("./assets/sunflower_icon.png");
    backpack_upgrade_icon = LoadTexture("./assets/backpack_capacity.png");
    collect_amount_upgrade_icon = LoadTexture("./assets/collect_amount.png");
    honey_per_pollen_upgrade_icon = LoadTexture("./assets/honey_per_pollen.png");
    bee_egg_icon = LoadTexture("./assets/bee_egg.png");
    red_bee_face = LoadTexture("./assets/red_bee.png");
    blue_bee_face = LoadTexture("./assets/blue_bee.png");
    white_bee_face = LoadTexture("./assets/white_bee.png");
}

GameTexture::~GameTexture() {
    UnloadTexture(background);
    UnloadTexture(strawberry_icon);
    UnloadTexture(sunflower_icon);
    UnloadTexture(backpack_upgrade_icon);
    UnloadTexture(collect_amount_upgrade_icon);
    UnloadTexture(honey_per_pollen_upgrade_icon);
    UnloadTexture(bee_egg_icon);
    UnloadTexture(red_bee_face);
    UnloadTexture(blue_bee_face);
    UnloadTexture(white_bee_face);
}

GameTexture::GameTexture (const GameTexture& other) {
    background = other.background;
    strawberry_icon = other.strawberry_icon;
    sunflower_icon = other.sunflower_icon;
    backpack_upgrade_icon = other.backpack_upgrade_icon;
    collect_amount_upgrade_icon = other.collect_amount_upgrade_icon;
    honey_per_pollen_upgrade_icon = other.honey_per_pollen_upgrade_icon;
    bee_egg_icon = other.bee_egg_icon;
    red_bee_face = other.red_bee_face;
    blue_bee_face = other.blue_bee_face;
    white_bee_face = other.white_bee_face;
}

Texture2D GameTexture::get_background() {
    return background;
}

Texture2D GameTexture::get_strawberry_icon() {
    return strawberry_icon;
}

Texture2D GameTexture::get_backpack_upgrade_icon() {
    return backpack_upgrade_icon;
}

Texture2D GameTexture::get_collect_amount_upgrade_icon() {
    return collect_amount_upgrade_icon;
}

Texture2D GameTexture::get_honey_per_pollen_upgrade_icon() {
    return honey_per_pollen_upgrade_icon;
}

Texture2D GameTexture::get_bee_egg_icon() {
    return bee_egg_icon;
}

Texture2D GameTexture::get_red_bee_face() {
    return red_bee_face;
}

Texture2D GameTexture::get_blue_bee_face() {
    return blue_bee_face;
}

Texture2D GameTexture::get_white_bee_face() {
    return white_bee_face;
}
