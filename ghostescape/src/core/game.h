#ifndef GHOSTESCAPE_GAME_H
#define GHOSTESCAPE_GAME_H

#include <string>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <glm/glm.hpp>

class Scene;
class Game
{
private:
    // 窗口和渲染
    glm::vec2 screen_size_ = glm::vec2(0);
    SDL_Window* window_ = nullptr;
    SDL_Renderer* renderer_ = nullptr;

    // 是否正在运行
    bool is_running_ = true;

    // 当前场景
    Scene* current_scene_ = nullptr; // 当前场景

    // FPS dt_单位s
    Uint64 FPS_ = 60;
    Uint64 frame_delay_ = 0;
    float dt_ = 0.0f;


    Game(){}
public:
    static Game& GetInstance()
    {
        static Game instance;
        return instance;
    }

    // 禁止拷贝构造函数与赋值操作符
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;


    void run(); // 运行游戏, 执行游戏主循环

    void init(const std::string& title, int width, int height); // 初始化游戏
    void handleEvents(); // 处理事件
    void update(float dt); // 更新游戏状态
    void render(); // 渲染游戏
    void clean(); // 清理游戏资源

    // 工具函数
    [[nodiscard]] glm::vec2 getScreenSize() const { return screen_size_; } // 获取屏幕大小
    [[nodiscard]] Scene* getCurrentScene() const { return current_scene_; } // 获取当前场景
    void drawGrid(const glm::vec2& top_left, const glm::vec2& botton_right, float grid_width, SDL_FColor fcolor); // 绘制网格
    void drawBoundary(const glm::vec2& top_left, const glm::vec2& botton_right, float boundary_width, SDL_FColor fcolor); // 绘制边界
};


#endif //GHOSTESCAPE_GAME_H