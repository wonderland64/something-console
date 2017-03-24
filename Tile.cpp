#include "Tile.hh"
#include "Actor.hh"

Tile::Tile(unsigned int y, unsigned int x, TileType tileType) : y_(y), x_(x), type_(tileType), occupant_(nullptr) {}

bool Tile::canMoveInto() const {
    return (type_ == TileType::FLOOR && occupant_ == nullptr);
}

char Tile::graphic() const {
    if (occupant_ != nullptr) {
        return occupant_->graphic();
    }

    return type_;
}

void Tile::setTileType(TileType type) {
    if (type_ == type) {
        return;
    }
    else if (type_ == TileType::EMPTY) {
        type_ = type;
        return;
    }
    else if (type_ == TileType::WALL) {
        type_ = type;
    }

    return;
}

void Tile::removeOccupant() {
    if (occupant_ == nullptr) {
        throw std::domain_error("Tile::removeOccupant: already nullptr");
    }
    occupant_ = nullptr;
}
void Tile::addOccupant(const Actor& actor) {
    if (occupant_ != nullptr) {
        throw std::domain_error("Tile::addOccupant: already occupied");
    }
    occupant_ = &actor;
}



// Tile::Tile(unsigned int y, unsigned int x, TileType type) : y_(y), x_(x), type_(type) {}

// char Tile::getGraphic() const {
//     // A mover (better name) tells a tile when it moves on to it. but not when it leaves (it could though).
//     // A mover would need access to levelArray to tell a tile anything. Avoiding this would be swell.
//     // How would a tile know if a mover is there without a list of movers or someone telling it.
//     // Maybe the mover tells the levelController and the controller tells the tile(s).
//     // if (myMover->x == x && myMover->y == y) { return myMover->graphic };
//     // else { myMover = 0; }
//     // if (equipment is here) { return equipment.graphic; }
//     // return type_;
//     if (occupant_ != nullptr) {
//         return '@';
//     }

//     return type_;
// }

// void Tile::coordinates(int& y, int& x) const {
//     y = y_ + y;
//     x = x_ + x;
// }

// void Tile::setTileType(TileType type) {
//     if (type_ == type) {
//         //return;
//     }
//     else if (type_ == TileType::EMPTY) {
//         type_ = type;
//         //return;
//     }
//     else if (type_ == TileType::WALL) {
//         type_ = type;
//     }
//     //redrawTile(y_, x_, getGraphic());
//     return;
// }

// void Tile::changeOccupant() {
//     if (occupant_ == nullptr) {
//         throw std::domain_error("no occupant on tile");
//     }
//     occupant_ = nullptr;
//     print_(y_, x_, getGraphic());
// }
// void Tile::changeOccupant(const Actor& actor) {
//     occupant_ = &actor;
//     print_(y_, x_, getGraphic());
// }

// bool Tile::isPassable() {
//     if (occupant_ != nullptr) {
//         return false;
//     }
//     return type_ == TileType::FLOOR;
// }

// // void Tile::redrawTile() {
// //     mvaddch(y_, x_, getGraphic());
// // }


