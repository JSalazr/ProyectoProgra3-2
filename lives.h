#ifndef LIVES_H
#define LIVES_H
#include "obstaculos.h"

class Lives : public Obstaculos
{
    public:
        Lives();
        ALLEGRO_BITMAP* heart;
        virtual ~Lives();
    protected:
    private:
};

#endif // LIVES_H
