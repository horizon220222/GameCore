//
// Created by 18201 on 2025/12/27.
//
#include "scene.h"

void Scene::setCameraPosition(const glm::vec2 &camera_position)
{
    camera_position_ = camera_position;
    camera_position_ = glm::clamp(camera_position_, glm::vec2(0, 0), world_size_ - game_.getScreenSize());
}