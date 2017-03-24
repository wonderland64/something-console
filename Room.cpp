#include "Room.hh"
#include "Random.hh"
#include "Tile.hh"

const int Room::minRoomSize_ = 5;

Room::Room() : y_(0), x_(0), height_(0), width_(0) {}
Room::Room(int y, int x, int height, int width) :y_(y), x_(x), height_(height), width_(width) {}

int Room::centerX() const {
    return x_ + (width_ / 2);
}
int Room::centerY() const {
    return y_ + (height_ / 2);
}

bool Room::generateRoom(const roomVec& rooms, int maxRoomHeight, int maxRoomWidth,
                              int height, int width) {
    int maxFails = 100;
    Random rand;

    while (maxFails > 0) {
        height_ = rand.next(minRoomSize_, maxRoomHeight);
        width_ = rand.next(minRoomSize_, maxRoomWidth);
        y_ = rand.next(0, height - 1 - height_);
        x_ = rand.next(0, width - 1 - width_);

        if (isRoomValid(rooms)) {
            return true;
        }
        --maxFails;
    }
    return false;
}

void Room::addToLevel(tileAtFunc tileAt) const {
    int width = x_ + width_;
    int height = y_ + height_;

    for (int y = y_; y != height + 1; ++y) {
        for (int x = x_; x != width + 1; ++x) {
            if (y == y_ || y == height || x == x_ || x == width) {
                tileAt(y, x)->setTileType(TileType::WALL);
            }
            else {
                tileAt(y, x)->setTileType(TileType::FLOOR);
            }
        }
    }
}

bool Room::isRoomValid(const roomVec& rooms) const {
    for (auto it = rooms.cbegin(); it != rooms.cend(); ++it) {
        if (isOverlapping(*it)) {
            return false;
        }
    }
    return true;
}
bool Room::isOverlapping(const Room& room) const {
    return (isOverlappingX(room) && isOverlappingY(room));
    // if (isOverlappingX(room) && isOverlappingY(room)) {
    //     return true;
    // }
    // return false;
}

// A one function solution to isOverlapping. Overly complex, and the calling code is too long.
// It does reduce code reuse tho...

// #include <functional>
// bool Room::isOverlappingAxis(Room room, std::function<void(Room r, int pos, int size)> getData) {
//     int r1Pos, r2Pos;
//     int r1Size, r2Size;
//     getData(*this, r1Pos, r1Size);
//     getData(room, r2Pos, r2Size);

//     if (r1Pos < r2Pos) {
//         return !(r1Pos + r1Size < r2Pos);
//     }
//     return !(r2Pos + r2Size < r1Pos);
//     isOverlappingAxis(this, [](Room r, int& pos, int& size) { pos = r.x_; size = r.width_; });
// }

bool Room::isOverlappingX(const Room& room) const {
    if (this->x_ < room.x_) {
        return !(this->x_ + this->width_ < room.x_);
    }
    return !(room.x_ + room.width_ < this->x_);
}
bool Room::isOverlappingY(const Room& room) const {
    if (this->y_ < room.y_) {
        return !(this->y_ + this->height_ < room.y_);
    }
    return !(room.y_ + room.height_ < this->y_);
}
