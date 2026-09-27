#ifndef THEMOLLUSK_ASSET_MANAGER_H
#define THEMOLLUSK_ASSET_MANAGER_H

#include <raylib.h>
#include <string>
#include <vector>

#include "TextureHandle.h"

class AssetManager {
public:
    AssetManager() {
        _textures.push_back(Texture2D{});
    }

    TextureHandle load(const std::string& path) {
        Texture2D texture = LoadTexture(path.c_str());
        _textures.push_back(texture);
        
        return TextureHandle{ 
            static_cast<uint32_t>(_textures.size() - DEFAULT_SIZE) 
        };
    }

    const Texture2D& get(TextureHandle handle) const {
        return _textures[handle.id]; 
    }

    void unloadAll() {
        for(size_t i = FIRST_TEXTURE_IDX; i < _textures.size(); ++i) {
            UnloadTexture(_textures[i]);
        }
        _textures.resize(DEFAULT_SIZE);
    }

private:
    static constexpr size_t DEFAULT_SIZE = 1;
    static constexpr size_t FIRST_TEXTURE_IDX = DEFAULT_SIZE;
    std::vector<Texture2D> _textures;
};

#endif // !THEMOLLUSK_ASSET_MANAGER_H