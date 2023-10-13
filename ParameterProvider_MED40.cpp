#include "ParameterProvider_MED40.h"


void ParameterProvider_MED40::initializeParameters() {
    this->ByteArrays["K"] = {
        {1, {-54, -30, -108, 26}},
        {5, {-18, -83, -121, 63}},
        {9, {-66, -109, -84, 45}}
    };
}

bool ParameterProvider_MED40::GetBool(const std::string& paramString, int paramInt, Parameter<bool>& paramParameter) {
    auto it = Booleans.find(paramString);
    if (it != Booleans.end()) {
        auto map = it->second;
        auto paramIt = map.find(paramInt);
        if (paramIt != map.end()) {
            paramParameter.data = paramIt->second;
            return true;
        }
    }
    return false;
}

bool ParameterProvider_MED40::GetBoolArray(const std::string& paramString, int paramInt, std::vector<bool>& paramArrayOfBoolean) {
    auto it = BooleanArrays.find(paramString);
    if (it != BooleanArrays.end()) {
        auto map = it->second;
        auto paramIt = map.find(paramInt);
        if (paramIt != map.end()) {
            auto &srcArray = paramIt->second;
            if (paramArrayOfBoolean.size() == srcArray.size()) {
                std::copy(srcArray.begin(), srcArray.end(), paramArrayOfBoolean.begin());
                return true;
            }
        }
    }
    return false;
}

bool ParameterProvider_MED40::GetInt(const std::string& paramString, int paramInt, Parameter<int>& paramParameter) {
    auto it = Integers.find(paramString);
    if (it != Integers.end()) {
        auto map = it->second;
        auto paramIt = map.find(paramInt);
        if (paramIt != map.end()) {
            paramParameter.data = paramIt->second;
            return true;
        }
    }
    return false;
}
