#include "asset_manager.h"

AssetManager::AssetManager() {
    background = LoadTexture("./assets/background.png");
    if (background.id <= 0) {
        throw std::runtime_error("Couldn't find background texture");
    }

    strawberry_icon = LoadTexture("./assets/strawberry_icon.png");
    if (strawberry_icon.id <= 0) {
        throw std::runtime_error("Couldn't find strawberry_icon texture");
    }

    strawberry_field = LoadTexture("./assets/strawberry_field.png");
    if (strawberry_field.id <= 0) {
        throw std::runtime_error("Couldn't find strawberry_field texture");
    }

    sunflower_icon = LoadTexture("./assets/sunflower_icon.png");
    if (sunflower_icon.id <= 0) {
        throw std::runtime_error("Couldn't find sunflower_icon texture");
    }

    sunflower_field = LoadTexture("./assets/sunflower_field.png");
    if (sunflower_field.id <= 0) {
        throw std::runtime_error("Couldn't find sunflower_field texture");
    }

    clover_icon = LoadTexture("./assets/clover_icon.png");
    if (clover_icon.id <= 0) {
        throw std::runtime_error("Couldn't find clover_icon texture");
    }

    clover_field = LoadTexture("./assets/clover_field.png");
    if (clover_field.id <= 0) {
        throw std::runtime_error("Couldn't find clover_field texture");
    }

    cactus_icon = LoadTexture("./assets/cactus_icon.png");
    if (cactus_icon.id <= 0) {
        throw std::runtime_error("Couldn't find cactus_icon texture");
    }

    cactus_field = LoadTexture("./assets/cactus_field.png");
    if (cactus_field.id <= 0) {
        throw std::runtime_error("Couldn't find cactus_field texture");
    }

    cherry_icon = LoadTexture("./assets/cherry_icon.png");
    if (cherry_icon.id <= 0) {
        throw std::runtime_error("Couldn't find cherry_icon texture");
    }

    cherry_field = LoadTexture("./assets/cherry_field.png");
    if (cherry_field.id <= 0) {
        throw std::runtime_error("Couldn't find cherry_field texture");
    }

    orange_icon = LoadTexture("./assets/orange_icon.png");
    if (orange_icon.id <= 0) {
        throw std::runtime_error("Couldn't find orange_icon texture");
    }

    orange_field = LoadTexture("./assets/orange_field.png");
    if (orange_field.id <= 0) {
        throw std::runtime_error("Couldn't find orange_field texture");
    }

    blueberry_icon = LoadTexture("./assets/blueberry_icon.png");
    if (blueberry_icon.id <= 0) {
        throw std::runtime_error("Couldn't find blueberry_icon texture");
    }

    blueberry_field = LoadTexture("./assets/blueberry_field.png");
    if (blueberry_field.id <= 0) {
        throw std::runtime_error("Couldn't find blueberry_field texture");
    }

    backpack_upgrade_icon = LoadTexture("./assets/backpack_capacity.png");
    if (backpack_upgrade_icon.id <= 0) {
        throw std::runtime_error("Couldn't find backpack_upgrade_icon texture");
    }

    collect_amount_upgrade_icon = LoadTexture("./assets/collect_amount.png");
    if (collect_amount_upgrade_icon.id <= 0) {
        throw std::runtime_error("Couldn't find collect_amount_upgrade_icon texture");
    }

    honey_per_pollen_upgrade_icon = LoadTexture("./assets/honey_per_pollen.png");
    if (honey_per_pollen_upgrade_icon.id <= 0) {
        throw std::runtime_error("Couldn't find honey_per_pollen_upgrade_icon texture");
    }

    bee_egg_icon = LoadTexture("./assets/bee_egg.png");
    if (bee_egg_icon.id <= 0) {
        throw std::runtime_error("Couldn't find bee_egg_icon texture");
    }

    red_bee_face = LoadTexture("./assets/red_bee.png");
    if (red_bee_face.id <= 0) {
        throw std::runtime_error("Couldn't find red_bee_face texture");
    }

    blue_bee_face = LoadTexture("./assets/blue_bee.png");
    if (blue_bee_face.id <= 0) {
        throw std::runtime_error("Couldn't find blue_bee_face texture");
    }

    white_bee_face = LoadTexture("./assets/white_bee.png");
    if (white_bee_face.id <= 0) {
        throw std::runtime_error("Couldn't find white_bee_face texture");
    }

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
