#ifndef GAME_HPP
#define GAME_HPP
#include "Game.cpp"

Game::Game(){
    play=1;
}

Player::Player(){
    health = 100;
    currentRoom = 1;
    
}

void Player::print_acc(){
    for(int i=0;i<accP.size();i++){
        cout<<accP.at(i)<<endl;
    }
}

void Rooms::addAcc(string name){
      acc.push_back(name);
}

bool Rooms::hasAcc(string name){
      for(auto i=acc.begin();i!=acc.end();i++){
          if(*i == name) return true;
      }
      return false;
}

bool Player::hasAcc(string name){
      for(auto i=accP.begin();i!=accP.end();i++){
          if(*i == name) return true;
      }
      return false;
}

bool Player::hasKey(){
     for(auto i=accP.begin();i!=accP.end();i++){
          if(*i == "key to treasure room") return true;
      }
      return false;
}


#endif
