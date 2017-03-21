#ifndef GUARD_InputMode_hh
#define GUARD_InputMode_hh

#include <memory>

class GameController;
class MovementMode;
class InterfaceMode;

// Make MovementMode have a default in the switch
// that leads to a second mode "InterfaceMode" that will figure out
// what to do. Try to make it so that these two modes catch all scenarios
// with movementMode being the standard and falling through to InterfaceMode if
// it doesn't catch anything.

class InputMode {
public:
    virtual ~InputMode() = default;

    virtual std::unique_ptr<InputMode> handleInput(GameController&, int) = 0;
    //virtual std::unique_ptr<InputMode> updateState(InputMode&) = 0;
};

class MovementMode : public InputMode {
public:
    virtual std::unique_ptr<InputMode> handleInput(GameController&, int) override;
    //virtual std::unique_ptr<InputMode> updateState(InputMode&) override;
};

class InterfaceMode : public InputMode {
    virtual std::unique_ptr<InputMode> handleInput(GameController&, int) override;
};

#endif
