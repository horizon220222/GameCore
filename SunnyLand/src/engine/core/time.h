//
// Created by 18201 on 2026/1/31.
//

#ifndef SUNNYLAND_TIME_H
#define SUNNYLAND_TIME_H

#include <SDL3/SDL_stdinc.h>    // 用于 Uint64

namespace engine::core
{
    class Time final
    {
    private:
        Uint64 last_time_ = 0; ///< @brief 上一帧的时间戳 (用于计算 delta)
        Uint64 frame_start_time_ = 0; ///< @brief 当前帧开始的时间戳 (用于帧率限制)
        double delta_time_ = 0.0; ///< @brief 未缩放的帧间时间差 (秒)
        double time_scale_ = 1.0; ///< @brief 时间缩放因子

        // 帧率限制相关
        int target_fps_ = 0; ///< @brief 目标 FPS (0 表示不限制)
        double target_frame_time_ = 0.0; ///< @brief 目标每帧时间 (秒)

    public:
        Time();

        void update();
        [[nodiscard]] double getDeltaTime() const;
        [[nodiscard]] double getUnscaledDeltaTime() const;
        void setTimeScale(double scale);
        [[nodiscard]] double getTimeScale() const;
        void setTargetFps(int fps);
        [[nodiscard]] int getTargetFps() const;

    private:
        void limitFrameRate(double current_delta_time);
    };
}

#endif //SUNNYLAND_TIME_H
