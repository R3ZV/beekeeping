#ifndef GAME_TEXTURE_H
#define GAME_TEXTURE_H

#include <raylib.h>

class GameTexture {
    Texture2D background;
    Texture2D strawberry_icon;
public:
    GameTexture ();
    GameTexture (const GameTexture& other);
    // ~GameTexture();
    Texture2D get_background();
    Texture2D get_strawberry_icon();
};

#endif // GAME_TEXTURE_H
