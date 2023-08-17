#include "AnimatedSprite.h"
#include <iostream>

namespace spritesheet {
    AnimatedSprite::AnimatedSprite(Texture2D &texture) : Sprite(texture)  {
        currentAnimation = nullptr;
        currentFrame = 0;
        frameTime = 0.1f;
        timer = 0;
        loop = true;
        playing = true;
        finished = false;
    }

    void AnimatedSprite::ToggleAnimation(bool toggle) {
        playing = toggle;
    }

    void AnimatedSprite::SetAnimation(std::vector<Rectangle> &animation, float frameTime, bool loop) {
        currentAnimation = &animation;
        this->frameTime = frameTime;
        this->loop = loop;
        currentFrame = 0;
    }

    void AnimatedSprite::Update() {
        if (playing) {
            if (timer >= frameTime) {
                if (currentFrame < static_cast<int>(currentAnimation->size()) - 1) {
                    currentFrame++;
                    finished = false;
                }
                else {
                    if (loop)
                        currentFrame = 0;
                    else
                        finished = true;
                }
                timer = 0;
            } else {
                timer += GetFrameTime();
            }
        }

        srcRect = (*currentAnimation)[currentFrame];

        Sprite::Update();
    }

    std::vector<Rectangle>* AnimatedSprite::getAnimation() {
        return currentAnimation;
    }
}