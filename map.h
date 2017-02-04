#ifdef MAP_H
#define MAP_H

enum TILE {
    EMPTY = -1,
    MOUNTAIN = -2,
    FOG = -3,
    FOG_OBSTACLE = -4
};

class map {
    void update();
}

#endif
