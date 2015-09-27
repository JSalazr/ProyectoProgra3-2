#ifndef COINS_H
#define COINS_H
#include "obstaculos.h"

class Coins : public Obstaculos
{
    public:
        ALLEGRO_BITMAP* coin;
        virtual ~Coins();
    protected:
    private:
};

#endif // COINS_H
