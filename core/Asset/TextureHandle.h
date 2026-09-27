#ifndef THEMOLLUSK_TEXTURE_HANDLE_H
#define THEMOLLUSK_TEXTURE_HANDLE_H

#include <cstdint>

struct TextureHandle{
    uint32_t id = 0;

    bool isValid() const { return id != 0; }
};

#endif // !THEMOLLUSK_TEXTURE_HANDLE_H