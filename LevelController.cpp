#include "Player.hh"
#include "LevelController.hh"
#include <ncurses.h>

//Tile::redrawTileFunction Tile::redrawTile = &LevelController::redrawTile;

LevelController::LevelController() : levelDisplay_(20, getmaxx(stdscr), getmaxy(stdscr)-20, 0) {}

void LevelController::generateLevel(Player& player, unsigned int sizeY, unsigned int sizeX,
                                    unsigned int roomAmount, unsigned int rowMax, unsigned int colMax) {

    levels_.push_back(Level(sizeY, sizeX));
    currentLevel_ = &levels_.back();
    currentLevel_->generateLevel(roomAmount, rowMax, colMax);
    spawnPlayer(player);
}

void LevelController::drawLevel() {
    currentLevel_->printLevelArray();
}

void LevelController::spawnPlayer(Actor& player) {
    //Tile* tile = currentLevel_->randomTile();
    currentLevel_->spawnActor(player);
}

