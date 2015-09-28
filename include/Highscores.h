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
        virtual ~Highscores();
        void crearHighscores()
        {
            for (multimap<int,string>::iterator x= highs.end(); x != highs.begin(); x--)
            {

            }
        }
        void agregarScore(string currentuser, int seconds)
        {
            highs.insert(pair<int, string>(seconds, currentuser));
        }
    protected:
    private:
};

#endif // HIGHSCORES_H
