#include "Sprite.h"
#include <iostream>

namespace spritesheet {
    Sprite::Sprite(Texture2D &texture) : texture(texture) {
        srcRect = {0, 0, (float)texture.width, (float)texture.height};
        dstRect = srcRect;

        origin = {0, 0};
        rotation = 0;
        tint = WHITE;

        flipHorizontal = false;
        flipVertical = false;
    }

    Rectangle Sprite::GetBounds() {
        return dstRect;
    }

    void Sprite::Update() {
        if (flipHorizontal) {
            srcRect.width = -srcRect.width;
        }

        if (flipVertical) {
            srcRect.height = -srcRect.width;
        }
    }

    void Sprite::Draw() {
        DrawTexturePro(texture, srcRect, dstRect, origin, rotation, tint);
    }
}