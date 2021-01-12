#include "Game.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main(){
    cout<< "Welcome To Adventorous Game Of the Decade - the_R.O.G. "<<endl<<endl;
    cout<< " K I L L - that's the only way to  L I V E !!!! "<<endl;
    cout<<"Let the ADVENTURE begin !"<<endl<<endl;

    string cmd;
    Game g;
    Player p;
    array<Rooms,6> r;
    for(int i=0;i<6;i++){
            r[i].id=i+1;
    }
    //ROOM 1 
     r[0].desc="You are in 'THE GIANT HALL'.As name suggests it's very BIIIIIG hall. This is the central point and a safe zone with no enemies.Perfect Place to take rest and build up the energy taking medkits -  to Continue your Adventure !!.There is a WEAPON ROOM to your north , RUNWAY to your east and LIBRARY to your west ..." ;
     r[0].ene=0;
     r[0].n=2;
     r[0].w=4;
     r[0].e=5;
     r[0].s=0;
     r[0].addAcc("medkit");
     //ROOM 2 
     r[1].desc="You came to 'THE WEAPON ROOM', a place to gather ammunation, which are MUST to survive in thiis adventure.Take a sword or a gun and chase your enemies. There is GIANT HALL to your south and a SECRET ROOM to your west...";
     r[1].ene=0;
     r[1].n=0;
     r[1].w=3;
     r[1].e=0;
     r[1].s=1;
     r[1].addAcc("gun");
     r[1].addAcc("sword");
     //ROOM 3 
     r[2].desc="At Present you're in a SECRET ROOM.This room is almost a secret to everyone until zombies found it and made it their Capital.Be aware of the zombies staying here.kill them if you have a gun or a sword. You have LIBRARY to your south and WEAPON ROOM to your east...";
     r[2].ene=2;
     r[2].n=0;
     r[2].w=0;
     r[2].e=2;
     r[2].s=4;
     //ROOM 4
     r[3].desc="Sssshhhhhh!! You are in one of the oldest LIBRARIES in the world, where the Great Scientists like Issac Newton and Thomas Edison used to spend hours of time.Take a look at all the books.You may also find a 'key to treasure room' here.To your left, There is SECRET ROOM and GAINT HALL to your north and east resp....";
     r[3].ene=0;
     r[3].n=3;
     r[3].w=0;
     r[3].e=1;
     r[3].s=0;
     r[3].addAcc("key to treasure room");
     //ROOM 5
     r[4].desc="Now You are on the runway to the TREASURE ROOM..Be careful coz there's a rumour that there is a Zombie living on this runway.Either Kill it or else RUUUNNNNNNN. There are also cooldrinks here :) So have them get energy and KILL the BLOODY ZOMBIE..There is TREASURE ROOM to your south and GIANT HALL to your east";
     r[4].ene=1;
     r[4].n=0;
     r[4].w=0;
     r[4].e=1;
     r[4].s=6;
     r[4].addAcc("cooldrinks");
     //ROOM 6
     r[5].desc="You are Staring at THE TREASURE NOWW..coz you are in THE TREASURE ROOM. But Dont forget about the MONSTER. Kill it to get the TREASURE.You can easily kill the monster using a gun and sword. Use your strength - Show your Bravery - Kill The Monster .. GO AHEAD !!!!";
     r[5].ene=1;
     r[5].n=5;
     r[5].w=0;
     r[5].e=0;
     r[5].s=0;
     r[5].addAcc("treasure");
     cout<<r[p.currentRoom -1].desc<<endl;
     
    while(g.isPlaying()){
        getline (cin, cmd);
        int i=p.currentRoom;
        if(cmd=="go west"){
                if(i!=6 && r[i-1].hasEnemies()){
                   int loss;
                    srand (time(NULL));
                    loss = rand() % 100 + 1;
                    p.health-=loss;
                    if(p.health <= 0 ) {cout<<"aaaarg Zombie killed you !! GAME OVER "; break;}
                }
                else if(i==6 && r[i-1].hasEnemies()){
                    {cout<<"aaaarg Monster killed you !! GAME OVER"; break;}
                }

                if(r[i-1].w==6 && !p.hasKey()){
                     cout<<"This room is locked.You need a key to treasure room to unlock it :(("<<endl;
                }
            else if(r[i-1].w!=0){
               p.currentRoom= r[i-1].w;
               cout<<r[p.currentRoom -1].desc<<endl;}
            else cout<<"There's no way try another direction"<<endl;
        }

        else if(cmd=="go east"){
           if(i!=6 && r[i-1].hasEnemies()){
                   int loss;
                    srand (time(NULL));
                    loss = rand() % 100 + 1;
                    p.health-=loss;
                    if(p.health <= 0 ) {cout<<"aaaarg Zombie killed you !! GAME OVER "; break;}
                }
                else if(i==6 && r[i-1].hasEnemies()){
                    {cout<<"aaaarg Monster killed you !! GAME OVER"; break;}
                }

          if(r[i-1].e==6 && !p.hasKey()){
             cout<<"This room is locked.You need a key to treasure room to unlock it :(("<<endl;
          }
          else if(r[i-1].e!=0){
            p.currentRoom= r[i-1].e;
            cout<<r[p.currentRoom -1].desc<<endl;}
           else cout<<"There's no way try another direction"<<endl;

        }

        else if(cmd=="go north"){
           if(i!=6 && r[i-1].hasEnemies()){
                   int loss;
                    srand (time(NULL));
                    loss = rand() % 100 + 1;
                    p.health-=loss;
                    if(p.health <= 0 ) {cout<<"aaaarg Zombie killed you !! GAME OVER "; break;}
                }
                else if(i==6 && r[i-1].hasEnemies()){
                    {cout<<"aaaarg Monster killed you !! GAME OVER"; break;}
                }
          if(r[i-1].n==6 && !p.hasKey()){
             cout<<"This room is locked.You need a 'key to treasure room' to unlock it :(("<<endl;
          }
          else if(r[i-1].n!=0){
            p.currentRoom= r[i-1].n;
            cout<<r[p.currentRoom -1].desc<<endl;}
          else cout<<"There's no way try another direction"<<endl;

        }
        else if(cmd=="go south"){
           if(i!=6 && r[i-1].hasEnemies()){
                   int loss;
                    srand (time(NULL));
                    loss = rand() % 100 + 1;
                    p.health-=loss;
                    if(p.health <= 0 ) {cout<<"aaaarg Zombie killed you !! GAME OVER "; break;}
                }
                else if(i==6 && r[i-1].hasEnemies()){
                    {cout<<"aaaarg Monster killed you !! GAME OVER"; break;}
                }
         if(r[i-1].s==6 && !p.hasKey()){
             cout<<"This room is locked.You need a key to treasure room to unlock it :(("<<endl;
          }
         else if(r[i-1].s!=0){
            p.currentRoom= r[i-1].s;
            cout<<r[p.currentRoom -1].desc<<endl;}
         else cout<<"There's no way try another direction"<<endl;
        }

         else if(cmd=="take medkit"){
            if(r[i-1].hasAcc("medkit")){
                p.accP.push_back("medkit");
            if(p.health==100) cout<<"Health is full !!"<<endl;
            else if(p.health>90){
               cout<<"taken"<<endl;
               p.health=100;
            int index;
            for(auto j=r[i-1].acc.begin();j!=r[i-1].acc.end();j++){
                if(*j == "medkit"){
                    r[i-1].acc.erase(j);
                    break;
                }
            }
           }
           else{
              cout<<"taken"<<endl;
               p.health+=10;
            int index;
            for(auto j=r[i-1].acc.begin();j!=r[i-1].acc.end();j++){
                if(*j == "medkit"){
                    r[i-1].acc.erase(j);
                    break;
                }
            }
           }
          }
           else {
             int ch=1;
             if(ch)
              cout<<"There is no medkit here !"<<endl;
        }
       }

        else if(cmd=="take gun"){
            if(r[i-1].hasAcc("gun")){
            p.accP.push_back("gun");
             cout<<"taken"<<endl;
            int index;
            for(auto j=r[i-1].acc.begin();j!=r[i-1].acc.end();j++){
                if(*j == "gun"){
                    r[i-1].acc.erase(j);
                    break;
                }
            }
          }
           else {
             int ch=1;
             for(auto j=p.accP.begin();j!=p.accP.end();j++){
                 if(*j == "gun"){
                    cout<<"You already have a gun."<<endl;
                    ch=0;
                    break;
                }
             }
             if(ch)
              cout<<"There is no gun here !"<<endl;
        }
       }

        else if(cmd=="take sword"){
            if(r[i-1].hasAcc("sword")){
            p.accP.push_back("sword");
             cout<<"taken"<<endl;
            int index;
            for(auto j=r[i-1].acc.begin();j!=r[i-1].acc.end();j++){
                if(*j == "sword"){
                    r[i-1].acc.erase(j);
                    break;
                }
            }
          }
           else {
             int ch=1;
             for(auto j=p.accP.begin();j!=p.accP.end();j++){
                 if(*j == "sword"){
                    cout<<"You already have a sword."<<endl;
                    ch=0;
                    break;
                }
             }
             if(ch)
              cout<<"There is no sword here !"<<endl;
        }
       }

       else if(cmd=="take treasure"){
            if(r[i-1].hasAcc("treasure")){
              if(r[i-1].hasEnemies()) cout<<"KILL the MONSTER to take the treasure"<<endl;
              else{
               p.accP.push_back("treasure");
               cout<<"YOU DISCOVERED THE TREASURE.. YOU WIN !!"<<endl;
               break;}
          }
           else {
             int ch=1;
             if(ch)
              cout<<"There is no treasure here !!"<<endl;
        }
       }

       else if(cmd=="take cooldrinks"){
            if(r[i-1].hasAcc("cooldrinks")){
            p.accP.push_back("cooldrinks");
             if(p.health==100) cout<<"Health is full !!"<<endl;
            else if(p.health>95){
             cout<<"taken"<<endl;
             p.health=100;
            int index;
            for(auto j=r[i-1].acc.begin();j!=r[i-1].acc.end();j++){
                if(*j == "cooldrinks"){
                    r[i-1].acc.erase(j);
                    break;
                }
            }
            }
            else{
             cout<<"taken"<<endl;
             p.health+=5;
            int index;
            for(auto j=r[i-1].acc.begin();j!=r[i-1].acc.end();j++){
                if(*j == "cooldrinks"){
                    r[i-1].acc.erase(j);
                    break;
                }
            }
            }
          }
           else {
             int ch=1;
             for(auto j=p.accP.begin();j!=p.accP.end();j++){
                 if(*j == "cooldrinks"){
                    cout<<"You already have cooldrinks."<<endl;
                    ch=0;
                    break;
                }
             }
             if(ch)
              cout<<"There are no cooldrinks here !"<<endl;
        }
       }

       else if(cmd=="take key to treasure room"){
            if(r[i-1].hasAcc("key to treasure room")){
            p.accP.push_back("key to treasure room");
             cout<<"taken"<<endl;
            int index;
            for(auto j=r[i-1].acc.begin();j!=r[i-1].acc.end();j++){
                if(*j == "key to treasure room"){
                    r[i-1].acc.erase(j);
                    break;
                }
            }
          }
           else {
             int ch=1;
             for(auto j=p.accP.begin();j!=p.accP.end();j++){
                 if(*j == "key to treasure room"){
                    cout<<"You already have a key to treasure room."<<endl;
                    ch=0;
                    break;
                }
             }
             if(ch)
              cout<<"There is no key to treasure room here !"<<endl;
        }
       }

       else if(cmd == "list items"){
          p.print_acc();
       }

       else if(cmd == "kill zombie"){
            if(r[i-1].hasEnemies() && i!=6){
                 if(p.hasAcc("gun") || p.hasAcc("sword")){
                   cout<<"You killed a zombie !"<<endl;
                   r[i-1].ene--;
                 }
                 else{
                   cout<<"run or else zombie will kill you"<<endl;
                 }
            }
            else if(i==6){
              cout<<"This is not a zombie...This is a MONSTERRRRR !!!!!!!!"<<endl;
            }
            else{
              cout<<"There is no zombie here"<<endl;
            }
       }

        else if(cmd == "kill monster"){
            if(r[i-1].hasEnemies() && i!=6){
                 cout<<"There is no monster here"<<endl;
            }
            else if(r[i-1].hasEnemies() && i==6){
                 if(p.hasAcc("gun") && p.hasAcc("sword")){
                   cout<<"You killed a Monster !"<<endl;
                   r[i-1].ene--;
                 }
                 else{
                     cout<<"You are dead !! GAME OVER "<<endl;
                 }
            }
            else{
              cout<<"There is no zombie here"<<endl;
            }
       }

        else
          break;
       
    }

    return 0;
}