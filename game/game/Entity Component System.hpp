//
//  Entity Component System.hpp
//  game
//
//  Created by Dawid on 22/04/2018.
//  Copyright © 2018 game. All rights reserved.
//

#ifndef Entity_Component_System_hpp
#define Entity_Component_System_hpp

#include <bits/stdc++.h>
using namespace std;

class Component;
class Entity;

using ComponentID = size_t;

inline ComponentID getComponentID()
{
    static ComponentID lastID = 0;
    return lastID++;
}

template <typename T> inline ComponentID getComponentID() noexcept
{
    static ComponentID typeID = getComponentID();
    return typeID;
}

constexpr size_t maxComponents = 32;

using ComponentBitSet = bitset<maxComponents>;
using ComponentArray = array<Component*, maxComponents>;

class Component
{
public:
    Entity* entity;
    
    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}
    
    virtual ~Component() {}
    
};

class Entity
{
private:
    bool active = true;
    
    vector <unique_ptr<Component>> components;
    
    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
    
public:
    void update()
    {
        for(auto &c: components) c->update();
        for(auto &c: components) c->draw();
    }
    
    void draw(){}
    
    bool isActive() const { return active; }
    
    void destroy() {  active = false; }
    
    template <typename T> bool hasComponents() const
    {
        return componentBitSet[getComponentID<T>];
    }
    
//    template <typename T, typename ... Targs>
//    {
//     T& addComponent(Targs&& ... mArgs)
//        
//    }
    
};

#endif /* Entity_Component_System_hpp */
