#ifndef CLEAN_H
#define CLEAN_H
#include "obstaculos.h"
#include "Entidad.h"

class Clean : public Obstaculos
{
    public:
        ALLEGRO_BITMAP* clean;
        Clean();
        virtual ~Clean();
    protected:
    private:
};

#endif // CLEAN_H
