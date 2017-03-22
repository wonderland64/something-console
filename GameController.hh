#ifndef GUARD_GameController_hh
#define GUARD_GameController_hh

#include "LevelController.hh"
#include "InputController.hh"
#include "Player.hh"
#include "UiController.hh"

class GameController {
public:
    GameController();
    //~GameController();
    GameController(const GameController&) = delete;
    GameController& operator=(const GameController&) = delete;

    void handleInput(int);
    void generateLevel(unsigned int = 10, unsigned int = 20, unsigned int = 20);
    void movePlayer(int, int);

private:
    LevelController levelController_;
    InputController inputController_;
    UiController uiController_;

    Player player_;

    void advanceTurn();
};

#endif
