// IParameterProvider.h

#pragma once
#include <string>
#include <vector>



class IParameterProvider {
public:
    virtual ~IParameterProvider() = default;

    virtual void initializeParameters() = 0;

    virtual bool GetBool(const std::string& paramString, int paramInt, bool* paramParameter) = 0;

    virtual bool GetBoolArray(const std::string& paramString, int paramInt, std::vector<bool>& paramArrayOfBoolean) = 0;

    virtual bool GetInt(const std::string& paramString, int paramInt, int* paramParameter) = 0;

    virtual bool GetIntArray(const std::string& paramString, int paramInt, std::vector<int>& paramArrayOfInteger) = 0;

    virtual bool GetShort(const std::string& paramString, int paramInt, short* paramParameter) = 0;

    virtual bool GetShortArray(const std::string& paramString, int paramInt, std::vector<short>& paramArrayOfShort) = 0;

    virtual bool GetLong(const std::string& paramString, int paramInt, int64_t* paramParameter) = 0;

    virtual bool GetLongArray(const std::string& paramString, int paramInt, std::vector<int64_t>& paramArrayOfLong) = 0;

    virtual bool GetFloat(const std::string& paramString, int paramInt, float* paramParameter) = 0;

    virtual bool GetFloatArray(const std::string& paramString, int paramInt, std::vector<float>& paramArrayOfFloat) = 0;

    virtual bool GetDouble(const std::string& paramString, int paramInt, double* paramParameter) = 0;

    virtual bool GetDoubleArray(const std::string& paramString, int paramInt, std::vector<double>& paramArrayOfDouble) = 0;

    virtual bool GetByte(const std::string& paramString, int paramInt, uint8_t* paramParameter) = 0;

    virtual bool GetByteArray(const std::string& paramString, int paramInt, std::vector<uint8_t>& paramArrayOfByte) = 0;
};

