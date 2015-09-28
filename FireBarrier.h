#ifndef FIREBARRIER_H
#define FIREBARRIER_H
#include "obstaculos.h"


class FireBarrier : public Obstaculos
{
    public:
        ALLEGRO_BITMAP* firebarrier;
        void act();
        void draw();
        FireBarrier();
        virtual ~FireBarrier();
    protected:
    private:
};

#endif // FIREBARRIER_H
