#include "asset_manager.h"

AssetManager::AssetManager() {
    background = LoadTexture("./assets/background.png");
    strawberry_icon = LoadTexture("./assets/strawberry_icon.png");
    strawberry_field = LoadTexture("./assets/strawberry_field.png");
    sunflower_icon = LoadTexture("./assets/sunflower_icon.png");
    sunflower_field = LoadTexture("./assets/sunflower_field.png");
    clover_icon = LoadTexture("./assets/clover_icon.png");
    clover_field = LoadTexture("./assets/clover_field.png");
    cactus_icon = LoadTexture("./assets/cactus_icon.png");
    cactus_field = LoadTexture("./assets/cactus_field.png");
    cherry_icon = LoadTexture("./assets/cherry_icon.png");
    cherry_field = LoadTexture("./assets/cherry_field.png");
    orange_icon = LoadTexture("./assets/orange_icon.png");
    orange_field = LoadTexture("./assets/orange_field.png");
    blueberry_icon = LoadTexture("./assets/blueberry_icon.png");
    blueberry_field = LoadTexture("./assets/blueberry_field.png");
    backpack_upgrade_icon = LoadTexture("./assets/backpack_capacity.png");
    collect_amount_upgrade_icon = LoadTexture("./assets/collect_amount.png");
    honey_per_pollen_upgrade_icon = LoadTexture("./assets/honey_per_pollen.png");
    bee_egg_icon = LoadTexture("./assets/bee_egg.png");
    red_bee_face = LoadTexture("./assets/red_bee.png");
    blue_bee_face = LoadTexture("./assets/blue_bee.png");
    white_bee_face = LoadTexture("./assets/white_bee.png");
    collect_sound = LoadSound("./assets/collect.wav");
    purchase_sound = LoadSound("./assets/purchase.wav");
    egg_hatch_sound = LoadSound("./assets/bee-hatch.wav");
    honey_sold_sound = LoadSound("./assets/honey.mp3");
    ambient = LoadSound("./assets/ambient.mp3");
}

AssetManager::~AssetManager() {
    UnloadTexture(background);
    UnloadTexture(strawberry_icon);
    UnloadTexture(strawberry_field);
    UnloadTexture(sunflower_icon);
    UnloadTexture(sunflower_field);
    UnloadTexture(clover_icon);
    UnloadTexture(clover_field);
    UnloadTexture(cactus_icon);
    UnloadTexture(cactus_field);
    UnloadTexture(cherry_icon);
    UnloadTexture(cherry_field);
    UnloadTexture(orange_icon);
    UnloadTexture(orange_field);
    UnloadTexture(blueberry_icon);
    UnloadTexture(blueberry_field);
    UnloadTexture(backpack_upgrade_icon);
    UnloadTexture(collect_amount_upgrade_icon);
    UnloadTexture(honey_per_pollen_upgrade_icon);
    UnloadTexture(bee_egg_icon);
    UnloadTexture(red_bee_face);
    UnloadTexture(blue_bee_face);
    UnloadTexture(white_bee_face);

    UnloadSound(collect_sound);
    UnloadSound(purchase_sound);
    UnloadSound(egg_hatch_sound);
    UnloadSound(honey_sold_sound);
}

Texture2D AssetManager::get_background() const {
    return background;
}

Texture2D AssetManager::get_strawberry_icon() const {
    return strawberry_icon;
}

Texture2D AssetManager::get_strawberry_field() const {
    return strawberry_field;
}

Texture2D AssetManager::get_sunflower_icon() const {
    return sunflower_icon;
}

Texture2D AssetManager::get_sunflower_field() const {
    return sunflower_field;
}

Texture2D AssetManager::get_clover_icon() const {
    return clover_icon;
}

Texture2D AssetManager::get_clover_field() const {
    return clover_field;
}

Texture2D AssetManager::get_cactus_icon() const {
    return cactus_icon;
}

Texture2D AssetManager::get_cactus_field() const {
    return cactus_field;
}

Texture2D AssetManager::get_cherry_icon() const {
    return cherry_icon;
}

Texture2D AssetManager::get_cherry_field() const {
    return cherry_field;
}

Texture2D AssetManager::get_orange_icon() const {
    return orange_icon;
}

Texture2D AssetManager::get_orange_field() const {
    return orange_field;
}

Texture2D AssetManager::get_blueberry_icon() const {
    return blueberry_icon;
}

Texture2D AssetManager::get_blueberry_field() const {
    return blueberry_field;
}

Texture2D AssetManager::get_backpack_upgrade_icon() const {
    return backpack_upgrade_icon;
}

Texture2D AssetManager::get_collect_amount_upgrade_icon() const {
    return collect_amount_upgrade_icon;
}

Texture2D AssetManager::get_honey_per_pollen_upgrade_icon() const {
    return honey_per_pollen_upgrade_icon;
}

Texture2D AssetManager::get_bee_egg_icon() const {
    return bee_egg_icon;
}

Texture2D AssetManager::get_red_bee_face() const {
    return red_bee_face;
}

Texture2D AssetManager::get_blue_bee_face() const {
    return blue_bee_face;
}

Texture2D AssetManager::get_white_bee_face() const {
    return white_bee_face;
}

Sound AssetManager::get_collect_sound() {
    return collect_sound;
}

Sound AssetManager::get_egg_hatch_sound() {
    return egg_hatch_sound;
}

Sound AssetManager::get_purchase_sound() {
    return purchase_sound;
}

Sound AssetManager::get_honey_sold_sound() {
    return honey_sold_sound;
}

Sound AssetManager::get_ambient() {
    return ambient;
}
