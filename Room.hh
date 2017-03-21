#ifndef GUARD_Room_hh
#define GUARD_Room_hh

//#include "Tile.hh"
#include <vector>
#include <functional>

class Level;
//class Tile;
enum TileType : char;

class Room {
private:
    using setTileFunction = std::function<void(unsigned int, unsigned int, TileType)>;

public:
    Room();
    Room(unsigned int, unsigned int, unsigned int, unsigned int);

    unsigned int centerX() const noexcept;
    unsigned int centerY() const noexcept;

    const bool generateRoom(const std::vector<Room>&, unsigned int, unsigned int, unsigned int, unsigned int);

    void addToLevel(setTileFunction);

private:
    unsigned int y0_;
    unsigned int x0_;
    unsigned int row_;
    unsigned int col_;

    static const unsigned int minRoomSize_ = 5;

    const bool isRoomValid(const std::vector<Room>&) const;
    // Helper functions to isRoomValid.
    const bool isOverlapping(const Room&) const;
    const bool isOverlappingX(const Room&) const;
    const bool isOverlappingY(const Room&) const;
};

#endif
