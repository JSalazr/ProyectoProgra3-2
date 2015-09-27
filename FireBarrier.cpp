#include "FireBarrier.h"
#include "obstaculos.h"
#include "Box.h"

//FireBarrier::FireBarrier()
//{
//    firebarrier = al_load_bitmap("resources/firebarrier.png");
//    velo = 3;
//
//    cuadro->width = al_get_bitmap_width(firebarrier);
//    cuadro->height = al_get_bitmap_height(firebarrier);
////al_draw_bitmap(firebarrier,0,0,0);
//
//}

void FireBarrier::draw()
{
    al_draw_bitmap(firebarrier, cuadro->x, cuadro->y, 0);
}

//FireBarrier::~FireBarrier()
//{
//    al_destroy_bitmap(firebarrier);
//    delete cuadro;
//}
