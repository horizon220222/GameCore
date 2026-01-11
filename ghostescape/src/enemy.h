//
// Created by 18201 on 2025/12/28.
//

#ifndef GHOSTESCAPE_ENEMY_H
#define GHOSTESCAPE_ENEMY_H

#include "core/actor.h"
#include "player.h"

class Enemy : public Actor
{
private:
    enum class State{
        NORMAL,
        HURT,
        DIE
    };
    State current_state_ = State::NORMAL;
    Player* target_ = nullptr;

    SpriteAnim* anim_normal_ = nullptr;
    SpriteAnim* anim_hurt_ = nullptr;
    SpriteAnim* anim_die_ = nullptr;

    SpriteAnim* current_anim_ = nullptr;

    float timer_ = 0.0f;  // 用于演示状态切换的计时器
public:
    void init() override;
    void update(float dt) override;

    void aim_target(Player* target);

    void checkState();
    void changeState(State new_state);
    void remove();

    // getters and setters
    Player* get_target() { return target_; }
    void set_target(Player* target) { target_ = target; }
};


#endif //GHOSTESCAPE_ENEMY_H