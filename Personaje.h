#ifndef PERSONAJE_H
#define PERSONAJE_H
#include "Box.h"
#include "Entidad.h"
#include <iostream>
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <vector>
#include <map>

//#include <Highscores.h>

using namespace std;

enum TIPO {REDI, RED, REDD, GREENI, GREEN, GREEND, BLUEI, BLUE, BLUED};


class Personaje : public Entidad
{
    public:
        int vida, frame, animacionActual;
        vector<ALLEGRO_BITMAP*> skins[9];
        Personaje(ALLEGRO_EVENT *ev);
//        map<string, char> controles;
        void keydown(int keycode, bool* variable);
        void act();
        void draw();
        bool keyPressed[5];
        virtual ~Personaje();
    protected:
    private:
};

#endif // PERSONAJE_H
