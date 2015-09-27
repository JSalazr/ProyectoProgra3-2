#include "lives.h"
#include "obstaculos.h"
#include "Box.h"

Lives::Lives()
{
    codigo = 0;
    heart = al_load_bitmap("resources/heart.png");

    cuadro->width = al_get_bitmap_width(heart);
    cuadro->height = al_get_bitmap_height(heart);
}

Lives::~Lives()
{
    //dtor
}
