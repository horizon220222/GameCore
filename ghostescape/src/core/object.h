//
// Created by 18201 on 2025/12/19.
//

#ifndef GHOSTESCAPE_OBJECT_H
#define GHOSTESCAPE_OBJECT_H

#include "game.h"
#include "defs.h"

class Object
{
protected:
    Game& game_ = Game::GetInstance();

    ObjectType type_ = ObjectType::NONE;
    std::vector<Object*> children_;
public:
    // 所有的类，不在构造函数和析构函数里面做任何事
    Object() = default;
    virtual ~Object() = default;

    virtual void init() {}      // 需要初始化的事物，在init()函数里面做。
    virtual void handleEvents(SDL_Event& event);
    virtual void update(float dt);
    virtual void render();
    virtual void clean();     // 需要清理的资源，在clean()函数里面做。

    [[nodiscard]] ObjectType getType() const { return type_; }
    void setType(ObjectType type) { type_ = type; }

    virtual void addChild(Object* child) { children_.push_back(child); }
    virtual void removeChild(Object* child) {
        children_.erase(std::remove(children_.begin(), children_.end(), child), children_.end());
    }
};


#endif //GHOSTESCAPE_OBJECT_H