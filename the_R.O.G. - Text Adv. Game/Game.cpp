#include <iostream>
#include<vector>
#include<array>

using namespace std;

class Game{
    public:
     int play;
     Game();
     inline bool isPlaying(){ return play; }
     inline bool end(){ return play; }

};

class Player{
    public:
    int health;
    int currentRoom;
    Player();
    vector<string> accP;
    void print_acc();
    bool hasAcc(string name);
    bool hasKey();
};

class Rooms{
    public:
    int id;
    int n,w,e,s;
    int ene;
    string desc;
    vector<string> acc;
    inline bool hasEnemies(){return ene>0 ? true : false;}
    void addAcc(string name);
    bool hasAcc(string name);

};
