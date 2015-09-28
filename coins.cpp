#include "coins.h"
#include "obstaculos.h"
#include "Box.h"

Coins::Coins()
{
    coin = al_load_bitmap("resources/coin.png");

    cuadro->width = al_get_bitmap_width(coin);
    cuadro->height = al_get_bitmap_height(coin);
}

Coins::~Coins()
{
    //dtor
}
