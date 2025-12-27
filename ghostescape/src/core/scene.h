//
// Created by 18201 on 2025/12/19.
//

#ifndef GHOSTESCAPE_SCENE_H
#define GHOSTESCAPE_SCENE_H

#include "object.h"

class Scene: public Object
{
protected:
    glm::vec2 camera_position_ = glm::vec2(0);  // 相机位置
    glm::vec2 world_size_ = glm::vec2(0); // 世界大小
    std::vector<Object*> objects_; // 场景中的物体
public:
    void init() override {}
    void handleEvents(SDL_Event& event) override {}
    void update(float dt) override {}
    void render() override {}
    void clean() override {}

    [[nodiscard]] glm::vec2 worldToScreen(const glm::vec2 &world_position) const {return world_position - camera_position_; }
    [[nodiscard]] glm::vec2 screenToWorld(const glm::vec2 &screen_position) const {return screen_position + camera_position_; }

    [[nodiscard]] glm::vec2 getWorldSize() const { return world_size_; }
    void setWorldSize(const glm::vec2 &world_size) { world_size_ = world_size; }

    [[nodiscard]] glm::vec2 getCameraPosition() const { return camera_position_; }
    void setCameraPosition(const glm::vec2 &camera_position);
};


#endif //GHOSTESCAPE_SCENE_H