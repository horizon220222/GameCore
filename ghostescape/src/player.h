//
// Created by 18201 on 2025/12/27.
//

#ifndef GHOSTESCAPE_PLAYER_H
#define GHOSTESCAPE_PLAYER_H

#include "core/actor.h"
#include "affiliate/sprite_anim.h"

class Player: public Actor
{
private:
    SpriteAnim* sprite_idle_ = nullptr;
    SpriteAnim* sprite_move_ = nullptr;
    bool is_moving_ = false;

public:
    void init() override;
    void handleEvents(SDL_Event& event) override;
    void update(float dt) override;
    void render() override;
    void clean() override;

    void keyboardControl();
    void syncCamera();

    void checkState();
    void changeState(bool is_moving);
};


#endif //GHOSTESCAPE_PLAYER_H