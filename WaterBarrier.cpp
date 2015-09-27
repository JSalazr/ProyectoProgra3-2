#include "WaterBarrier.h"

WaterBarrier::WaterBarrier()
{
    waterbarrier = al_load_bitmap("resources/waterbarrier.png");
    velo = 3;
    codigo = 3;

    cuadro->width = al_get_bitmap_width(waterbarrier);
    cuadro->height = al_get_bitmap_height(waterbarrier);
}

void WaterBarrier :: act()
{
    cuadro->y-=3;
}

void WaterBarrier :: draw()
{
    al_draw_bitmap(waterbarrier, cuadro->x, cuadro->y, 0);
}

WaterBarrier::~WaterBarrier()
{
    al_destroy_bitmap(waterbarrier);
    delete cuadro;
}
