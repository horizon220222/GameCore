//
// Created by 18201 on 2025/12/19.
//

#ifndef HORIZONSURVIVAL_SCENE_H
#define HORIZONSURVIVAL_SCENE_H

#include "object.h"

class Scene: public Object
{
protected:
    glm::vec2 camera_position_ = glm::vec2(0);
    std::vector<Object*> objects_;
public:
    // 所有的类，不在构造函数和析构函数里面做任何事
    Scene() = default;
    virtual ~Scene() = default;

    virtual void init() {}
    virtual void handleEvents(SDL_Event& event) {}
    virtual void update(float dt) {}
    virtual void render() {}
    virtual void clean() {}
};


#endif //HORIZONSURVIVAL_SCENE_H