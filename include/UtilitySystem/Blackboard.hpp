#pragma once

#include <string_view>
#include <unordered_map>
#include <functional>

class Blackboard
{
private:
    std::unordered_map<std::string_view, float> values;

public:
    void SetValue(std::string_view name, float value);

    float GetValue(std::string_view name);

    void DeleteValue(std::string_view name);

    bool HasValue(std::string_view name);

};

inline void Blackboard::SetValue(std::string_view name, float value)
{
    values[name] = std::clamp(value, 0.f, 1.f);
}

inline float Blackboard::GetValue(std::string_view name)
{
    if (values.find(name) == values.end())
        return 0.f;

    return values[name];
}

inline void Blackboard::DeleteValue(std::string_view name)
{
    values.erase(name);
}

inline bool Blackboard::HasValue(std::string_view name)
{
    return values.find(name) != values.end();
}
