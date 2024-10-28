#ifndef PARAMETERPROVIDER_CR61_SEC_18_25_01_20182620112649_H
#define PARAMETERPROVIDER_CR61_SEC_18_25_01_20182620112649_H

#include <QObject>
#include <QDebug>

#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>
#include <string>
#include <optional>

#include "daimlerstandardsecurityalgo.h"

// Class representing ParameterProvider_CR61_sec_18_25_01_20182620112649
class ParameterProvider_CR61_sec_18_25_01_20182620112649 : public IParameterProvider {

public:
    ParameterProvider_CR61_sec_18_25_01_20182620112649(){};

    void initializeParameters() override {
        qDebug() << __PRETTY_FUNCTION__;

        std::unordered_map<int, std::vector<uint8_t>> byteArrayMap;
        std::vector<uint8_t> arrayOfByte = {0x78, 0xB9, 0xAC, 0x41};

        byteArrayMap.emplace(0x09, arrayOfByte);
        ByteArrays.emplace("K", std::move(byteArrayMap));
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




#endif // PARAMETERPROVIDER_CR61_SEC_18_25_01_20182620112649_H
