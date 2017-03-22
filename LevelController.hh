#ifndef GUARD_LevelController_hh
#define GUARD_LevelController_hh

#include "Level.hh"
#include <vector>
class Player;

class LevelController {
public:
    LevelController();
    LevelController(const LevelController&) = delete;
    LevelController& operator=(const LevelController&) = delete;

    void generateLevel(Player&, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    void drawLevel();
    static void redrawTile(unsigned int, unsigned int, char);

private:
    Level* currentLevel_;
    std::vector<Level> levels_;

    void spawnPlayer(Player&);
};

#endif
