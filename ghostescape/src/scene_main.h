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
    void init() override;
    void handleEvents(SDL_Event& event) override;
    void update(float dt) override;
    void render() override;
    void clean() override;

    void renderBackground();
};


#endif //GHOSTESCAPE_SCENE_MAIN_H