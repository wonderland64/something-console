#ifndef GUARD_InputController_hh
#define GUARD_InputController_hh

#include "InputMode.hh"
#include <memory>
class GameController;

class InputController {
public:
    InputController();
    void getInput(GameController&, int);

private:
    std::unique_ptr<InputMode> mode_;

    //void handleInput(GameController&, int);
};

#endif
