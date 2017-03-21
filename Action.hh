#ifndef GUARD_Action_hh
#define GUARD_Action_hh

#include <memory>

class IAction {
public:
    virtual ~IAction() = default;
    virtual void tickDown() = 0;
};


// If R is not specified R defaults to void, result: if R is not specified F have to return void,
// if R is specified F have to return R. Seems to work.
template<class T, class F, class R = void>
class Action : public IAction{
public:
    Action(T ticks, F callback, R objectToModify = nullptr)
        : ticks_(ticks), objectToModify_(objectToModify), callback_(callback) {}

    void tickDown() override {
        if (ticks_ == 0) {
            objectToModify_ = callback_();
        }
        --ticks_;
        return;
    }

private:
    T ticks_;
    R objectToModify_; 
    F callback_;
};

#endif
