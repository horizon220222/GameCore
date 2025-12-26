//
// Created by 18201 on 2025/12/19.
//

#include "scene_main.h"

void SceneMain::init()
{
    world_size_ = game_.getScreenSize() * 3.0f; // 世界大小为屏幕的3倍
    camera_position_ = glm::vec2(0); // 初始相机位置
}

void SceneMain::handleEvents(SDL_Event& event)
{

}

void SceneMain::update(float dt)
{
    camera_position_ += dt * glm::vec2(128.0f, 72.0f);

    //坐标: 相机 = 世界X - 屏幕
    camera_position_.x = std::max(0.0f, std::min(camera_position_.x, world_size_.x - game_.getScreenSize().x));
    camera_position_.y = std::max(0.0f, std::min(camera_position_.y, world_size_.y - game_.getScreenSize().y));
}

void SceneMain::render()
{
    renderBackground();
}

void SceneMain::renderBackground()
{
    //坐标: 屏幕 = 世界X - 相机
    auto start = glm::vec2(0, 0) - camera_position_;
    auto end = world_size_ - camera_position_;
    game_.drawGrid(start, end, 80.0f, {0.5, 0.5, 0.5, 1.0});
}

void SceneMain::clean()
{

}
