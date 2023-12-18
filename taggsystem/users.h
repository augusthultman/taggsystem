#ifndef USERS_H
#define USERS_H

//#include <Arduino.h>
#include <stdint.h>
#include <array>

using UIDt = std::array<uint8_t, 10>;
constexpr auto BADUSER = std::array<uint8_t, 10>{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};


typedef int IDXt;
#define N_USERS 50
#define IDX_BADUSER (N_USERS+1)

class User {
private:
    UIDt UID = BADUSER;
public:
    explicit User(UIDt uid) {UID = uid;}
    User() = default;
    bool operator == (const User &other){
      return other.UID == UID;
    }
    void show();
    UIDt getUID() {return UID;}
    static UIDt fromRaw(const uint8_t* b){
      auto id = std::array<uint8_t, 10>{};
      std::copy(b, b + 10, id.begin());
      return id;
    }
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
