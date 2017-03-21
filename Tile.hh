#ifndef GUARD_Tile_hh
#define GUARD_Tile_hh

class Actor;
class LevelController;
//#include "Level.hh"
// Baseline Tile type that should rarely change. getGraphic should be more complex returning the CURRENT graphic, not just
// the tile type graphic.

enum TileType : char {
    EMPTY = ' ',
    WALL = '#',
    FLOOR = '.',
};

class Tile {
    friend class Level;
    //friend class Room;

public:
    using redrawTileFunction = void(*)(unsigned int, unsigned int, char);

    Tile(unsigned int, unsigned int, TileType = TileType::EMPTY);

    char getGraphic() const;

private:
    unsigned int y_;
    unsigned int x_;

    TileType type_;
    const Actor* occupant_;
    static redrawTileFunction redrawTile;

    void coordinates(int&, int&) const;
    void setTileType(TileType);
    void removeOccupant();
    void addOccupant(const Actor&);
    bool isPassable();


};

#endif
