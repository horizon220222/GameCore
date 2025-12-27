cmake_minimum_required(VERSION 3.20)
project(GHOSTESCAPE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (MSVC)
    add_compile_options(/utf-8)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(TARGET ${PROJECT_NAME}-${CMAKE_SYSTEM_NAME})

## 查找并载入Cmake预设
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_ttf REQUIRED)
find_package(glm CONFIG REQUIRED)

## 添加可执行文件
add_executable(${TARGET}
        src/main.cpp
        src/core/game.cpp
        src/core/game.h
        src/scene_main.cpp
        src/scene_main.h
        src/core/scene.h
        src/core/object.h
        src/core/object_screen.h
        src/core/object_world.h
        src/core/object_world.cpp
        src/core/actor.h
        src/player.cpp
        src/player.h
        src/core/scene.cpp
)

## 链接库
target_link_libraries(${TARGET}
        ${SDL3_LIBRARIES}
        SDL3_image::SDL3_image
        SDL3_ttf::SDL3_ttf
        glm::glm
)