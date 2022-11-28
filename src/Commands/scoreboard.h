#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "Map.h"
#include "Set.h"

class Scoreboard
{
    public:
    Scoreboard();
    ~Scoreboard();
    void addScore(int score);
    int getScore();
    void addWord(string word);
    bool isWord(string word);
    void printWords();
}

#endif