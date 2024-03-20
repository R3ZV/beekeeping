#ifndef GAME_TEXTURE_H
#define GAME_TEXTURE_H

#include <raylib.h>

class GameTexture {
    Texture2D background;
    Texture2D strawberry_icon;
    Texture2D sunflower_icon;
    Texture2D backpack_upgrade_icon;
    Texture2D collect_amount_upgrade_icon;
    Texture2D honey_per_pollen_upgrade_icon;
    Texture2D bee_egg_icon;
    Texture2D red_bee_face;
    Texture2D blue_bee_face;
    Texture2D white_bee_face;
public:
    GameTexture ();
    GameTexture (const GameTexture& other);
    ~GameTexture();
    Texture2D get_background();
    Texture2D get_strawberry_icon();
    Texture2D get_sunflower_icon();
    Texture2D get_backpack_upgrade_icon();
    Texture2D get_collect_amount_upgrade_icon();
    Texture2D get_honey_per_pollen_upgrade_icon();
    Texture2D get_bee_egg_icon();
    Texture2D get_red_bee_face();
    Texture2D get_blue_bee_face();
    Texture2D get_white_bee_face();
};

#endif // GAME_TEXTURE_H
