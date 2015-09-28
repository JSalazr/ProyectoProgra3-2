#include "Personaje.h"

Personaje::Personaje(ALLEGRO_EVENT *ev)
{
    vida = 3;
    animacionActual = 0;
    velocity = 10;
    cuadro->width = 65;
    cuadro->height = 65;
//
//    cout<<ALLEGRO_KEY_Q<<endl;
//    controles.insert("RED", ALLEGRO_KEY_Q);
//    controles.insert("GREEN", ALLEGRO_KEY_W);
//    controles.insert("BLUE", ALLEGRO_KEY_E);

    tipoActual = RED;
    skins[REDI].push_back(al_load_bitmap("resources/blobs/red1i.png"));
    skins[REDI].push_back(al_load_bitmap("resources/blobs/red2i.png"));
    skins[REDI].push_back(al_load_bitmap("resources/blobs/red3i.png"));
    skins[REDI].push_back(al_load_bitmap("resources/blobs/red4i.png"));

    skins[RED].push_back(al_load_bitmap("resources/blobs/red1.png"));
    skins[RED].push_back(al_load_bitmap("resources/blobs/red2.png"));
    skins[RED].push_back(al_load_bitmap("resources/blobs/red3.png"));
    skins[RED].push_back(al_load_bitmap("resources/blobs/red4.png"));

    skins[REDD].push_back(al_load_bitmap("resources/blobs/red1d.png"));
    skins[REDD].push_back(al_load_bitmap("resources/blobs/red2d.png"));
    skins[REDD].push_back(al_load_bitmap("resources/blobs/red3d.png"));
    skins[REDD].push_back(al_load_bitmap("resources/blobs/red4d.png"));

    skins[GREENI].push_back(al_load_bitmap("resources/blobs/green1i.png"));
    skins[GREENI].push_back(al_load_bitmap("resources/blobs/green2i.png"));
    skins[GREENI].push_back(al_load_bitmap("resources/blobs/green3i.png"));
    skins[GREENI].push_back(al_load_bitmap("resources/blobs/green4i.png"));

    skins[GREEN].push_back(al_load_bitmap("resources/blobs/green1.png"));
    skins[GREEN].push_back(al_load_bitmap("resources/blobs/green2.png"));
    skins[GREEN].push_back(al_load_bitmap("resources/blobs/green3.png"));
    skins[GREEN].push_back(al_load_bitmap("resources/blobs/green4.png"));

    skins[GREEND].push_back(al_load_bitmap("resources/blobs/green1d.png"));
    skins[GREEND].push_back(al_load_bitmap("resources/blobs/green2d.png"));
    skins[GREEND].push_back(al_load_bitmap("resources/blobs/green3d.png"));
    skins[GREEND].push_back(al_load_bitmap("resources/blobs/green4d.png"));

    skins[BLUEI].push_back(al_load_bitmap("resources/blobs/blue1i.png"));
    skins[BLUEI].push_back(al_load_bitmap("resources/blobs/blue2i.png"));
    skins[BLUEI].push_back(al_load_bitmap("resources/blobs/blue3i.png"));
    skins[BLUEI].push_back(al_load_bitmap("resources/blobs/blue4i.png"));
    //SJDHS
    skins[BLUE].push_back(al_load_bitmap("resources/blobs/blue1.png"));
    skins[BLUE].push_back(al_load_bitmap("resources/blobs/blue2.png"));
    skins[BLUE].push_back(al_load_bitmap("resources/blobs/blue3.png"));
    skins[BLUE].push_back(al_load_bitmap("resources/blobs/blue4.png"));
    //ASSD
    skins[BLUED].push_back(al_load_bitmap("resources/blobs/blue1d.png"));
    skins[BLUED].push_back(al_load_bitmap("resources/blobs/blue2d.png"));
    skins[BLUED].push_back(al_load_bitmap("resources/blobs/blue3d.png"));
    skins[BLUED].push_back(al_load_bitmap("resources/blobs/blue4d.png"));

    cuadro->width = al_get_bitmap_width(skins[RED][0]);
    cuadro->height = al_get_bitmap_height(skins[RED][0]);

    this->ev = ev;
    keyPressed[0] = false;
    keyPressed[1] = false;
}

void Personaje :: keydown(int keycode, bool* variable)
{
    if(ev->type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if(ev->keyboard.keycode == keycode)
            *variable=true;
    }
    if(ev->type == ALLEGRO_EVENT_KEY_UP)
    {
        if(ev->keyboard.keycode == keycode)
            *variable=false;
    }
}
void Personaje :: act()
{
    keydown(ALLEGRO_KEY_LEFT, &keyPressed[0]);
    keydown(ALLEGRO_KEY_RIGHT, &keyPressed[1]);
    keydown(ALLEGRO_KEY_Q, &keyPressed[2]);
    keydown(ALLEGRO_KEY_W, &keyPressed[3]);
    keydown(ALLEGRO_KEY_E, &keyPressed[4]);
    if(keyPressed[0] && cuadro->x >= -1+velocity)
    {
        cuadro->x-=velocity;
        if(tipoActual == RED){
            tipoActual = REDI;
            animacionActual = 0;
        }else if(tipoActual == GREEN){
            tipoActual = GREENI;
            animacionActual = 0;
        }else if(tipoActual==BLUE){
            tipoActual = BLUEI;
            animacionActual = 0;
        }
    }
    else if(keyPressed[1] && cuadro->x + cuadro->width <= 768)
    {
        cuadro->x+=velocity;
        if(tipoActual == RED){
            tipoActual = REDD;
            animacionActual = 0;
        }
        else if(tipoActual == GREEN){
            tipoActual = GREEND;
            animacionActual = 0;
        }
        else if(tipoActual==BLUE){
            tipoActual = BLUED;
            animacionActual = 0;
        }
    }
    else
    {
        if(tipoActual == REDD || tipoActual == REDI){
            tipoActual = RED;
            animacionActual = 0;
        }
        if(tipoActual == GREEND || tipoActual == GREENI){
            tipoActual = GREEN;
            animacionActual = 0;
        }
        if(tipoActual==BLUED || tipoActual==BLUEI){
            tipoActual = BLUE;
            animacionActual = 0;
        }
    }
    if(keyPressed[2])
    {
        tipoActual = RED;
        animacionActual = 0;
    }
    if(keyPressed[3])
    {
        tipoActual = GREEN;
        animacionActual = 0;
    }
    if(keyPressed[4])
    {
        tipoActual = BLUE;
        animacionActual = 0;
    }

    if(frame%13==0)
    {
        if(animacionActual < 3)
            animacionActual++;
        else
            animacionActual=0;
    }
    frame++;
}
void Personaje::draw()
{
    //al_draw_scaled_bitmap(skins[tipoActual][1], cuadro->x, cuadro->y, cuadro->width, cuadro->height, cuadro->x, cuadro->y, cuadro->width, cuadro->height, 0);
    al_draw_bitmap(skins[tipoActual][animacionActual], cuadro->x, cuadro->y, 0);
    //al_draw_rotated_bitmap(skins[tipoActual][animacionActual], cuadro->x, cuadro->y, cuadro->width, cuadro->height, 100, 0);
    //cambiar de skin
}

Personaje::~Personaje()
{
    //dtor
}
