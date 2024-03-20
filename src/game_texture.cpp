#include "game_texture.h"

GameTexture::GameTexture() {
    background = LoadTexture("./assets/background.png");
    strawberry_icon = LoadTexture("./assets/strawberry.png");
}

GameTexture::~GameTexture() {
    UnloadTexture(background);
    UnloadTexture(strawberry_icon);
}

GameTexture::GameTexture (const GameTexture& other) {
    background = other.background;
    strawberry_icon = other.strawberry_icon;
}

Texture2D GameTexture::get_background() {
    return background;
}

Texture2D GameTexture::get_strawberry_icon() {
    return strawberry_icon;
}
