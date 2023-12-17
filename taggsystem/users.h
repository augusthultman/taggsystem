#ifndef USERS_H
#define USERS_H

#include <Arduino.h>
#include <stdint.h>

typedef uint32_t UIDt;
#define BADUSER (UIDt)-1

typedef int IDXt;
#define N_USERS 50
#define IDX_BADUSER (N_USERS+1)

class User {
private:
    UIDt UID;
public:
    explicit User(UIDt uid) {UID = uid;}
    User(void) {UID = BADUSER;}
    bool operator == (const User &other){
      return other.UID == UID;
    }
    void show();
    UIDt getUID() {return UID;}
    static UIDt fromRaw(byte* b){return (UIDt)*((uint32_t*)b);}
};

class Users {
private:
    User users[N_USERS];
public:
    Users();
    bool find(UIDt uid);
    bool add(UIDt uid);
    bool del(UIDt uid);
    void show();
};

#endif //USERS_H