#include "Highscores.h"

Highscores::Highscores()
{
    highs.insert(pair<int, string>(3, "hola"));
    highs.insert(pair<int, string>(4, "la"));
    highs.insert(pair<int, string>(3, "h"));
    highs.insert(pair<int, string>(1, "ho"));
}

Highscores::~Highscores()
{
    //dtor
}
