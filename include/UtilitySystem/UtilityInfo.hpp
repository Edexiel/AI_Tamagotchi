#include "Curves.h"

#include <functional>

struct UtilityInfo
{
public:
    UtilityCurves::CurveSignature func = UtilityCurves::linear;
    float secondParam = 0.0f;
    float offset = 0.0f;
    bool oneMinus = false;

    float Evaluate(float t) const {
        float value = std::clamp(func(t - offset, secondParam), 0.f, 1.f);

        if (oneMinus)
            return 1 - value;
        return value;
    }
};