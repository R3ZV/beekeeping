#ifndef GAME_ACTION_H
#define GAME_ACTION_H

#include <raylib.h>
#include <math.h>
#include <string>
#include <ostream>

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
    double get_deelay() const;
    double get_timer() const;
    double get_opacity() const;
    double get_pos_y() const;
};

#endif // GAME_ACTION_H
