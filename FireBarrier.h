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
//        void act();
//        void draw();
//        double velo;
    protected:
    private:
};

#endif // FIREBARRIER_H
