//
// Created by 18201 on 2025/12/27.
//

#ifndef GHOSTESCAPE_OBJECT_WORLD_H
#define GHOSTESCAPE_OBJECT_WORLD_H

#include "object_screen.h"
#include "../affiliate/collider.h"

class Collider;

class ObjectWorld : public ObjectScreen
{
protected:
    glm::vec2 position_ = glm::vec2(0, 0); // 世界位置
    Collider* collider_ = nullptr;

public:
    void init() override {type_ = ObjectType::OBJECT_WORLD;}
    glm::vec2 getPosition() const override { return position_; }
    void setPosition(const glm::vec2& position);
    void setRenderPosition(const glm::vec2& render_position) override;
    void update(float dt) override;
    Collider* getCollider() { return collider_; }
    void setCollider(Collider* collider) { collider_ = collider; }
};

#endif //GHOSTESCAPE_OBJECT_WORLD_H