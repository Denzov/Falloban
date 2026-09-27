#ifndef THEMOLLUSK_SPRITE_H
#define THEMOLLUSK_SPRITE_H

#include <raylib.h>

#include "Math/Values.h"
#include "Math/Vec2.h"

class Sprite {
public:
    Texture2D texture;
    Math::Vec2 local_offset;
    Math::Vec2 scale;
    Color tint;

    void draw(Math::Vec2 world_pos, float world_rot) const {      
        const Math::Vec2 final_pos = 
            world_pos + local_offset.rotated(world_rot);

        const float half_tex_width = texture.width * 0.5f;
        const float half_tex_height = texture.height * 0.5f;

        const Rectangle source {
            .x = Math::ZERO_VEC2.x,
            .y = Math::ZERO_VEC2.y,
            .width = static_cast<float>(texture.width),
            .height = static_cast<float>(texture.height)
        };

        const Rectangle dest {
            .x = final_pos.x,
            .y = final_pos.y, 
            .width = texture.width * scale.x,
            .height = texture.height * scale.y
        };

        const Math::Vec2 origin = {
            half_tex_width * scale.x,
            half_tex_height * scale.y
        };
        
        DrawTexturePro(
            texture,
            source, 
            dest,
            {origin.x, origin.y}, 
            world_rot * RAD2DEG, 
            tint
        );
    }
};

#endif // !THEMOLLUSK_SPRITE_H