#include "Enemigo.h"

Enemigo::Enemigo()
{
    firebarrier = al_load_bitmap("resources/firebarrier.png");
    coin = al_load_bitmap("resources/coin.png");
    heart = al_load_bitmap("resources/heart.png");
    obs = al_load_bitmap("resources/obstacle.png");
    clean = al_load_bitmap("resources/clean.png");
    enemy = al_load_bitmap("resources/enemy.png");

    cuadro->width = al_get_bitmap_width(fierbarrier);
    cuadro->height = al_get_bitmap_height(firebarrier);

    cuadro->width = al_get_bitmap_width(coin);
    cuadro->height = al_get_bitmap_height(coin);

    cuadro->width = al_get_bitmap_width(heart);
    cuadro->height = al_get_bitmap_height(heart);

    cuadro->width = al_get_bitmap_width(obs);
    cuadro->height = al_get_bitmap_height(obs);

    cuadro->width = al_get_bitmap_width(clean);
    cuadro->height = al_get_bitmap_height(clean);

    cuadro->width = al_get_bitmap_width(enemy);
    cuadro->height = al_get_bitmap_height(enemy);
}

Enemigo::~Enemigo()
{
    //dtor
}
