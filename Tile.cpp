#include "Tile.hh"
#include "Actor.hh"
#include "LevelController.hh"
#include <stdexcept>

Tile::redrawTileFunction Tile::redrawTile = &LevelController::redrawTile;

Tile::Tile(unsigned int y, unsigned int x, TileType type) : y_(y), x_(x), type_(type) {}

char Tile::getGraphic() const {
    // A mover (better name) tells a tile when it moves on to it. but not when it leaves (it could though).
    // A mover would need access to levelArray to tell a tile anything. Avoiding this would be swell.
    // How would a tile know if a mover is there without a list of movers or someone telling it.
    // Maybe the mover tells the levelController and the controller tells the tile(s).
    // if (myMover->x == x && myMover->y == y) { return myMover->graphic };
    // else { myMover = 0; }
    // if (equipment is here) { return equipment.graphic; }
    // return type_;
    if (occupant_ != 0) {
        return '@';
    }

    return type_;
}

void Tile::coordinates(int& y, int& x) const {
    y = y_ + y;
    x = x_ + x;
}

void Tile::setTileType(TileType type) {
    if (type_ == type) {
        //return;
    }
    else if (type_ == TileType::EMPTY) {
        type_ = type;
        //return;
    }
    else if (type_ == TileType::WALL) {
        type_ = type;
    }
    //redrawTile(y_, x_, getGraphic());
    return;
}

void Tile::removeOccupant() {
    if (occupant_ == nullptr) {
        throw std::domain_error("no occupant on tile");
    }
    occupant_ = 0;
    redrawTile(y_, x_, getGraphic());
}
void Tile::addOccupant(const Actor& actor) {
    occupant_ = &actor;
    redrawTile(y_, x_, getGraphic());
}
bool Tile::isPassable() {
    if (occupant_ != 0) {
        return false;
    }
    return type_ == TileType::FLOOR;
}
