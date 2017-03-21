#include "InputMode.hh"
#include "GameController.hh"

using unique_ptr = std::unique_ptr<InputMode>;

std::unique_ptr<InputMode> MovementMode::handleInput(GameController& gc, int input) {
    switch (input) {
    case 360: // num 1
        gc.movePlayer(1, -1);
        break;
    case 258: // num 2
      gc.movePlayer(1, 0);
        break;
    case 338: // num 3
        gc.movePlayer(1, 1);
        break;
    case 260: // num 4
        gc.movePlayer(0, -1);
        break;
    case 350: // num 5
        gc.movePlayer(0, 0);
        break;
    case 261: // num 6
        gc.movePlayer(0, 1);
        break;
    case 262: // num7
        gc.movePlayer(-1, -1);
        break;
    case 259: // num 8
        gc.movePlayer(-1, 0);
        break;
    case 339: // num 9
        gc.movePlayer(-1, 1);
        break;
    default:
        return std::make_unique<InterfaceMode>();
        break;
    }
    return 0;
}

std::unique_ptr<InputMode> InterfaceMode::handleInput(GameController& gc, int input) {
    switch (input) {
    case 32:
        gc.generateLevel(10, 20, 20);
        break;
    }
    return std::make_unique<MovementMode>();
}

