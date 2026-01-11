//
// Created by 18201 on 2025/12/28.
//

#include "object.h"

void Object::handleEvents(SDL_Event& event)
{
    for (auto& child : children_)
    {
        if(child->getActive())
        {
            child->handleEvents(event);
        }
    }
}

void Object::update(float dt)
{
    for (auto it = children_.begin(); it != children_.end();) {
        auto child = *it;
        if (child->getNeedRemove()){
            it = children_.erase(it);
            child->clean();
            delete child;
        } else {
            if(child->getActive()) {
                child->update(dt);
            }
            ++it;
        }
    }
}

void Object::render()
{
    for (auto& child : children_)
    {
        if(child->getActive())
        {
            child->render();
        }
    }
}

void Object::clean()
{
    for (auto& child : children_)
    {
        if(child->getActive())
        {
            child->clean();
        }
    }
}