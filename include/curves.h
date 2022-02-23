#pragma once

namespace UtilityCurves
{
    // Every curves should have this signature, even if they don't use the second Parameters
    // This allow for simpler curves customization while preventing overengineering
    // secondParam may be unused
    typedef float (*CurveSignature)(float, float);

    float step(float t, float secondParam);
    float linear(float t, float secondParam);

    // if (a > 1), this is exponential
    // if (0 < a < 1), this is logarithmic
    float exponential(float t, float secondParam);

    // Apparently, if (x == 1), this is the logistic curve
    float sigmoid(float t, float secondParam);
}