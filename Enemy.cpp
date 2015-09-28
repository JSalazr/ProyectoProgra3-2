#include "Enemy.h"
#include "obstaculos.h"
#include <vector>
#include "Box.h"

using namespace std;

Enemy::Enemy()
{
    enemy = al_load_bitmap("resources/enemy.png");
    velo = 3;

    cuadro->width = al_get_bitmap_width(enemy);
    cuadro->height = al_get_bitmap_height(enemy);

  //  cuadro->x = rand()%(720 - cuadro->width);
//    frame=0;
//    animacionactual = 0;
//    enemy[0]=al_load_bitmap("resources/blobs/red1.png");
//    cout<<enemy[0]<<endl;
//    enemy[1]=al_load_bitmap("resources/enemy2.png");
//    enemy[2]=al_load_bitmap("resources/enemy3.png");

}

void Enemy :: act()
{
    //cout<<cuadro->x<<" , "<<cuadro->y<<endl;
    cuadro->y-=3;
    cuadro->x+=velo;
    if(cuadro->x >= 768-cuadro->width)
        velo = -3;
    else if (cuadro->x <= 0)
        velo = 3;

}

void Enemy :: draw()
{
    al_draw_bitmap(enemy, cuadro->x, cuadro->y, 0);
}

Enemy::~Enemy()
{
    al_destroy_bitmap(enemy);
    delete cuadro;
}

//void Enemy::showEnemy()
//{
//       //al_draw_bitmap(enemy[0], 0 , 0, 0);
////        al_draw_bitmap(skins[tipoActual][animacionActual], cuadro->x, cuadro->y, 0);
//            cout<<enemy[0];
//            if(frame%13==0)
//        {
//            if(animacionactual < 2)
//                animacionactual++;
//            else
//                animacionactual=0;
//        }
//        frame++;
//}
