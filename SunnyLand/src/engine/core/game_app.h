//
// Created by 18201 on 2026/1/31.
//

#ifndef SUNNYLAND_GAME_APP_H
#define SUNNYLAND_GAME_APP_H

#include <memory>

// 前向声明, 减少头文件的依赖，增加编译速度
struct SDL_Window;
struct SDL_Renderer;

namespace engine::core
{
    class Time;

    /**
     * @brief 主游戏应用程序类，初始化SDL，管理游戏循环。
     */
    class GameApp final
    {
    private:
        SDL_Window* window_ = nullptr;
        SDL_Renderer* sdl_renderer_ = nullptr;
        bool is_running_ = false;

        // 引擎组件
        std::unique_ptr<engine::core::Time> time_;


    public:
        GameApp();
        ~GameApp();

        /**
         * @brief 运行游戏应用程序，其中会调用init()，然后进入主循环，离开循环后自动调用close()。
         */
        void run();

        // 禁止拷贝和移动
        GameApp(const GameApp&) = delete;
        GameApp& operator=(const GameApp&) = delete;
        GameApp(GameApp&&) = delete;
        GameApp& operator=(GameApp&&) = delete;

    private:
        [[nodiscard]] bool init();
        void handleEvents();
        void update(float delta_time);
        void render();
        void close();
    };
}


#endif //SUNNYLAND_GAME_APP_H
