#ifndef ICON_H
#define ICON_H

#include "Sprite.h"

namespace spritesheet {
    class Icon : public Sprite {
        public:
            Icon(Texture2D& texture);
            void Update() override;

        private:
            float speed;
            Vector2 direction;
    };
};

#endif