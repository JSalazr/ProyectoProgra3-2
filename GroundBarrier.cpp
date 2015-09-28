#include "GroundBarrier.h"

GroundBarrier::GroundBarrier()
{
    groundbarrier = al_load_bitmap("resources/groundbarrier.png");
    velo = 3;
    codigo = 2;

    cuadro->width = al_get_bitmap_width(groundbarrier);
    cuadro->height = al_get_bitmap_height(groundbarrier);
}

void GroundBarrier :: act()
{
    cuadro->y-=3;
}

void GroundBarrier :: draw()
{
    al_draw_bitmap(groundbarrier, cuadro->x, cuadro->y, 0);
}

GroundBarrier::~GroundBarrier()
{
    al_destroy_bitmap(groundbarrier);
    delete cuadro;
}
