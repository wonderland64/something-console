#ifndef GUARD_Tile_hh
#define GUARD_Tile_hh

class Actor;

// Baseline Tile type that should rarely change. getGraphic should be more complex returning the CURRENT graphic, not just
// the tile type graphic.

enum TileType : char {
    EMPTY = ' ',
    WALL = '#',
    FLOOR = '.',
};

class Tile {
public:
    Tile(unsigned int y, unsigned int x, TileType tileType = TileType::EMPTY);

    bool canMoveInto() const;

    char graphic() const;

    void setTileType(TileType type);

    void removeOccupant();
    void addOccupant(const Actor& actor);

    // char getGraphic() const;

    // void coordinates(int&, int&) const;
    // void setTileType(TileType);

    // void changeOccupant();
    // void changeOccupant(const Actor&);

    // bool isPassable();


private:
    unsigned int y_;
    unsigned int x_;

    TileType type_;
    const Actor* occupant_;

};

#endif
