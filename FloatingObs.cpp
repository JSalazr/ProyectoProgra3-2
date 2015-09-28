#include "FloatingObs.h"
#include "obstaculos.h"
#include "Box.h"

FloatingObs::FloatingObs()
{
    obstacle = al_load_bitmap("resources/obstacle.png");

    cuadro->width = al_get_bitmap_width(obstacle);
    cuadro->height = al_get_bitmap_height(obstacle);
}

FloatingObs::~FloatingObs()
{
    //dtor
}
