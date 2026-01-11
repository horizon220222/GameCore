//
// Created by 18201 on 2025/12/27.
//

#ifndef GHOSTESCAPE_OBJECT_SCREEN_H
#define GHOSTESCAPE_OBJECT_SCREEN_H

#include "object.h"

class ObjectScreen : public Object
{
protected:
    glm::vec2 render_position_ = glm::vec2(0, 0); // 渲染(屏幕)位置
    void init() override {type_ = ObjectType::OBJECT_SCREEN;}
public:
    glm::vec2 getRenderPosition() const { return render_position_; }
    virtual void setRenderPosition(const glm::vec2& render_position) { render_position_ = render_position; }
    virtual glm::vec2 getPosition() const { return glm::vec2(0); }
};

#endif //GHOSTESCAPE_OBJECT_SCREEN_H