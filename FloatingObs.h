#ifndef FLOATINGOBS_H
#define FLOATINGOBS_H
#include "obstaculos.h"

class FloatingObs : public Obstaculos
{
    public:
        FloatingObs();
        ALLEGRO_BITMAP *obstacle;
        virtual ~FloatingObs();
    protected:
    private:
};

#endif // FLOATINGOBS_H
