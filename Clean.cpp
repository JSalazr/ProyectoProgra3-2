#include "Clean.h"
#include "obstaculos.h"
#include "Box.h"

Clean::Clean()
{
    codigo = 0;
    clean = al_load_bitmap("resources/clean.png");

    cuadro->width = al_get_bitmap_width(clean);
    cuadro->height = al_get_bitmap_height(clean);
}

Clean::~Clean()
{
    //dtor
}
