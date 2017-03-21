#ifndef GUARD_Level_hh
#define GUARD_Level_hh

#include <vector>
#include "Room.hh"
#include "Tile.hh"

class Level {
public:
    Level(int, int);

    std::size_t width() const;
    std::size_t height() const;
    //const std::vector<Room>& getRooms() const;

    Tile* moveActor(const Actor&, Tile*, int, int);
    Tile* randomTile();
    void spawnActor(Actor&);

    void generateLevel(unsigned int, unsigned int, unsigned int);
    // Temp
    void printLevelArray();

private:
    std::vector<std::vector<Tile>> tiles_;
    std::vector<Room> rooms_;

    //void addToLevelArray(const Room&);
    void addCorridor(const Room&, const Room&);
    void fixCorners(unsigned int, unsigned int);

    void setTileType(unsigned int, unsigned int, TileType);

    void redrawTile(const Tile&) const;
};

#endif
