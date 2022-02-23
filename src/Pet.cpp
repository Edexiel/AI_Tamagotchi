#include "Pet.h"
#include "AnimalSpriteSheet.h"

void Pet::Draw(Texture &spriteSheet) {
    Rectangle spriteInfo{animalSpriteInfos[spriteSheetIndex][0],
                         animalSpriteInfos[spriteSheetIndex][1],
                         animalSpriteInfos[spriteSheetIndex][2],
                         animalSpriteInfos[spriteSheetIndex][3]
    };

    DrawTextureRec(spriteSheet,
                   spriteInfo,
                   Vector2{position.x - spriteInfo.width / 2.0f,
                           position.y - spriteInfo.height / 2.0f
                   },
                   WHITE);
}

Rectangle Pet::GetCollisionRect() {
    return Rectangle{position.x - animalSpriteInfos[spriteSheetIndex][2] / 2,
                     position.y - animalSpriteInfos[spriteSheetIndex][3] / 2,
                     animalSpriteInfos[spriteSheetIndex][2],
                     animalSpriteInfos[spriteSheetIndex][3]
    };
}
