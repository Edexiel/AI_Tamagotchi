#include "Curves.h"

#include "raymath.h"
#include <cmath>

float UtilityCurves::step(float t, float secondParam) {
    return (t > 0.5) ? 1.0f : 0.0f;
}

float UtilityCurves::linear(float t, float secondParam) {
    return t;
}

float UtilityCurves::exponential(float t, float secondParam) {
    return pow(t, secondParam);
}

float UtilityCurves::sigmoid(float t, float secondParam) {
    return 1 / (1 + exp(secondParam * (t * 2 - 1)));
}
