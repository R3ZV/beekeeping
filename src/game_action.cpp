#include "game_action.h"

GameAction::GameAction (
    double deelay,
    double timer,
    GameActionType type,
    std::string text,
    double pos_x,
    double pos_y,
    int font_size,
    Color color,
    double opacity
) :
    deelay(deelay),
    timer(timer),
    type(type),
    text(text),
    pos_x(pos_x),
    pos_y(pos_y),
    font_size(font_size),
    color(color),
    opacity(opacity)
{}

void GameAction::start_action() {
    switch (type) {
    case DisplayText:
        Color tint = color;
        tint.a -= opacity;
        DrawText(text.c_str(), pos_x, pos_y, font_size, tint);
        break;
    }
}

double GameAction::get_deelay() {
    return deelay;
}

double GameAction::get_timer() {
    return timer;
}

void GameAction::decrees_opacity(double amount) {
    opacity += amount;
    opacity = std::min(opacity, 255.0);
}
void GameAction::move_y(double amount) {
    pos_y -= amount;
}

double GameAction::get_opacity() {
    return color.a;
}
double GameAction::get_pos_y() {
    return pos_y;
}
