#include "FireBarrier.h"

FireBarrier::FireBarrier()
{
    firebarrier = al_load_bitmap("resources/firebarrier.png");
    velo = 3;
    codigo = 1;

    cuadro->width = al_get_bitmap_width(firebarrier);
    cuadro->height = al_get_bitmap_height(firebarrier);
}

void FireBarrier :: act()
{
    cuadro->y-=3;
}

void FireBarrier :: draw()
{
    al_draw_bitmap(firebarrier, cuadro->x, cuadro->y, 0);
}

FireBarrier::~FireBarrier()
{
    al_destroy_bitmap(firebarrier);
    delete cuadro;
}
