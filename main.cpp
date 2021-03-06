#include <iostream>

#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Highscores.h"
#include "coins.h"
#include "lives.h"
#include "obstaculos.h"
#include "Entidad.h"
#include "Personaje.h"
#include "FloatingObs.h"
#include "Enemy.h"
#include "WaterBarrier.h"
#include "FireBarrier.h"
#include "GroundBarrier.h"
#include <unistd.h>
#include <sstream>

using namespace std;

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
//ALLEGRO_MAP *mapa = al_open_map("/tmx", "lab.tmx");
//al_draw_map(mapa, 0, 0, 0); // (map, dx, dy, flags)

//EVENTOS Y TIMERS
ALLEGRO_EVENT ev;
ALLEGRO_TIMEOUT timeout;
ALLEGRO_TIMER *timer = NULL;

//Elementos Generales
ALLEGRO_BITMAP  *logo   = NULL;
ALLEGRO_BITMAP  *perder   = NULL;
ALLEGRO_BITMAP  *instru   = NULL;
ALLEGRO_BITMAP  *fondo   = NULL;
ALLEGRO_BITMAP  *pausa   = NULL;
ALLEGRO_BITMAP  *splash   = NULL;
ALLEGRO_BITMAP  *menu   = NULL;
ALLEGRO_BITMAP  *btnplay   = NULL;
ALLEGRO_BITMAP  *btnexit   = NULL;
ALLEGRO_BITMAP  *btnplay1   = NULL;
ALLEGRO_BITMAP  *btnexit1   = NULL;
ALLEGRO_BITMAP  *btnscore   = NULL;
ALLEGRO_BITMAP  *btnscore1   = NULL;
ALLEGRO_BITMAP  *btninst   = NULL;
ALLEGRO_BITMAP  *btninst1   = NULL;
ALLEGRO_BITMAP  *btnabout   = NULL;
ALLEGRO_BITMAP  *btnabout1  = NULL;
ALLEGRO_BITMAP  *splashabout   = NULL;
ALLEGRO_BITMAP  *instrucciones   = NULL;
ALLEGRO_BITMAP  *scores_s   = NULL;
ALLEGRO_SAMPLE* optionSound = NULL;
ALLEGRO_SAMPLE* levelUp = NULL;
ALLEGRO_SAMPLE* keyType = NULL;
ALLEGRO_SAMPLE* lose = NULL;
ALLEGRO_SAMPLE* yey = NULL;
ALLEGRO_SAMPLE_INSTANCE* optionSoundInstance = NULL;
ALLEGRO_SAMPLE_INSTANCE* levelUpInstance = NULL;
ALLEGRO_SAMPLE_INSTANCE* keyTypeInstance = NULL;
ALLEGRO_SAMPLE_INSTANCE* loseInstance = NULL;
ALLEGRO_SAMPLE_INSTANCE* yeyInstance = NULL;

ALLEGRO_KEYBOARD_STATE keystate;

//ALLEGRO_

ALLEGRO_BITMAP* nubes;

ALLEGRO_FONT *normalFont = NULL;
//Entidad *personaje;

    bool restart = 0;

int width = 768, height = 1000, FPS = 30, seconds=1, timer2=0, moveSpeed=5,moveSpeedB1=1, moveSpeedB2=3, menuopt=1, pauseopt=1;
string currentuser="hola";
int bg1=0, bg2=0;
bool izq=false, der=false, splash1=true, splash2= false, pausa_m=false, inst_m=false, scores_m=false, about_m=false, perder_m=false;

bool collision(Entidad* e, Entidad* a);

void keydown(int keycode, bool* variable)
{
    if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if(ev.keyboard.keycode == keycode)
            *variable=true;
    }
    if(ev.type == ALLEGRO_EVENT_KEY_UP)
    {
        if(ev.keyboard.keycode == keycode)
            *variable=false;
    }
}

bool press(int keycode)
{
    if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if(ev.keyboard.keycode==keycode)
        {
            return true;
        }
        return false;
    }
}

int initAllegro()
{
    if(!al_init())
    {
        cout<<"failed to initialize allegro!\n"<<endl;
        return -1;
    }

    if(!al_init_image_addon())
    {
        cout<<"Error: Failed to initialize al_init_image_addon!"<<endl;
        return -1;
    }

    display = al_create_display(width, height);
    if(!display)
    {
        cout<<"failed to create display!\n"<<endl;
        return -1;
    }

    event_queue = al_create_event_queue();
    if(!event_queue)
    {
        cout<<"failed to create event_queue!\n"<<endl;
        al_destroy_display(display);
        return -1;
    }

    timer = al_create_timer(1.0 / FPS);
    if(!timer)
    {
        cout<<"failed to create timer!"<<endl;
    }

    if(!al_install_keyboard())
    {
        cout<<"failed to initialize the keyboard!"<<endl;
    }

    if(!al_install_audio() || !al_init_acodec_addon() || !al_reserve_samples(2))
    {
        cout<<"failed to initialize Audio!"<<endl;
    }

    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon();// initialize the ttf (True Type Font) addon
    cout<<"Llego aki";
    normalFont = al_load_ttf_font("PIXEL-LI.TTF",50,0 );
//    cartoonFont = al_load_ttf_font("GameFiles/fonts/kenpixel_blocks.ttf",50,0 );

    if (!normalFont /*|| !cartoonFont*/)
    {
        cout<<"Failed to initialize the font"<<endl;
        return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));//registrar eventos del display
    al_register_event_source(event_queue, al_get_timer_event_source(timer));//registrar eventos del timer
    al_register_event_source(event_queue, al_get_keyboard_event_source());//registrar eventos del teclado

    al_start_timer(timer);

    al_init_timeout(&timeout, 0.06);
}

string ingresarNombre()
{
    string name = "";
    while(1)
    {
        al_clear_to_color(al_map_rgb(0,0,0));
        bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);
        if(get_event && ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if (press(ALLEGRO_KEY_ESCAPE) || press(ALLEGRO_KEY_ENTER))
                break;
            for(int x = 1; x <= 27; x++)//for para obtener los valores de todas las letras
                if (press(x))//comparamos que tecla está siendo presionada
                {
                    al_play_sample_instance(keyTypeInstance);
                    char e = x+64; //de ser así, sumarle al valor ASCII equivalente
                    name.push_back(e);//concatenarla al nombre
                }

            if (press(ALLEGRO_KEY_BACKSPACE) && name.size()>0)//comprar si vamos a borrar una letra
            {
                string temp = name;
                name = "";
                for(int x = 0; x<temp.size()-1; x++)
                    name+=temp[x];
            }
        }
//        al_draw_bitmap(fondo,0,0,0);
        al_draw_text(normalFont, al_map_rgb(102,204,0), width/2, (height/2)-35,ALLEGRO_ALIGN_CENTRE, "INGRESE SU NOMBRE:");
        al_draw_text(normalFont, al_map_rgb(255,255,255), width/2, height/2,ALLEGRO_ALIGN_CENTRE, name.c_str());//dibuja el nombre
        al_flip_display();//necesario para cambiar a la siguiente parte del buffer (que dibujará)
    }
    return name;
}

void menuin(){
    al_draw_bitmap(menu, 0, 0 ,100);
    if(press(ALLEGRO_KEY_DOWN))
    {
        //al_play_sample_instance(optionSoundInstance);
        menuopt++;
        if(menuopt>6)
        {
            //al_play_sample_instance(optionSoundInstance);
            menuopt=2;
        }
        //al_play_sample_instance(optionSoundInstance);
    }
    if(press(ALLEGRO_KEY_UP))
    {
        menuopt--;
        if(menuopt<1)
        {
            //al_play_sample_instance(optionSoundInstance);
            menuopt=5;
        }
        //al_play_sample_instance(optionSoundInstance);
    }

    if(menuopt==1){
        al_draw_bitmap(btnplay1, 190, 390, 100);
        al_draw_bitmap(btnscore, 140, 530, 100);
        al_draw_bitmap(btninst, 140, 660, 100);
        al_draw_bitmap(btnexit, 200, 760, 100);
        al_draw_bitmap(btnabout, 200, 900, 100);
        //al_play_sample_instance(optionSoundInstance);
        if(ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            currentuser = ingresarNombre();
            splash2=false;
        }
    }
    else if(menuopt==2){
        al_draw_bitmap(btnplay, 180, 375, 100);
        al_draw_bitmap(btnscore1, 140, 530, 100);
        al_draw_bitmap(btninst, 140, 660, 100);
        al_draw_bitmap(btnexit, 200, 760, 100);
          al_draw_bitmap(btnabout, 200, 900, 100);
        //al_play_sample_instance(optionSoundInstance);
         if(ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            //splash2=false;
            scores_m=true;
        }


     }
     else if(menuopt==3){
        al_draw_bitmap(btnplay, 180, 375, 100);
        al_draw_bitmap(btnscore, 140, 530, 100);
        al_draw_bitmap(btninst1, 140, 660, 100);
        al_draw_bitmap(btnexit, 200, 760, 100);
          al_draw_bitmap(btnabout, 200, 900, 100);
        //al_play_sample_instance(optionSoundInstance);
        if(ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            //splash2=false;
            inst_m=true;
        }

     }
     else if(menuopt==4){
        al_draw_bitmap(btnplay, 180, 375, 100);
        al_draw_bitmap(btnscore, 140, 530, 100);
        al_draw_bitmap(btninst, 140, 660, 100);
        al_draw_bitmap(btnexit1, 200, 760, 100);
          al_draw_bitmap(btnabout, 200, 900, 100);
        //al_play_sample_instance(optionSoundInstance);
        if(ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            exit(1);
        }
    }
    else if(menuopt==5){
        al_draw_bitmap(btnplay, 180, 375, 100);
        al_draw_bitmap(btnscore, 140, 530, 100);
        al_draw_bitmap(btninst, 140, 660, 100);
        al_draw_bitmap(btnexit, 200, 760, 100);
        al_draw_bitmap(btnabout1, 200, 900, 100);
        //al_play_sample_instance(optionSoundInstance);
         if(ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            about_m=true;
        }
    }


}

void pausein(){
        al_draw_bitmap(splash, 0, 0, 100);
        if(press(ALLEGRO_KEY_DOWN))
        {
            pauseopt++;
            al_play_sample_instance(optionSoundInstance);
            if(pauseopt>3)
                pauseopt=2;
        }
        if(press(ALLEGRO_KEY_UP))
        {
            pauseopt--;
            al_play_sample_instance(optionSoundInstance);
            if(pauseopt<1)
                pauseopt=1;
        }
        if(pauseopt==1)
        {
            al_draw_bitmap(btnplay1, 190, 200, 100);
            al_draw_bitmap(btnexit, 190, 650, 100);
            if(ev.keyboard.keycode==ALLEGRO_KEY_ENTER)
                pausa_m=false;
        }
        else if(pauseopt==2)
        {
            al_draw_bitmap(btnplay, 180, 185, 100);
            al_draw_bitmap(btnexit1, 190, 650, 100);
            if(ev.keyboard.keycode==ALLEGRO_KEY_ENTER)
            {
//                splash1 = true;
                pausa_m = false;
                restart=1;
            }
        }
}

vector<Entidad* > initEnemigos(int cant);
vector<Entidad* > patitos;
Entidad* personaje;// = new Personaje(&ev);

int main()
{
    initAllegro();

    personaje = new Personaje(&ev);
    patitos.insert(patitos.begin(), personaje);
    //al_reverse_samples(1);
//    A
    cout<<"llrego alo"<<endl;
    fondo = al_load_bitmap("resources/fondo-cielo.png");
    nubes = al_load_bitmap("resources/nubes.png");
    splash = al_load_bitmap("resources/splash.png");
    menu = al_load_bitmap("resources/menu.png");
    btnplay = al_load_bitmap("resources/play.png");
    btnexit = al_load_bitmap("resources/exit.png");
    btnplay1 = al_load_bitmap("resources/play1.png");
    btnexit1 = al_load_bitmap("resources/exit1.png");
    btnscore = al_load_bitmap("resources/score.png");
    btnscore1 = al_load_bitmap("resources/score1.png");
    btninst = al_load_bitmap("resources/instructions.png");
    btninst1 = al_load_bitmap("resources/insctructions1.png");
    btnabout = al_load_bitmap("resources/about.png");
    btnabout1 = al_load_bitmap("resources/about1.png");
    instrucciones = al_load_bitmap("resources/instrucciones.png");
    perder = al_load_bitmap("resources/perdiste.png");
    scores_s = al_load_bitmap("resources/scores_s.png");
    splashabout = al_load_bitmap("resources/splashabout.png");
    optionSound = al_load_sample("resources/option.wav");
    levelUp = al_load_sample("resources/levelup.wav");
    keyType = al_load_sample("resources/keytype.wav");
    lose = al_load_sample("resources/fire.wav");
    yey = al_load_sample("resources/yey.wav");
    optionSoundInstance = al_create_sample_instance(optionSound);
    levelUpInstance = al_create_sample_instance(levelUp);
    keyTypeInstance = al_create_sample_instance(keyType);
    loseInstance = al_create_sample_instance(lose);
    yeyInstance = al_create_sample_instance(yey);
    al_set_sample_instance_playmode(optionSoundInstance, ALLEGRO_PLAYMODE_ONCE);
    al_set_sample_instance_playmode(levelUpInstance, ALLEGRO_PLAYMODE_ONCE);
    al_set_sample_instance_playmode(keyTypeInstance, ALLEGRO_PLAYMODE_ONCE);
    al_set_sample_instance_playmode(loseInstance, ALLEGRO_PLAYMODE_ONCE);
    al_set_sample_instance_playmode(yeyInstance, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(optionSoundInstance, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(levelUpInstance, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(keyTypeInstance, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(loseInstance, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(yeyInstance, al_get_default_mixer());

    int nivel = 1;
    bool lvlup = 1;
//    bool restart = 0;
    ostringstream displayLvl;
    ostringstream displayScores;
//    string displayLvl;
//    patitos = initEnemigos(nivel*5);
//    patitos.insert(patitos.begin(), personaje);
//    int cant = nivel*5;
//    for(int i = 0; i < cant; i++)
//    {
//        int randy = 1;
//
//        switch (randy)
//        {
//        case 1:
//            patitos.insert(patitos.begin(), new Enemy());
//            (*(patitos.begin()))->cuadro->y= 1280 + (i*200+rand()%(200));
//            (*(patitos.begin()))->cuadro->x=(rand()%(768));
//
//                  case 2:
//
//                  case 3:
//            break;
//
//        }
//    }


    Highscores *high=new Highscores();
    int cont=0;
    while(true)
    {
        bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);

//            al_get_keyboard_state(&keystate);

        if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            timer2++;
            if(timer2==60)
            {
                //cout<<seconds++<<endl;
                timer2=0;
            }
            if(timer2%2==0)
            {

            }
        }
        if(get_event && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            break;
        }

        if(splash1 || splash2)
        {
            if(splash1)
            {
                al_draw_bitmap(splash, 0, 0, 100);
                if(ev.keyboard.keycode == ALLEGRO_KEY_SPACE)
                {
                    splash1=false;
                    splash2=true;

//		    al_play_sample_instance(optionSoundInstance);
                }
            }
            if(splash2)
            {
               menuin();

//	       al_play_sample_instance(optionSoundInstance);
            }
             if(inst_m){
                al_draw_bitmap(instrucciones, 0, 0, 100);
                if(ev.keyboard.keycode== ALLEGRO_KEY_ESCAPE )
                inst_m=false;
            }

             if(scores_m){
                al_draw_bitmap(scores_s, 0, 0, 100);
                int lug=high->highs.size();
                int pos=200*lug;
                if(lug>=12){
                    lug==12;
                    pos=70*lug;
                }
                for(multimap<int,string>::iterator i = high->highs.begin();
                    i!=high->highs.end();
                    i++)
                    {

                        if(high->highs.size()>=12){
                            if(cont>=high->highs.size()-12 && cont<high->highs.size())
                            {
                                displayScores.str("");
                                displayScores.clear();
                                displayScores << (*i).second <<"                  "<< (*i).first;
                                al_draw_text(normalFont, al_map_rgb(102,204,0), width/2, pos,ALLEGRO_ALIGN_CENTRE, displayScores.str().c_str());
                                cout<<(*i).first<<","<<(*i).second<<endl;
                            }
                            pos-=40;
                            cont++;
                            if(cont>high->highs.size())
                                cont=0;
                            if(lug==0)
                                lug=12;
                        }
                        else
                        {
                                                        //lug=high->highs.size();
                            if(cont<high->highs.size())
                            {
                                displayScores.str("");
                                displayScores.clear();
                                displayScores << (*i).second <<"                  "<< (*i).first;
                                al_draw_text(normalFont, al_map_rgb(102,204,0), width/2, pos,ALLEGRO_ALIGN_CENTRE, displayScores.str().c_str());
                                cout<<(*i).first<<","<<(*i).second<<endl;
                            }
                            cont++;
                            pos-=40;
                                if(cont>high->highs.size())
                                    cont=0;
                                if(lug==0)
                                lug=high->highs.size();
                        }
                    }
                if(ev.keyboard.keycode== ALLEGRO_KEY_ESCAPE )
                scores_m=false;
            }
            if(about_m){
                al_draw_bitmap(splashabout,0,0,100);
                if(ev.keyboard.keycode== ALLEGRO_KEY_ESCAPE )
                about_m=false;
            }
        }
        else if(perder_m){
        al_draw_bitmap(perder,0,0,100);
           if(ev.keyboard.keycode== ALLEGRO_KEY_ESCAPE ){
                perder_m=false;
                splash1=true;
            }
        }

        else
        {
            if(restart)
            {
                high->highs.insert(pair<int, string>(nivel-1, currentuser));
                patitos.clear();
                patitos.insert(patitos.begin(), personaje);
                menuopt=1;
                pauseopt=1;
                bg1=0;
                bg2=0;
                izq=false;
                der=false;
                splash1=false;
                perder_m=true;
                splash2= false;
                pausa_m=false;
                inst_m=false;
                scores_m=false;
                nivel = 1;
                lvlup = 1;
                restart = 0;
            }

            if(lvlup)
            {
    //            patitos.insert(patitos.begin(), personaje);
                int cant = nivel*3;
                for(int i = 0; i < cant; i++)
                {
                    int randy = rand()%4;
                    switch (randy)
                    {
                        case 0:
                            patitos.insert(patitos.begin(), new Enemy());
                            (*(patitos.begin()))->cuadro->y= 1280 + (i*300+rand()%(200));
                            (*(patitos.begin()))->cuadro->x=(rand()%(768));
                            break;

                        case 1:
                            patitos.insert(patitos.begin(), new WaterBarrier());
                            (*(patitos.begin()))->cuadro->y= 1280 + (i*400+rand()%(200));
                            break;

                        case 2:
                            patitos.insert(patitos.begin(), new FireBarrier());
                            (*(patitos.begin()))->cuadro->y= 1280 + (i*400+rand()%(200));
                            break;

                        case 3:
                            patitos.insert(patitos.begin(), new GroundBarrier());
                            (*(patitos.begin()))->cuadro->y= 1280 + (i*400+rand()%(200));
                            break;
                    }
                }
                lvlup = 0;
                displayLvl.str("");
                displayLvl.clear();
                displayLvl << "NIVEL: " << nivel;
                al_play_sample_instance(levelUpInstance);
                nivel++;
            }

//            cant = 0;

//        al_clear_to_color(al_map_rgb(0,0,255));

            if(ev.keyboard.keycode==ALLEGRO_KEY_ESCAPE){
                pausa_m=true;
                }

            if(pausa_m){
                pausein();
            }

            else{

            al_draw_bitmap(fondo, 0, bg1, 0);
            al_draw_bitmap(fondo, 0, bg1+2560, 0);
            al_draw_bitmap(nubes, 0, bg2, 0);
            al_draw_bitmap(nubes, 0, bg2+2560, 0);

            vector<vector<Entidad*>::iterator> borrar;

            for(vector<Entidad*>::iterator i = patitos.begin(); i != patitos.end(); i++)
            {
                (*i)->act();
                (*i)->draw();

                if((*i) != personaje && collision((*i), personaje))
                {
                    //al_reverse_samples(1);
                    //al_play_sample_instance(yeyInstance);
                    if((*i)->codigo == 1)
                    {
                        if(!(personaje->tipoActual == RED || personaje->tipoActual == REDD || personaje->tipoActual == REDI))
                        {
                            restart = 1;
                            patitos.erase(i);
                            al_play_sample_instance(loseInstance);
                            cout<<"perdiste"<<endl;
                        }
                    }
                    else if((*i)->codigo == 2)
                    {
                        if(!(personaje->tipoActual == GREEN || personaje->tipoActual == GREEND || personaje->tipoActual == GREENI))
                        {
                            restart = 1;
                            patitos.erase(i);
                            al_play_sample_instance(loseInstance);
                            cout<<"perdiste"<<endl;
                        }
                    }
                    else if((*i)->codigo == 3)
                    {
                        if(!(personaje->tipoActual == BLUE || personaje->tipoActual == BLUED || personaje->tipoActual == BLUEI))
                        {
                            restart = 1;
                            patitos.erase(i);
                            al_play_sample_instance(loseInstance);
                            cout<<"perdiste"<<endl;
                        }
                    }
                    else
                        {
                            restart = 1;
                            patitos.erase(i);
                            al_play_sample_instance(loseInstance);
                            cout<<"perdiste"<<endl;
                        }

                }
                 //cout<<(&(*i)->codigo)<<endl;

                if((*i)->cuadro->y>900)
                    al_draw_text(normalFont, al_map_rgb(102,204,0), width/2, (height/2)-35,ALLEGRO_ALIGN_CENTRE, displayLvl.str().c_str());

//            if((*patitos.end()-1)->cuadro->x > ((*i)->cuadro->x+(*i)->cuadro->width))
//                cout<<"persdiste";

                if((*i)->cuadro->y < -100)
                    borrar.push_back(i);
            }

            for(int x = 0; x < borrar.size(); x++){
                patitos.erase(borrar[x]);
            }
            if(patitos.size() == 1)
                lvlup = 1;

//        personaje->act();
//        personaje->draw();
            bg1-=moveSpeedB1;
            bg2-=moveSpeedB1;
            if(bg1<=-2560)
                bg1=0;
            if(bg2<=-2560)
                bg2=0;
            //if(collision)
        }

        }

        al_flip_display();

    }
    return 0;
}

bool collision(Entidad* e, Entidad* a)
{
    if(a->cuadro->x+a->cuadro->width < e->cuadro->x)
        return false;
    if(a->cuadro->x > e->cuadro->x+e->cuadro->width)
        return false;
    if(a->cuadro->y+a->cuadro->height < e->cuadro->y)
        return false;
    if(a->cuadro->y > e->cuadro->y+e->cuadro->height)
        return false;

    return true;
}

//vector<Entidad* > initEnemigos(int cant)
//{
//    vector<Entidad* > patitos;
//    patitos.insert(patitos.begin(), new Personaje(&ev));
//    for(int i = 0; i < cant; i++)
//    {
//        int randy = 1;
//
//        switch (randy)
//        {
//        case 1:
//            patitos.insert(patitos.begin(), new Enemy());
//            (*(patitos.begin()))->cuadro->y= 1280 + (i*rand()%(2000));
//
////                  case 2:
////
////                  case 3:
//            break;
//
//        }
//    }
//    return patitos;
//}
