#ifndef WATERBARRIER_H
#define WATERBARRIER_H
#include "obstaculos.h"


class WaterBarrier : public Obstaculos
{
    public:
        ALLEGRO_BITMAP* waterbarrier;
        void act();
        void draw();
        WaterBarrier();
        virtual ~WaterBarrier();
    protected:
    private:
};

#endif // WATERBARRIER_H
