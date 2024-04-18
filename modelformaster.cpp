#include "modelformaster.h"

ModelForMaster::ModelForMaster() {
    currentLevel = 1;
    player = new Block("Player");
    wall = new Block("Wall");
    for(int i = 0; i < 5;i++)
        levels[i] = new Map(i);
}
