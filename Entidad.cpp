#include "Entidad.h"


Entidad::Entidad()
{
    colisionado = 0;
    cuadro = new Box(0,0,0,0);
    velocity = 1;
}

Entidad::~Entidad()
{
    //dtor
}
