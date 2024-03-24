#include "asset_manager.h"

std::ostream &operator<<(std::ostream &out, const AssetManager &manager) {
    out << "Loaded: " << manager.loaded_textures << " textures\n";
    return out;
}

AssetManager::AssetManager() {
    background = LoadTexture("./assets/background.png");
    loaded_textures++;

    strawberry_icon = LoadTexture("./assets/strawberry_icon.png");
    loaded_textures++;

    strawberry_field = LoadTexture("./assets/strawberry_field.png");
    loaded_textures++;

    sunflower_icon = LoadTexture("./assets/sunflower_icon.png");
    loaded_textures++;

    sunflower_field = LoadTexture("./assets/sunflower_field.png");
    loaded_textures++;

    clover_icon = LoadTexture("./assets/clover_icon.png");
    loaded_textures++;

    clover_field = LoadTexture("./assets/clover_field.png");
    loaded_textures++;

    cactus_icon = LoadTexture("./assets/cactus_icon.png");
    loaded_textures++;

    cactus_field = LoadTexture("./assets/cactus_field.png");
    loaded_textures++;

    cherry_icon = LoadTexture("./assets/cherry_icon.png");
    loaded_textures++;

    cherry_field = LoadTexture("./assets/cherry_field.png");
    loaded_textures++;

    orange_icon = LoadTexture("./assets/orange_icon.png");
    loaded_textures++;

    orange_field = LoadTexture("./assets/orange_field.png");
    loaded_textures++;

    blueberry_icon = LoadTexture("./assets/blueberry_icon.png");
    loaded_textures++;

    blueberry_field = LoadTexture("./assets/blueberry_field.png");
    loaded_textures++;

    backpack_upgrade_icon = LoadTexture("./assets/backpack_capacity.png");
    loaded_textures++;

    collect_amount_upgrade_icon = LoadTexture("./assets/collect_amount.png");
    loaded_textures++;

    honey_per_pollen_upgrade_icon = LoadTexture("./assets/honey_per_pollen.png");
    loaded_textures++;

    bee_egg_icon = LoadTexture("./assets/bee_egg.png");
    loaded_textures++;

    red_bee_face = LoadTexture("./assets/red_bee.png");
    loaded_textures++;

    blue_bee_face = LoadTexture("./assets/blue_bee.png");
    loaded_textures++;

    white_bee_face = LoadTexture("./assets/white_bee.png");
    loaded_textures++;
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
}

AssetManager::AssetManager (const AssetManager& other) {
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
