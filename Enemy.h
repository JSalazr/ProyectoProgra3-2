#ifndef ENEMY_H
#define ENEMY_H
#include "obstaculos.h"


class Enemy : public Obstaculos
{
    public:
        ALLEGRO_BITMAP* enemy;
//        int animacionactual;
//        int frame;
//        ALLEGRO_BITMAP* enemy[3];
//        void showEnemy();
        void act();
        void draw();
        Enemy();
        virtual ~Enemy();
    protected:
    private:
};

#endif // ENEMY_H
