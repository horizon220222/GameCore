//
// Created by 18201 on 2025/12/27.
//

#ifndef GHOSTESCAPE_ACTOR_H
#define GHOSTESCAPE_ACTOR_H

#include "object_world.h"

class Actor : public ObjectWorld
{
protected:
    glm::vec2 velocity_ = glm::vec2(0, 0); // 速度
    float max_speed_ = 100.0f; // 最大速度大小

public:
    [[nodiscard]] glm::vec2 getVelocity() const { return velocity_; }
    void setVelocity(const glm::vec2& velocity) { velocity_ = velocity; }
    [[nodiscard]] float getMaxSpeed() const { return max_speed_; }
    void setMaxSpeed(float max_speed) { max_speed_ = max_speed; }
};


#endif //GHOSTESCAPE_ACTOR_H