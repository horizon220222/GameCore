//
// Created by 18201 on 2025/12/27.
//

#ifndef GHOSTESCAPE_PLAYER_H
#define GHOSTESCAPE_PLAYER_H
#include "core/actor.h"


class Player: public Actor
{
public:

    void init() override;
    void handleEvents(SDL_Event& event) override;
    void update(float dt) override;
    void render() override;
    void clean() override;

    void keyboardControl();
    void move(float dt);
    void syncCamera();
};


#endif //GHOSTESCAPE_PLAYER_H