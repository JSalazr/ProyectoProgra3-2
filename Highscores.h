#ifndef HIGHSCORES_H
#define HIGHSCORES_H
#include <map>
#include <utility>
#include <iostream>

using namespace std;

class Highscores
{
    public:
        multimap<int, string> highs;
        Highscores();
        void crearScores();
        virtual ~Highscores();
    protected:
    private:
};

#endif // HIGHSCORES_H
