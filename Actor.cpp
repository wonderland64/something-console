#include "Actor.hh"
#include "Level.hh"

Actor::Actor(Level* level, Tile* tile, char graphic) : currentLevel_(level), tile_(tile), graphic_(graphic) {}

void Actor::move(int y, int x) {
    if (y == 0 && x == 0) {
        return;
    }
    tile_ = currentLevel_->moveActor(*this, tile_, y, x);
}
char Actor::graphic() const {
    return graphic_;
}
void Actor::moveLevel(Level* level, Tile* tile) {
    currentLevel_ = level;
    tile_ = tile;
}

// void Actor::setTile(Tile* tile) {
//     this->tile_ = tile;
// }
// void Actor::setCurrentLevel(Level* currentLevel) {
//     this->currentLevel_ = currentLevel;
// }
