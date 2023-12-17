#include "users.h"
#include <Arduino.h>

void User::show(){
  Serial.println(UID);
}

Users::Users(){ //This actually already happened in the constructor of Users
    for (IDXt i = 0; i < N_USERS; ++i)
    {
        users[i] = User(BADUSER);
    }
}

bool Users::find(UIDt uid){
    for(User &user:users)
    {
        if(user == User(uid)){
            return true;
        }
    }
    return false;
}

bool Users::add(UIDt uid){
    if(find(uid))
    {
      return false;
    }
    for(User &user:users)
    {
        if(user == User(BADUSER)){
            user = User(uid);
            return true;
        }
    }
    return false;
}

bool Users::del(UIDt uid){
    for(User &user:users)
    {
        if(user == User(uid)){
            user = User(BADUSER);
            return true;
        }
    }
    return false;
}

void Users::show(){
  for(User &user:users)
  {
    if(!(user == User(BADUSER)))
    {
      user.show();
    }
  }
}