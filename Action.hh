#ifndef GUARD_Action_hh
#define GUARD_Action_hh

#include <memory>

class IAction {
public:
    virtual ~IAction() = default;
    virtual void tickDown() = 0;
};

template<class T, class F>
class Action : public IAction{
public:
    Action(T ticks, F callback) : ticks_(ticks), callback_(callback) {}

    void tickDown() override {
        if (ticks_ == 0) {
            callback_();
        }
        --ticks_;
        return;
    }

private:
    T ticks_;
    F callback_;
};

#endif
