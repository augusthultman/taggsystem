#pragma once

#include "uidt.h"
#include "users.h"

struct State {
    enum StateNum {
        Start = 0,
        AddUser,
        AddAdmin,
        RemoveUser,

        NoUsers,
    };

    StateNum state = Start;
    bool isWaitingForButtonRelease = false;
    UIDt currentId;

    void wait();
    void reset();

    /// Note that id can be nullptr
    /// Returns value of relay pin
    bool handle(Users &users, const UIDt *id, bool isPressed);

private:
    /// This is the only mode that can turn of the relay hence the only function
    /// that returns true
    bool handleStart(Users &users, const UIDt *id, bool isPressed);
    void handleAddUser(Users &users, const UIDt *id, bool isPressed);
    void handleAddAdmin(Users &users, const UIDt *id, bool isPressed);
    void handleRemoveUser(Users &users, const UIDt *id, bool isPressed);

    /// If no user is set, the first user showing it's id will be admin
    void handleNoUser(Users &users, const UIDt *id, bool isPressed);
};
