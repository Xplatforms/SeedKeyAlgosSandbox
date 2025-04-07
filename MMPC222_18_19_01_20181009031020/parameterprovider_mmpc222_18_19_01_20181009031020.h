#ifndef PARAMETERPROVIDER_MMPC222_18_19__1_2_181__9_31_2__H
#define PARAMETERPROVIDER_MMPC222_18_19__1_2_181__9_31_2__H

#include <QObject>
#include <QDebug>

#include <iostream>
#include <vector>
#include <memory>
#include <cstdint>
#include <optional>

// Assuming enums and classes that were mentioned in your Java code:
enum class VKeyGenResultEx {
    KGRE_Ok,
    KGRE_BufferToSmall,
    KGRE_UnspecifiedError,
    KGRE_SecurityLevelInvalid
};

template<typename T>
struct Parameter {
    T data;

    // Default constructor
    Parameter() : data() {}

    // Parameterized constructor
    explicit Parameter(const T& value) : data(value) {}
};

// Forward declare the required interfaces/classes
class IParameterProvider:public QObject {
    Q_OBJECT
public:
    virtual void initializeParameters() = 0;
    //virtual bool GetByteArray(const std::string& key, int param, std::vector<uint8_t>& byteArray) = 0;
    virtual ~IParameterProvider() = default;

    virtual bool GetBool(const std::string& paramString, int paramInt, Parameter<bool>& paramParameter)  = 0;

    virtual bool GetBoolArray(const std::string& paramString, int paramInt, std::vector<bool>& paramArrayOfBoolean) = 0;

    virtual bool GetInt(const std::string& paramString, int paramInt, Parameter<int>& paramParameter) = 0;

    virtual bool GetIntArray(const std::string& paramString, int paramInt, std::vector<int>& paramArrayOfInteger) = 0;

    virtual bool GetShort(const std::string& paramString, int paramInt, Parameter<int16_t>& paramParameter) = 0;

    virtual bool GetShortArray(const std::string& paramString, int paramInt, std::vector<short>& paramArrayOfShort) = 0;

    virtual bool GetLong(const std::string& paramString, int paramInt, Parameter<int64_t>& paramParameter) = 0;

    virtual bool GetLongArray(const std::string& paramString, int paramInt, std::vector<int64_t>& paramArrayOfLong) = 0;

    virtual bool GetFloat(const std::string& paramString, int paramInt, Parameter<float>& paramParameter) = 0;

    virtual bool GetFloatArray(const std::string& paramString, int paramInt, std::vector<float>& paramArrayOfFloat) = 0;

    virtual bool GetDouble(const std::string& paramString, int paramInt, Parameter<double>& paramParameter) = 0;

    virtual bool GetDoubleArray(const std::string& paramString, int paramInt, std::vector<double>& paramArrayOfDouble) = 0;

    virtual bool GetByte(const std::string& paramString, int paramInt, Parameter<uint8_t>& paramParameter) = 0;

    virtual bool GetByteArray(const std::string& paramString, int paramInt, std::vector<uint8_t>& paramArrayOfByte) = 0;
};

class ParameterProvider_MMPC222_18_19_01_20181009031020 : public IParameterProvider
{
    Q_OBJECT
public:
    ParameterProvider_MMPC222_18_19_01_20181009031020();

    void initializeParameters() override {
        qDebug() << __PRETTY_FUNCTION__;

        // Byte array A
        std::unordered_map<int, std::vector<uint8_t>> mapA;
        std::vector<uint8_t> arrayA = {0x00, 0xAF, 0xFE, 0x00};
        mapA.emplace(1, std::move(arrayA));
        this->ByteArrays.emplace("A", std::move(mapA));

        // Byte array B
        std::unordered_map<int, std::vector<uint8_t>> mapB;
        std::vector<uint8_t> arrayB = {0x87, 0x65, 0x43, 0x21};
        mapB.emplace(1, std::move(arrayB));
        this->ByteArrays.emplace("B", std::move(mapB));

        // Byte array C
        std::unordered_map<int, std::vector<uint8_t>> mapC;
        std::vector<uint8_t> arrayC = {0x00, 0x00, 0xCA, 0xFE};
        mapC.emplace(1, std::move(arrayC));
        this->ByteArrays.emplace("C", std::move(mapC));
    }

    bool GetByteArray(const std::string& key, int param, std::vector<uint8_t>& byteArray) override {
        if (ByteArrays.find(key) != ByteArrays.end()) {
            auto& map = ByteArrays[key];
            if (map.find(param) != map.end()) {
                const auto& arr = map[param];
                if (byteArray.size() != arr.size()) return false;
                std::copy(arr.begin(), arr.end(), byteArray.begin());
                return true;
            }
        }
        return false;
    }

    template<typename T>
    bool GetValue(const std::unordered_map<std::string, std::unordered_map<int, T>>& container,
                  const std::string& key, int param, Parameter<T>& paramOut) {
        if (container.find(key) != container.end()) {
            const auto& innerMap = container.at(key);
            if (innerMap.find(param) != innerMap.end()) {
                paramOut.data = innerMap.at(param);
                return true;
            }
        }
        return false;
    }

    template<typename T>
    bool GetArray(const std::unordered_map<std::string, std::unordered_map<int, std::vector<T>>>& container,
                  const std::string& key, int param, std::vector<T>& arrayOut) {
        if (container.find(key) != container.end()) {
            const auto& innerMap = container.at(key);
            if (innerMap.find(param) != innerMap.end()) {
                const auto& storedArray = innerMap.at(param);
                if (arrayOut.size() != storedArray.size()) {
                    return false;
                }
                arrayOut = storedArray;
                return true;
            }
        }
        return false;
    }

    // Example of specific Get methods using the templates
    bool GetBool(const std::string& key, int param, Parameter<bool>& paramOut) override {
        return this->GetValue(this->Booleans, key, param, paramOut);
    }

    bool GetInt(const std::string& key, int param, Parameter<int>& paramOut) override {
        return this->GetValue(this->Integers, key, param, paramOut);
    }

    bool GetBoolArray(const std::string& key, int param, std::vector<bool>& arrayOut) override {
        return this->GetArray(this->BooleanArrays, key, param, arrayOut);
    }

    bool GetIntArray(const std::string& key, int param, std::vector<int>& arrayOut) override {
        return this->GetArray(this->IntegerArrays, key, param, arrayOut);
    }

    bool GetShort(const std::string& paramString, int paramInt, Parameter<int16_t>& paramParameter) override {return false;};
    bool GetShortArray(const std::string& paramString, int paramInt, std::vector<short>& paramArrayOfShort) override {return false;};
    bool GetLong(const std::string& paramString, int paramInt, Parameter<int64_t>& paramParameter) override {return false;};
    bool GetLongArray(const std::string& paramString, int paramInt, std::vector<int64_t>& paramArrayOfLong) override {return false;};
    bool GetFloat(const std::string& paramString, int paramInt, Parameter<float>& paramParameter) override {return false;};
    bool GetFloatArray(const std::string& paramString, int paramInt, std::vector<float>& paramArrayOfFloat) override {return false;};
    bool GetDouble(const std::string& paramString, int paramInt, Parameter<double>& paramParameter) override {return false;};
    bool GetDoubleArray(const std::string& paramString, int paramInt, std::vector<double>& paramArrayOfDouble) override {return false;};
    bool GetByte(const std::string& paramString, int paramInt, Parameter<uint8_t>& paramParameter) override {return false;};


private:

    std::unordered_map<std::string, std::unordered_map<int, bool>> Booleans;
    std::unordered_map<std::string, std::unordered_map<int, std::vector<bool>>> BooleanArrays;

    std::unordered_map<std::string, std::unordered_map<int, int>> Integers;
    std::unordered_map<std::string, std::unordered_map<int, std::vector<int>>> IntegerArrays;

    std::unordered_map<std::string, std::unordered_map<int, int16_t>> Shorts;
    std::unordered_map<std::string, std::unordered_map<int, std::vector<int16_t>>> ShortArrays;

    std::unordered_map<std::string, std::unordered_map<int, int64_t>> Longs;
    std::unordered_map<std::string, std::unordered_map<int, std::vector<int64_t>>> LongArrays;

    std::unordered_map<std::string, std::unordered_map<int, float>> Floats;
    std::unordered_map<std::string, std::unordered_map<int, std::vector<float>>> FloatArrays;

    std::unordered_map<std::string, std::unordered_map<int, double>> Doubles;
    std::unordered_map<std::string, std::unordered_map<int, std::vector<double>>> DoubleArrays;

    std::unordered_map<std::string, std::unordered_map<int, uint8_t>> Bytes;
    std::unordered_map<std::string, std::unordered_map<int, std::vector<uint8_t>>> ByteArrays;
};

#endif // PARAMETERPROVIDER_MMPC222_18_19__1_2_181__9_31_2__H
