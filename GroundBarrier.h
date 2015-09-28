#ifndef GROUNDBARRIER_H
#define GROUNDBARRIER_H
#include "obstaculos.h"


class GroundBarrier : public Obstaculos
{
    public:
        ALLEGRO_BITMAP* groundbarrier;
        void act();
        void draw();
        GroundBarrier();
        virtual ~GroundBarrier();
    protected:
    private:
};

#endif // GROUNDBARRIER_H
