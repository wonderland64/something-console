#include "Level.hh"
#include "Room.hh"
#include "Tile.hh"
#include "Random.hh"
#include "Actor.hh"
#include <ncurses.h>

Level::Level(int sizeY, int sizeX) : tiles_() {
    for (int y = 0; y != sizeY; ++y) {
        tiles_.push_back(std::vector<Tile>());
        for (int x = 0; x != sizeX; ++x) {
            tiles_[y].push_back(Tile(y, x));
        }
    }
}

std::size_t Level::width() const {
    return tiles_[0].size() - 1;
}
std::size_t Level::height() const {
    return tiles_.size() - 1;
}

Tile* Level::moveActor(const Actor& actor, Tile* tile, int y, int x) {
    tile->coordinates(y, x);
    Tile* newTile = &tiles_[y][x];
    //tile->isPassable(); later add Actor&.
    if (newTile->isPassable()) {
        tile->removeOccupant();
        redrawTile(*tile);
        newTile->addOccupant(actor);
        redrawTile(*newTile);
        return newTile;
    }
    return tile;
}
Tile* Level::randomTile() {
    Random rand;
    Room& room = rooms_[rand.next(size_t(0), rooms_.size())];
    return &tiles_[room.centerY()][room.centerX()];
}
void Level::spawnActor(Actor& actor) {
    Tile* tile = randomTile();
    actor.moveLevel(this, tile);
    tile->addOccupant(actor);
}

void Level::generateLevel(unsigned int roomAmount, unsigned int rowMax, unsigned int colMax) {
    if (rowMax > height()) {
        rowMax = height() - 1;
    }
    if (colMax > width()) {
        colMax = width() - 1;
    }
    for (unsigned int i = 0; i != roomAmount; ++i) {
        Room room;
        if (room.generateRoom(rooms_, rowMax, colMax, height(), width()) == false) {
            return;
        }
        rooms_.push_back(room);
        auto setTile = [this](unsigned int y, unsigned int x, TileType type) { setTileType(y, x, type); };
        room.addToLevel(setTile);
        if (i != 0) {
            addCorridor(rooms_[i], rooms_[i - 1]);
        }
    }
}

void Level::addCorridor(const Room& r1, const Room& r2) {
    unsigned int r1CenterX = r1.centerX();
    unsigned int r1CenterY = r1.centerY();
    unsigned int r2CenterX = r2.centerX();
    unsigned int r2CenterY = r2.centerY();

    while (r1CenterX != r2CenterX) {
        r1CenterX += r1CenterX > r2CenterX ? -1 : 1;
        Tile& top = tiles_[r1CenterY - 1][r1CenterX];
        Tile& middle = tiles_[r1CenterY][r1CenterX];
        Tile& bottom = tiles_[r1CenterY + 1][r1CenterX];

        top.setTileType(TileType::WALL);
        bottom.setTileType(TileType::WALL);
        middle.setTileType(TileType::FLOOR);
    }
    fixCorners(r1CenterY, r1CenterX);

    while (r1CenterY != r2CenterY) {
        Tile& left = tiles_[r1CenterY][r1CenterX - 1];
        Tile& center = tiles_[r1CenterY][r1CenterX];
        Tile& right = tiles_[r1CenterY][r1CenterX + 1];

        left.setTileType(TileType::WALL);
        center.setTileType(TileType::FLOOR);
        right.setTileType(TileType::WALL);

        r1CenterY += r1CenterY > r2CenterY ? -1 : 1;
    }
}
void Level::fixCorners(unsigned int y, unsigned int x) {
    tiles_[y - 1][x - 1].setTileType(TileType::WALL);
    tiles_[y - 1][x + 1].setTileType(TileType::WALL);
    tiles_[y + 1][x - 1].setTileType(TileType::WALL);
    tiles_[y + 1][x + 1].setTileType(TileType::WALL);
}

void Level::setTileType(unsigned int y, unsigned int x, TileType type) {
    if (y > height() || x > width()) {
        throw std::domain_error("Level::setTileType: out of range");
    }
    tiles_[y][x].setTileType(type);
}

void Level::printLevelArray() {
    using vector_size = std::vector<std::vector<char>>::size_type;
    for (vector_size y = 0; y != height(); ++y) {
        for (vector_size x = 0; x != width(); ++x) {
            auto c = tiles_[y][x].getGraphic();
            mvaddch(y, x, c);
         }
    }
}
void Level::redrawTile(const Tile& tile) const {
    mvaddch(tile.y_, tile.x_, tile.getGraphic());
}
