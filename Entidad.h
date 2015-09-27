#ifndef ENTIDAD_H
#define ENTIDAD_H
#include "Box.h"
#include <iostream>
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <vector>
//#include <Highscores.h>

using namespace std;


class Entidad
{
    public:
        ALLEGRO_EVENT *ev;
        ALLEGRO_TIMEOUT timeout;
        ALLEGRO_EVENT_QUEUE *event_queue = NULL;
        ALLEGRO_DISPLAY *display;
        bool colisionado;
        Box *cuadro;// = new Box(0,0,0,0);
        float velocity;// = 1;
        virtual void act() = 0;
        virtual void draw() = 0;
        int codigo;
        int tipoActual;
        Entidad();
        virtual ~Entidad();
    protected:
    private:
};

#endif // ENTIDAD_H
