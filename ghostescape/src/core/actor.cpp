//
// Created by 18201 on 2025/12/28.
//

#include "actor.h"
#include "scene.h"

void Actor::move(float dt)
{
    setPosition(position_ + velocity_ * dt);
    position_ = glm::clamp(position_, glm::vec2(0, 0), game_.getCurrentScene()->getWorldSize());
}