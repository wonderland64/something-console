#ifndef GUARD_Action_hh
#define GUARD_Action_hh

#include <memory>

class IAction {
public:
    virtual ~IAction() = default;
    virtual bool tickDown() = 0;
    virtual bool validAction() = 0;
};

// If R is not specified R defaults to void, result: if R is not specified F have to return void,
// if R is specified F have to return R. Seems to work.
// tickDown() returns true if the action is still valid, and false otherwise.

// TODO: should probably refine the boolean bit.
template<class T, class F, class R = void>
class Action : public IAction{
public:
    Action(T ticks, F callback, R* objectToModify = nullptr)
        : ticks_(ticks), objectToModify_(objectToModify), callback_(callback), invoked_(false) {}

    bool tickDown() override {
        if (ticks_ == 0 && !invoked_) {
            *objectToModify_ = callback_();
            invoked_ = true;
        }
        --ticks_;
        return !invoked_;
    }

    bool validAction() override {
        return !invoked_;
    }

private:
    T ticks_;
    R* objectToModify_;
    F callback_;
    bool invoked_;
};

#endif
