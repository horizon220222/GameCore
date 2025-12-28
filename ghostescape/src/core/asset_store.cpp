//
// Created by 18201 on 2025/12/28.
//

#include "asset_store.h"

void AssetStore::loadImage(const std::string& file_path)
{
    SDL_Texture* texture = IMG_LoadTexture(renderer_, file_path.c_str());
    if (texture == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load image: %s", file_path.c_str());
        return;
    }
    textures_.emplace(file_path, texture);
}

void AssetStore::loadFont(const std::string& file_path, int font_size)
{
    TTF_Font* font = TTF_OpenFont(file_path.c_str(), static_cast<float>(font_size));
    if (font == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load font: %s", file_path.c_str());
        return;
    }
    fonts_.emplace(file_path + std::to_string(font_size), font);
}

SDL_Texture* AssetStore::getImage(const std::string& file_path)
{
    auto iter = textures_.find(file_path);
    if (iter == textures_.end())
    {
        loadImage(file_path);
        iter = textures_.find(file_path);
    }
    if (iter == textures_.end())
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to get image: %s", file_path.c_str());
        return nullptr;
    }
    return iter->second;
}

TTF_Font* AssetStore::getFont(const std::string& file_path, int font_size)
{
    auto iter = fonts_.find(file_path + std::to_string(font_size));
    if (iter == fonts_.end())
    {
        loadFont(file_path, font_size);
        iter = fonts_.find(file_path + std::to_string(font_size));
    }
    if (iter == fonts_.end())
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to get font: %s", file_path.c_str());
        return nullptr;
    }
    return iter->second;
}

void AssetStore::clean()
{
    for (auto& texture : textures_)
    {
        SDL_DestroyTexture(texture.second);
    }
    textures_.clear();

    for (auto& font : fonts_)
    {
        TTF_CloseFont(font.second);
    }
    fonts_.clear();
}
