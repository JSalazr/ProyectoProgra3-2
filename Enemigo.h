#ifndef ENEMIGO_H
#define ENEMIGO_H


class Enemigo : public Entidad
{
    public:
        ALLEGRO_BITMAP* firebarrier, coin, heart, obs, clean, enemy;
        Enemigo();
        virtual ~Enemigo();
    protected:
    private:
};

#endif // ENEMIGO_H
