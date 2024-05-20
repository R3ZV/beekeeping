#include "asset_manager.h"

void AssetManager::load_texture(Texture2D& texture, std::string path) {
    texture = LoadTexture(path.c_str());
    if (texture.id <= 0) {
        throw std::runtime_error("Couldn't find background texture");
    }
}

AssetManager::AssetManager() {
    load_texture(background, "./assets/background.png");
    load_texture(strawberry_icon, "./assets/strawberry_icon.png");
    load_texture(strawberry_field, "./assets/strawberry_field.png");
    load_texture(sunflower_icon, "./assets/sunflower_icon.png");
    load_texture(sunflower_field, "./assets/sunflower_field.png");
    load_texture(clover_icon, "./assets/clover_icon.png");
    load_texture(clover_field, "./assets/clover_field.png");
    load_texture(cactus_icon, "./assets/cactus_icon.png");
    load_texture(cactus_field, "./assets/cactus_field.png");
    load_texture(cherry_icon, "./assets/cherry_icon.png");
    load_texture(cherry_field, "./assets/cherry_field.png");
    load_texture(orange_icon, "./assets/orange_icon.png");
    load_texture(orange_field, "./assets/orange_field.png");
    load_texture(blueberry_icon, "./assets/blueberry_icon.png");
    load_texture(blueberry_field, "./assets/blueberry_field.png");
    load_texture(backpack_upgrade_icon, "./assets/backpack_capacity.png");
    load_texture(collect_amount_upgrade_icon, "./assets/collect_amount.png");
    load_texture(honey_per_pollen_upgrade_icon, "./assets/honey_per_pollen.png");
    load_texture(bee_egg_icon, "./assets/bee_egg.png");
    load_texture(red_bee_face, "./assets/red_bee.png");
    load_texture(blue_bee_face, "./assets/blue_bee.png");
    load_texture(white_bee_face, "./assets/white_bee.png");

    collect_sound = LoadSound("./assets/collect.wav");
    purchase_sound = LoadSound("./assets/purchase.wav");
    egg_hatch_sound = LoadSound("./assets/bee-hatch.wav");
    honey_sold_sound = LoadSound("./assets/honey.mp3");
    ambient = LoadSound("./assets/ambient.mp3");
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
