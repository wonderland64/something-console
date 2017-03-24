#ifndef GUARD_Level_hh
#define GUARD_Level_hh

#include "Room.hh"
#include "Tile.hh"
#include <vector>

class Level {
public:
    Level(int sizeY, int sizeX);

    //static Level Build(int sizeY, int sizeX, int roomAmount = 20);
    void generateLevel(int maxRoomHeight, int maxRoomWidth, int roomAmount);

    std::size_t width() const;
    std::size_t height() const;

    Tile* tileAt(int y, int x);

    const Room& randomRoom() const;

    //Tile* moveActor(const Actor&, Tile*, int, int);
    //Tile* randomTile();
    //void spawnActor(Actor&);
    //void printLevelArray();

private:
    std::vector<std::vector<Tile>> tiles_;
    std::vector<Room> rooms_;

    void addCorridor(const Room&, const Room&);
    void fixCorners(int, int);

    //void setTileType(int, int, TileType);
};

#endif
