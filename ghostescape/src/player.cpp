//
// Created by 18201 on 2025/12/27.
//

#include "player.h"
#include "affiliate/sprite_anim.h"
#include "core/scene.h"

void Player::init()
{
    Actor::init();
    max_speed_ = 500.0f;
    SpriteAnim::addSpriteAnimChild(this, "assets/sprite/ghost-idle.png", 2.0f);
}

void Player::handleEvents(SDL_Event& event)
{
    Actor::handleEvents(event);
}

void Player::update(float dt)
{
    Actor::update(dt);
    keyboardControl();
    move(dt);
    syncCamera();
}

void Player::render()
{
    Actor::render();
    game_.drawBoundary(render_position_, render_position_, 1.0f, {1.0, 0.0, 0.0, 1.0});
}

void Player::clean()
{
    Actor::clean();
}

void Player::keyboardControl()
{
    velocity_ *= 0.9f; // 慢慢停下来

    auto currentKeyStates = SDL_GetKeyboardState(NULL);
    if (currentKeyStates[SDL_SCANCODE_W]){
        velocity_.y = -max_speed_;
    }
    if (currentKeyStates[SDL_SCANCODE_S]){
        velocity_.y = max_speed_;
    }
    if (currentKeyStates[SDL_SCANCODE_A]){
        velocity_.x = -max_speed_;
    }
    if (currentKeyStates[SDL_SCANCODE_D]){
        velocity_.x = max_speed_;
    }
}

void Player::move(float dt)
{
    // 更新位置，位置 + 速度 * dt(时间)
    setPosition(position_ + velocity_ * dt);
    position_ = glm::clamp(position_, glm::vec2(0, 0), game_.getCurrentScene()->getWorldSize());
}

void Player::syncCamera()
{
    glm::vec2 targetPos = position_ - game_.getScreenSize() / 2.0f;
    glm::vec2 currentPos = game_.getCurrentScene()->getCameraPosition();
    float smoothFactor = 0.1f; // 较小的值移动更平滑
    glm::vec2 newPos = currentPos + (targetPos - currentPos) * smoothFactor;
    game_.getCurrentScene()->setCameraPosition(newPos);

    // game_.getCurrentScene()->setCameraPosition(position_ - game_.getScreenSize() / 2.0f);
}
