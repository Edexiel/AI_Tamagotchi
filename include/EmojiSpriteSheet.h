#pragma once

enum class Emoji : int
{
    _,
    alert,
    anger,
    bars,
    cash,
    circle,
    cloud,
    cross,
    dots1,
    dots2,
    dots3,
    drop,
    drops,
    exclamation,
    exclamations,
    faceAngry,
    faceHappy,
    faceSad,
    heart,
    heartBroken,
    hearts,
    idea,
    laugh,
    music,
    question,
    sleep,
    sleeps,
    star,
    stars,
    swirl,
    Size
};

static const char *emojiNames[(int) Emoji::Size] = {
        "_"
        "alert"
        "anger"
        "bars"
        "cash"
        "circle"
        "cloud"
        "cross"
        "dots1"
        "dots2"
        "dots3"
        "drop"
        "drops"
        "exclamation"
        "exclamations"
        "faceAngry"
        "faceHappy"
        "faceSad"
        "heart"
        "heartBroken"
        "hearts"
        "idea"
        "laugh"
        "music"
        "question"
        "sleep"
        "sleeps"
        "star"
        "stars"
        "swirl"
};

static const float emojiSpriteInfos[(int) Emoji::Size][4] = {
        {64,  152, 32, 38},
        {160, 114, 32, 38},
        {160, 76,  32, 38},
        {160, 38,  32, 38},
        {160, 0,   32, 38},
        {128, 152, 32, 38},
        {128, 114, 32, 38},
        {128, 76,  32, 38},
        {128, 38,  32, 38},
        {128, 0,   32, 38},
        {96,  152, 32, 38},
        {96,  114, 32, 38},
        {96,  76,  32, 38},
        {96,  38,  32, 38},
        {96,  0,   32, 38},
        {160, 152, 32, 38},
        {64,  114, 32, 38},
        {64,  76,  32, 38},
        {64,  38,  32, 38},
        {64,  0,   32, 38},
        {32,  152, 32, 38},
        {32,  114, 32, 38},
        {32,  76,  32, 38},
        {32,  38,  32, 38},
        {32,  0,   32, 38},
        {0,   152, 32, 38},
        {0,   114, 32, 38},
        {0,   76,  32, 38},
        {0,   38,  32, 38},
        {0,   0,   32, 38}
};

