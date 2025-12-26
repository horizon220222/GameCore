//
// Created by 18201 on 2025/12/19.
//

#ifndef HORIZONSURVIVAL_SCENE_MAIN_H
#define HORIZONSURVIVAL_SCENE_MAIN_H

#include "core/scene.h"


class SceneMain : public Scene
{
private:
    glm::vec2 world_size_ = glm::vec2(0);


public:
    // 所有的类，不在构造函数和析构函数里面做任何事
    SceneMain() = default;
    virtual ~SceneMain() = default;

    virtual void init() override;
    virtual void handleEvents(SDL_Event& event) override;
    virtual void update(float dt) override;
    virtual void render() override;
    virtual void clean() override;

    void renderBackground();
};


#endif //HORIZONSURVIVAL_SCENE_MAIN_H