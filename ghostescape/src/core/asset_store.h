//
// Created by 18201 on 2025/12/28.
//

#ifndef GHOSTESCAPE_ASSET_STORE_H
#define GHOSTESCAPE_ASSET_STORE_H

#include <unordered_map>  //无序map
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>

class AssetStore
{
private:
    SDL_Renderer* renderer_ = nullptr;
    std::unordered_map<std::string, SDL_Texture*> textures_;
    std::unordered_map<std::string, TTF_Font*> fonts_;
public:
    explicit AssetStore(SDL_Renderer* renderer) { renderer_ = renderer; }
    ~AssetStore() = default;

    void loadImage(const std::string& file_path);
    void loadFont(const std::string& file_path, int font_size);

    SDL_Texture* getImage(const std::string& file_path);
    TTF_Font* getFont(const std::string& file_path, int font_size);

    void clean();
};


#endif //GHOSTESCAPE_ASSET_STORE_H