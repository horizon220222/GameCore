//
// Created by 18201 on 2025/12/19.
//

#ifndef GHOSTESCAPE_SCENE_MAIN_H
#define GHOSTESCAPE_SCENE_MAIN_H

#include "core/scene.h"

class Player;
class SceneMain : public Scene
{
private:
    Player* player_ = nullptr;

public:
    // 所有的类，不在构造函数和析构函数里面做任何事
    SceneMain() = default;
    virtual ~SceneMain() = default;

    void init() override;
    void handleEvents(SDL_Event& event) override;
    void update(float dt) override;
    void render() override;
    void clean() override;

    void renderBackground();
};


#endif //GHOSTESCAPE_SCENE_MAIN_H