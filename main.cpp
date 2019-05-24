//
//  myExecutable.cpp
//  algo2_hw2
//
//  Created by Hasan Furkan Vural on 15.10.2018.
//  150140029
//  Copyright © 2018 H. Furkan Vural. All rights reserved.
/*********************************************************************
 While compiling, please use this command.
            "g++ main.cpp -o project3
           ./project3 <inputtxtname> <outputtxtname(OPTIONAL)> -std=c++11"
*********************************************************************/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

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

void bpm(Team *teams, int N)
{
    for (int u = 0; u < N; u++)
    {
        bool canwin = (teams[u].outscore()+ teams[u].outmatchleft() >= teams[u].outavr() ) ? true : false;
        if (canwin)
            teams[u].setcanWin(true);
        else
            teams[u].setcanWin(false);
    }
}

int main(int argc, const char *argv[]) {
    
    if(argc<2)
    {
        argv[1] = "input1.txt";
    }
    ifstream inputFile(argv[1]);
    int size = 0, i=0;
    Team *teams = nullptr;

    if (inputFile.is_open())
    {
        string sizestr;
        getline(inputFile, sizestr, '\n');
        size = stoi(sizestr);
        teams = new Team[size];
        
        while (i!=size)
        {
            string score;
            if(i<size-1)getline(inputFile, score,' ');
            else getline(inputFile, score,'\n');
            teams[i].setscore(score);
            teams[i].setname("team"+to_string(i+1));
            i++;
        }
        i=0;
        while (i!=size)
        {
            int matchleft=0;
            for(int k=0; k<size; k++)
            {
                string matchnum;
                if(k!=size-1) getline(inputFile, matchnum,' ');
                else getline(inputFile, matchnum,'\n');
                
                matchleft+=stoi(matchnum);
            }
            
            teams[i].setmatchleft(matchleft);
            i++;
        }
        
        inputFile.close();
    }
    else
    {
        cout<<"cannot open inputfile"<<endl<<endl;
    }
    
    float total=0;
    for (int t=0; t<size; t++)
        total+=teams[t].outscore();
    
    for (int t=0; t<size; t++)
        teams[t].setavr(float(total-teams[t].outscore()+teams[t].outmatchleft())/float(size-1));

    bpm(teams, size);
    if(argc<3)
    {
        argv[2] = "output.txt";
        for(int x=0; x<size; x++)
            cout<<teams[x].outcanWin()<<" ";
    }
    ofstream outputFile(argv[2]);
    if (outputFile.is_open())
    {
        for(int x=0; x<size; x++)
            outputFile<<teams[x].outcanWin()<<" ";
        
        outputFile.close();
    }
    else cout << "Unable to open outputfile"<<endl<<endl;;
    
    return 0;
}

