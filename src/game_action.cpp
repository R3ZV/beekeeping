#include "game_action.h"

std::ostream &operator<<(std::ostream& out, const GameAction& action) {
    out << "Deelay: " << action.deelay << "\n";
    out << "Timer: " << action.timer << "\n";
    out << "Type: " << action.type << "\n";
    out << "Text: " << action.text << "\n";
    out << "X: " << action.pos_x << "\n";
    out << "Y: " << action.pos_y << "\n";
    out << "Opacity: " << action.opacity << "\n";
    out << "Font size: " << action.font_size << "\n";
    return out;
}

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

void GameAction::decrees_opacity(double amount) {
    opacity += amount;
    opacity = std::min(opacity, 255.0);
}
void GameAction::move_y(double amount) {
    pos_y -= amount;
}

double GameAction::get_deelay() const {
    return deelay;
}

double GameAction::get_timer()  const {
    return timer;
}

double GameAction::get_opacity() const {
    return color.a;
}
double GameAction::get_pos_y() const {
    return pos_y;
}
