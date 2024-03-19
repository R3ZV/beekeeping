#ifndef GAME_ACTION_H
#define GAME_ACTION_H

#include <functional>

class GameAction {
    double deelay;
    std::function<void(void)> action;
public:
    GameAction(
        double deelay,
        std::function <void(void)> action
    );
    void start_action();

    double get_deelay();
};

#endif // GAME_ACTION_H
