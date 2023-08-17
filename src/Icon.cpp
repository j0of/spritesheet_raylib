#include "Icon.h"
#include "Globals.h"
#include <iostream>

namespace spritesheet {
    Icon::Icon(Texture2D& texture) : Sprite(texture) {
        direction = {1, 1};
        speed = 200;

        dstRect.x = Globals::WINDOW_WIDTH / 2 - dstRect.width / 2;
        dstRect.y = Globals::WINDOW_HEIGHT / 2 - dstRect.height / 2;
    }

    void Icon::Update() {
        dstRect.x += direction.x * speed * GetFrameTime();
        dstRect.y += direction.y * speed * GetFrameTime();

        if (dstRect.x <= 0 || dstRect.x + dstRect.width >= Globals::WINDOW_WIDTH) {
            direction.x = -direction.x;
        }
        if (dstRect.y <= 0 || dstRect.y + dstRect.height >= Globals::WINDOW_HEIGHT) {
            direction.y = -direction.y;
        }
    }
}