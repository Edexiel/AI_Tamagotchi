#include "Pet.h"
#include "AnimalSpriteSheet.h"
#include "EmojiSpriteSheet.h"

#include "UtilitySystem/Utilities/UtilityCleaning.hpp"
#include "UtilitySystem/Utilities/UtilityFeeding.hpp"
#include "UtilitySystem/Utilities/UtilityPlaying.hpp"
#include "UtilitySystem/Utilities/UtilitySleeping.hpp"

#include "PetStats.h"

void Pet::Draw(Texture &spriteSheet,Texture& emojisheet)
{

    // Player sprite
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

    // Emoji sprite
    Emoji emoji = GetSuggestedEmoji();
    int index = (int)emoji;
    Rectangle emojiInfo{emojiSpriteInfos[index][0],
                        emojiSpriteInfos[index][1],
                        emojiSpriteInfos[index][2],
                        emojiSpriteInfos[index][3]
    };

    DrawTextureRec(emojisheet,
                   emojiInfo,
                   Vector2{position.x -100.f,
                           position.y -100.f
                   },
                   WHITE);

}

Rectangle Pet::GetCollisionRect()
{
    return Rectangle{position.x - animalSpriteInfos[spriteSheetIndex][2] / 2,
                     position.y - animalSpriteInfos[spriteSheetIndex][3] / 2,
                     animalSpriteInfos[spriteSheetIndex][2],
                     animalSpriteInfos[spriteSheetIndex][3]
    };
}

Pet::Pet() : utilitySystem("PetUtilitySystem", 1.f)
{

    utilitySystem.SetDefaultAction(&actions.idle);
    utilitySystem.AddUtility<UtilityFeeding>("Feeding", &actions.eat);
    utilitySystem.AddUtility<UtilityCleaning>("Cleaning", &actions.clean);
    utilitySystem.AddUtility<UtilityPlaying>("Playing", &actions.play);
    utilitySystem.AddUtility<UtilitySleeping>("Sleeping", &actions.sleep);

    Blackboard &blackboard = utilitySystem.GetBlackboard();

    blackboard.SetValue(PET_SATIETY, 1);
    blackboard.SetValue(PET_CLEANLINESS, 1);
    blackboard.SetValue(PET_SADNESS, 1);
    blackboard.SetValue(PET_SLEEPINESS, 1);
}

void Pet::Update()
{
    needs.UpdateBlackBoard(utilitySystem.GetBlackboard());
}

std::string_view Pet::GetSuggestedAction()
{
    return utilitySystem.Evaluate()->GetName();
}

Emoji Pet::GetSuggestedEmoji()
{
    return utilitySystem.Evaluate()->GetEmoji();
}

ActionBase *Pet::GetAction()
{
    return utilitySystem.Evaluate();
}
