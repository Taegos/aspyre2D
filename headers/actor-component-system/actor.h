#pragma once

class Actor {
public:
    Actor();
    virtual void update(float) = 0;
    int getId() const;
protected:
    const int id;
private: 
    static int currentId;
};