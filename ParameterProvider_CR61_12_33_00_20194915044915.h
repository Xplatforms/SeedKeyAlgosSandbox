#pragma once

#include <string>
#include <map>
#include <vector>
#include <cstdint>
#include "IParameterProvider.h"
#include "Parameter.h"

class ParameterProvider_CR61_12_33_00_20194915044915 : public IParameterProvider {
public:
    void initializeParameters() override;

    bool GetBool(const std::string& paramString, int paramInt, Parameter<bool>& paramParameter) override;
    bool GetBoolArray(const std::string& paramString, int paramInt, std::vector<bool>& paramArrayOfBoolean) override;
    bool GetInt(const std::string& paramString, int paramInt, int* paramParameter) override;
    bool GetIntArray(const std::string& paramString, int paramInt, std::vector<int>& paramArrayOfInteger) override;
    bool GetShort(const std::string& paramString, int paramInt, Parameter<int16_t>& paramParameter) override;
    bool GetShortArray(const std::string& paramString, int paramInt, std::vector<int16_t>& paramArrayOfShort) override;
    bool GetLong(const std::string& paramString, int paramInt, Parameter<int64_t>& paramParameter) override;
    bool GetLongArray(const std::string& paramString, int paramInt, std::vector<int64_t>& paramArrayOfLong) override;
    bool GetFloat(const std::string& paramString, int paramInt, Parameter<float>& paramParameter) override;
    bool GetFloatArray(const std::string& paramString, int paramInt, std::vector<float>& paramArrayOfFloat) override;
    bool GetDouble(const std::string& paramString, int paramInt, Parameter<double>& paramParameter) override;
    bool GetDoubleArray(const std::string& paramString, int paramInt, std::vector<double>& paramArrayOfDouble) override;
    bool GetByte(const std::string& paramString, int paramInt, Parameter<uint8_t>& paramParameter) override;
    bool GetByteArray(const std::string& paramString, int paramInt, std::vector<uint8_t>& paramArrayOfByte) override;

private:
    std::map<std::string, std::map<int, bool>> Booleans;
    std::map<std::string, std::map<int, std::vector<bool>>> BooleanArrays;
    std::map<std::string, std::map<int, int>> Integers;
    std::map<std::string, std::map<int, std::vector<int>>> IntegerArrays;
    std::map<std::string, std::map<int, int16_t>> Shorts;
    std::map<std::string, std::map<int, std::vector<int16_t>>> ShortArrays;
    std::map<std::string, std::map<int, int64_t>> Longs;
    std::map<std::string, std::map<int, std::vector<int64_t>>> LongArrays;
    std::map<std::string, std::map<int, float>> Floats;
    std::map<std::string, std::map<int, std::vector<float>>> FloatArrays;
    std::map<std::string, std::map<int, double>> Doubles;
    std::map<std::string, std::map<int, std::vector<double>>> DoubleArrays;
    std::map<std::string, std::map<int, uint8_t>> Bytes;
    std::map<std::string, std::map<int, std::vector<uint8_t>>> ByteArrays;
};
