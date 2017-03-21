#ifndef GUARD_Actor_hh
#define GUARD_Actor_hh

#include "Action.hh"

class Level;
class Tile;

class Actor {
public:
    Actor(Level*, Tile*, char);
    virtual ~Actor() = default;

    void move(int, int);
    char graphic() const;
    void moveLevel(Level*, Tile*);

    bool progressAction();

private:
    Level* currentLevel_;
    Tile* tile_;

    char graphic_;

    std::unique_ptr<IAction> action_;
};

#endif
