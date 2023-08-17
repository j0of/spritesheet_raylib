#ifndef SPRITE_H
#define SPRITE_H

#include <raylib.h>

namespace spritesheet {
    class Sprite {
        public:
            Sprite(Texture2D &texture);
            Rectangle GetBounds();
            virtual void Update();
            void Draw();
        protected:
            Texture2D &texture;
            Rectangle srcRect;
            Rectangle dstRect;
            Vector2 origin;
            float rotation;
            Color tint;

            bool flipHorizontal;
            bool flipVertical;
    };
}

#endif