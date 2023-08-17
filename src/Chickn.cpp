#include "Chickn.h"
#include <raymath.h>
#include <iostream>
#include "Globals.h"

namespace spritesheet {
    Chickn::Chickn(Texture2D &texture, Sound &bruh) : AnimatedSprite(texture), bruh(bruh) {
        walkFrames = {
            Rectangle{0, 0, 32, 32},
            Rectangle{32, 0, 32, 32}
        };

        talkFrames = {
            Rectangle{0, 0, 32, 32},
            Rectangle{32, 0, 32, 32},
            Rectangle{64, 0, 32, 32},
            Rectangle{0, 32, 32, 32},
            Rectangle{32, 32, 32, 32},
            Rectangle{64, 32, 32, 32},
            Rectangle{0, 64, 32, 32},
            Rectangle{32, 64, 32, 32},
            Rectangle{64, 64, 32, 32}
        };

        SetAnimation(walkFrames, 0.5f, true);

        dstRect = {Globals::WINDOW_WIDTH / 2 - 64, Globals::WINDOW_HEIGHT / 2 - 64, 192, 192};
        
        speed = 300;

        direction = Vector2Zero();
    }

    void Chickn::Update() {
        if (!Vector2Equals(direction, Vector2Zero())) {
            Vector2 normalized = Vector2Normalize(direction);

            dstRect.x += normalized.x * speed * GetFrameTime();
            dstRect.y += normalized.y * speed * GetFrameTime();
        }

        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            direction.x = -1;
            flipHorizontal = true;
        }
        else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            direction.x = 1;
            flipHorizontal = false;
        }
        else
            direction.x = 0;
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
            direction.y = -1;
        else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
            direction.y = 1;
        else
            direction.y = 0;

        if (IsKeyPressed(KEY_SPACE)) {
            SetAnimation(talkFrames, 0.1f, false);
            PlaySound(bruh);
        } else if (std::addressof(*getAnimation()) == std::addressof(talkFrames) && finished) {
            SetAnimation(walkFrames, 0.5f, true);
        }

        AnimatedSprite::Update();
    }
}