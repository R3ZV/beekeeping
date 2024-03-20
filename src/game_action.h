#ifndef GAME_ACTION_H
#define GAME_ACTION_H

#include <raylib.h>
#include <math.h>
#include <string>

enum GameActionType {
    DisplayText
};

class GameAction {
    double deelay;
    double timer;
    GameActionType type;
    std::string text;
    double pos_x;
    double pos_y;
    int font_size;
    Color color;
    double opacity;
public:
    GameAction(
        double deelay,
        double timer,
        GameActionType type,
        std::string text,
        double pos_x,
        double pos_y,
        int font_size,
        Color color,
        double opacity
    );

    void start_action();

    void decrees_opacity(double amount);
    void move_y(double amount);
    double get_deelay();
    double get_timer();
    double get_opacity();
    double get_pos_y();
};

#endif // GAME_ACTION_H
