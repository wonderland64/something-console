#ifndef GUARD_Actor_hh
#define GUARD_Actor_hh

#include <memory>

class Level;
class Tile;
class IAction;

class Actor {
public:
    Actor(char);
    virtual ~Actor() = default;

    char graphic() const;

    void move(int yDirection, int xDirection);

    bool validAction() const;
    bool progressAction() const;

    void place(Tile* tile);

private:
    Tile* tile_;
    char graphic_;

    std::unique_ptr<IAction> action_;
};

#endif
