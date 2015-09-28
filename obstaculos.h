#ifndef OBSTACULOS_H
#define OBSTACULOS_H
#include <iostream>
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "Entidad.h"

using namespace std;

class Obstaculos : public Entidad
{
    public:
//        int codigo;
        double velo;
        Obstaculos();
        virtual ~Obstaculos();
    protected:
    private:
};

#endif // OBSTACULOS_H
