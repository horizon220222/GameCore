//
// Created by 18201 on 2026/1/11.
//

#ifndef GHOSTESCAPE_COLLIDER_H
#define GHOSTESCAPE_COLLIDER_H

#include "../core/object_affiliate.h"

class Collider : public ObjectAffiliate
{
protected:
    enum class Type{
        CIRCLE,
        RECTANGLE
    };
    Type type_ = Type::CIRCLE;

public:
    void render() override;

    static Collider* addColliderChild(ObjectScreen* parent, glm::vec2 size, Type type = Type::CIRCLE, Anchor anchor = Anchor::CENTER);
    bool isColliding(Collider* other);

    // getters and setters
    Type type() const { return type_; }
    void setType(Type type) { type_ = type; }
};


#endif //GHOSTESCAPE_COLLIDER_H