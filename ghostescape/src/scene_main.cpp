//
// Created by 18201 on 2025/12/19.
//

#include "scene_main.h"
#include "player.h"

void SceneMain::init()
{
    world_size_ = game_.getScreenSize() * 3.0f; // 世界大小为屏幕的3倍
    camera_position_ = glm::vec2(0); // 初始相机位置

    player_ = new Player();
    player_->init();
    player_->setPosition(world_size_ / 2.0f);
    addChild(player_);
}

void SceneMain::handleEvents(SDL_Event& event)
{
    Scene::handleEvents(event);
}

void SceneMain::update(float dt)
{
    Scene::update(dt);
}

void SceneMain::render()
{
    renderBackground();
    Scene::render();
}

void SceneMain::clean()
{
    Scene::clean();
}

void SceneMain::renderBackground()
{
    //坐标: 屏幕 = 世界X - 相机
    auto start =  worldToScreen(glm::vec2(0, 0));
    auto end = worldToScreen(world_size_);
    game_.drawGrid(start, end, 80.0f, {0.5, 0.5, 0.5, 1.0});
}
