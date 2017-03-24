#ifndef GUARD_Room_hh
#define GUARD_Room_hh

#include <vector>
#include <functional>

class Level;
class Tile;

enum TileType : char;

class Room {
private:
    using tileAtFunc = std::function<Tile*(int y, int x)>;
    using roomVec = std::vector<Room>;

public:
    Room();
    Room(int y, int x, int height, int width);

    int centerX() const;
    int centerY() const;

    bool generateRoom(const roomVec& rooms, int, int, int, int);

    void addToLevel(tileAtFunc tileAt) const;

private:
    int y_;
    int x_;
    int height_;
    int width_;

    static const int minRoomSize_;

    bool isRoomValid(const roomVec& rooms) const;
    // Helper functions to isRoomValid.
    bool isOverlapping(const Room& room) const;
    bool isOverlappingX(const Room& room) const;
    bool isOverlappingY(const Room& room) const;
};

#endif
