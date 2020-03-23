#ifndef Team_h
#define Team_h

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;


class Team{
    string name;
    int score;
    int matchleft;
    bool canWin;
    float avr;
public:
    Team(){};
    void setname(string x){name = x;}
    void setscore(string x){score = stoi(x);}
    void setmatchleft(int x){matchleft = x;}
    void setcanWin(bool x) {canWin = x;}
    void setavr(float x){avr = x;}
    string outname(){return name;}
    int outscore(){return score;}
    float outavr(){return avr;}
    int outmatchleft(){return matchleft;}
    bool outcanWin(){return canWin;}

};


#endif