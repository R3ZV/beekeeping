#include "game_action.h"

GameAction::GameAction (
    double deelay,
    std::function <void(void)> action
) :
    deelay(deelay),
    action(action)
{}

void GameAction::start_action() {
    action();
}

double GameAction::get_deelay() {
    return deelay;
}
