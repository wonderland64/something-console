#include "InputController.hh"

InputController::InputController() : mode_(std::unique_ptr<InputMode>(new MovementMode)) {}

void InputController::getInput(GameController& gc, int input) {
    std::unique_ptr<InputMode> newMode = mode_->handleInput(gc, input);

    if (newMode != nullptr) {
        mode_ = std::move(newMode);
        mode_->handleInput(gc, input);
    }
}
