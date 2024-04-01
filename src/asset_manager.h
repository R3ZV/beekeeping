#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <ostream>
#include <raylib.h>

class AssetManager {
    int loaded_assets;
    Texture2D background;
    Texture2D strawberry_icon;
    Texture2D strawberry_field;
    Texture2D sunflower_icon;
    Texture2D sunflower_field;
    Texture2D clover_icon;
    Texture2D clover_field;
    Texture2D cactus_icon;
    Texture2D cactus_field;
    Texture2D cherry_icon;
    Texture2D cherry_field;
    Texture2D orange_icon;
    Texture2D orange_field;
    Texture2D blueberry_icon;
    Texture2D blueberry_field;
    Texture2D backpack_upgrade_icon;
    Texture2D collect_amount_upgrade_icon;
    Texture2D honey_per_pollen_upgrade_icon;
    Texture2D bee_egg_icon;
    Texture2D red_bee_face;
    Texture2D blue_bee_face;
    Texture2D white_bee_face;

    Sound ambient;
    Sound honey_sold_sound;
    Sound collect_sound;
    Sound egg_hatch_sound;
    Sound purchase_sound;
public:
    AssetManager();
    ~AssetManager();
    Texture2D get_background() const;
    Texture2D get_strawberry_icon() const;
    Texture2D get_strawberry_field() const;
    Texture2D get_sunflower_icon() const;
    Texture2D get_sunflower_field() const;
    Texture2D get_clover_icon() const;
    Texture2D get_clover_field() const;
    Texture2D get_cactus_icon() const;
    Texture2D get_cactus_field() const;
    Texture2D get_cherry_icon() const;
    Texture2D get_cherry_field() const;
    Texture2D get_orange_icon() const;
    Texture2D get_orange_field() const;
    Texture2D get_blueberry_icon() const;
    Texture2D get_blueberry_field() const;
    Texture2D get_backpack_upgrade_icon() const;
    Texture2D get_collect_amount_upgrade_icon() const;
    Texture2D get_honey_per_pollen_upgrade_icon() const;
    Texture2D get_bee_egg_icon() const;
    Texture2D get_red_bee_face() const;
    Texture2D get_blue_bee_face() const;
    Texture2D get_white_bee_face() const;

    Sound get_collect_sound();
    Sound get_egg_hatch_sound();
    Sound get_purchase_sound();
    Sound get_honey_sold_sound();
    Sound get_ambient();
};

#endif // GAME_TEXTURE_H
