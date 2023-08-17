#include "Sprite.h"
#include <vector>

namespace spritesheet {
    class AnimatedSprite : public Sprite {
        public:
            AnimatedSprite(Texture2D &texture);
            void SetAnimation(std::vector<Rectangle> &animation, float frameTime, bool loop);
            void ToggleAnimation(bool toggle);
            void Update() override;
        private:
            std::vector<Rectangle> *currentAnimation;
            int currentFrame;
            float frameTime;
            float timer;
            bool playing;
        protected:
            bool loop;
            bool finished;
            std::vector<Rectangle>* getAnimation();
    };
}