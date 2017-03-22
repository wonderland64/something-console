#include "Actor.hh"
#include "Level.hh"

Actor::Actor(Level* level, Tile* tile, char graphic)
    : currentLevel_(level), tile_(tile), graphic_(graphic), action_(nullptr) {}

void Actor::move(int y, int x) {
    // if (y == 0 && x == 0) {
    //     return;
    // }
    //tile_ = currentLevel_->moveActor(*this, tile_, y, x);
    auto callback = [this, y, x]() { return currentLevel_->moveActor(*this, tile_, y, x); };
    action_ = std::make_unique<Action<int, decltype(callback), Tile*>>(0, callback, &tile_);
}
char Actor::graphic() const {
    return graphic_;
}
void Actor::moveLevel(Level* level, Tile* tile) {
    currentLevel_ = level;
    tile_ = tile;
}

bool Actor::progressAction() {
    if (action_ == nullptr) {
        return false;
    }
    return action_->tickDown();
}
