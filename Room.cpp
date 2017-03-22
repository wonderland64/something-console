#include "Room.hh"
#include "Random.hh"
#include "Level.hh"
#include "Tile.hh"

const unsigned int Room::minRoomSize_;

Room::Room() : y0_(0), x0_(0), row_(0), col_(0) {}
Room::Room(unsigned int y0, unsigned int x0, unsigned int row, unsigned int col) :y0_(y0), x0_(x0), row_(row), col_(col) {
    //Room::minRoomSize_ = 5;
}

unsigned int Room::centerX() const noexcept {
    return x0_ + (col_ / 2);
}
unsigned int Room::centerY() const noexcept {
    return y0_ + (row_ / 2);
}

bool Room::generateRoom(const std::vector<Room>& rooms, unsigned int rowMax, unsigned int colMax,
                              unsigned int height, unsigned int width) {
    unsigned int maxFails = 100;
    Random rand;
    while (maxFails > 0) {
        row_ = rand.next(minRoomSize_, rowMax);
        col_ = rand.next(minRoomSize_, colMax);
        y0_ = rand.next(unsigned (int(0)), height - 1 - row_);
        x0_ = rand.next(unsigned(int(0)), width - 1 - col_);
        if (isRoomValid(rooms)) {
            return true;
        }
        else {
            --maxFails;
        }
    }
    return false;
}

void Room::addToLevel(setTileFunction setTile) {
    unsigned int width = x0_ + col_;
    unsigned int height = y0_ + row_;

    for (unsigned int y = y0_; y != height + 1; ++y) {
        for (unsigned int x = x0_; x != width + 1; ++x) {
            if (y == y0_ || y == height || x == x0_ || x == width) {
                setTile(y, x, TileType::WALL);
            }
            else {
                setTile(y, x, TileType::FLOOR);
            }
        }
    }
}

bool Room::isRoomValid(const std::vector<Room>& rooms) const {
    for (auto it = rooms.cbegin(); it != rooms.cend(); ++it) {
        if (isOverlapping(*it)) {
            return false;
        }
    }
    return true;
}
bool Room::isOverlapping(const Room& room) const {
    if (isOverlappingX(room) && isOverlappingY(room)) {
        return true;
    }
    return false;
}
bool Room::isOverlappingX(const Room& room) const {
    if (this->x0_ < room.x0_) {
        return !(this->x0_ + this->col_ < room.x0_);
    }
    return !(room.x0_ + room.col_ < this->x0_);
}
bool Room::isOverlappingY(const Room& room) const {
    if (this->y0_ < room.y0_) {
        return !(this->y0_ + this->row_ < room.y0_);
    }
    return !(room.y0_ + room.row_ < this->y0_);
}
