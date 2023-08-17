#include "AnimatedSprite.h"

namespace spritesheet {
    class Chickn : public AnimatedSprite {
        public:
            Chickn(Texture2D &texture, Sound &bruh);
            void Update() override;
        private:
            int speed;
            Vector2 direction;
            std::vector<Rectangle> walkFrames;
            std::vector<Rectangle> talkFrames;
            Sound &bruh;
    };
}