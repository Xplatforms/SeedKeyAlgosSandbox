#ifndef DAIMLERSTANDARDSECURITYALGO_H
#define DAIMLERSTANDARDSECURITYALGO_H

#include <QObject>
#include <QDebug>

#include <iostream>
#include <vector>
#include <memory>
#include <cstdint>
#include <optional>

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

// Assuming enums and classes that were mentioned in your Java code:
enum class VKeyGenResultEx {
    KGRE_Ok,
    KGRE_BufferToSmall,
    KGRE_UnspecifiedError,
    KGRE_SecurityLevelInvalid
};

// C++ equivalent of DaimlerStandardSecurityAlgo class
class DaimlerStandardSecurityAlgo : public QObject {
    Q_OBJECT
public:
    explicit DaimlerStandardSecurityAlgo(std::shared_ptr<IParameterProvider> paramProvider, QObject * parent = Q_NULLPTR);

    VKeyGenResultEx GenerateKey(const std::vector<uint8_t>& inputArray, int param,
                                const std::string& /* paramStr1 */, const std::string& /* paramStr2 */,
                                std::vector<uint8_t>& outputArray, Parameter<int>& paramOut) {
        if (inputArray.size() != 8) {
            return VKeyGenResultEx::KGRE_UnspecifiedError;
        }
        if (outputArray.size() != 4) {
            return VKeyGenResultEx::KGRE_BufferToSmall;
        }
        if (!this->InitializeParameters(param)) {
            return VKeyGenResultEx::KGRE_UnspecifiedError;
        }
        // Extract and mask bytes
        int i  = inputArray[0] & 0xFF;
        int j  = inputArray[1] & 0xFF;
        int k  = inputArray[2] & 0xFF;
        int m  = inputArray[3] & 0xFF;
        int n  = inputArray[4] & 0xFF;
        int i1 = inputArray[5] & 0xFF;
        int i2 = inputArray[6] & 0xFF;
        int i3 = inputArray[7] & 0xFF;

        // Initialize and calculate intermediate values
        uint64_t l1 = 0;
        uint64_t l2 = 0;
        uint64_t l3 = 0;
        uint64_t l4 = 0;
        uint64_t l5 = 0;
        constexpr uint64_t l6 = 1103515245ULL;
        constexpr uint64_t l7 = 12345ULL;

        // Calculate l4 and l5 using shifting and addition
        l4 = static_cast<uint64_t>(i);
        l4 = (l4 << 8) + j;
        l4 = (l4 << 8) + k;
        l4 = (l4 << 8) + m;

        l5 = static_cast<uint64_t>(n);
        l5 = (l5 << 8) + i1;
        l5 = (l5 << 8) + i2;
        l5 = (l5 << 8) + i3;

        // Calculate l1, l2, and l3
        l1 = l6 * l4 + l7;
        l2 = l6 * l5 + l7;
        l3 = l1 ^ l2 ^ mK;

        // Fill outputArray with the result bytes
        outputArray[0] = static_cast<uint8_t>((l3 >> 24) & 0xFF);
        outputArray[1] = static_cast<uint8_t>((l3 >> 16) & 0xFF);
        outputArray[2] = static_cast<uint8_t>((l3 >> 8) & 0xFF);
        outputArray[3] = static_cast<uint8_t>(l3 & 0xFF);

        // Update parameter with output size
        paramOut.data = 4;
        return VKeyGenResultEx::KGRE_Ok;
    }

private:
    std::shared_ptr<IParameterProvider> provider;
    uint64_t mK;
    std::vector<uint8_t> mKBytes;

    bool InitializeParameters(int param)
    {
        mKBytes.resize(4);
        if (!provider->GetByteArray("K", param, mKBytes)) {
            return false;
        }
        qDebug() << "mKBytes " << QString::number(mKBytes[0],16) << QString::number(mKBytes[1],16)
            << QString::number(mKBytes[2],16) << QString::number(mKBytes[3],16);
        mK = 0;
        // Perform the equivalent bitwise operations with masking
        mK += (static_cast<uint64_t>(mKBytes[0]) & 0xFF) << 24;
        mK += (static_cast<uint64_t>(mKBytes[1]) & 0xFF) << 16;
        mK += (static_cast<uint64_t>(mKBytes[2]) & 0xFF) << 8;
        mK += (static_cast<uint64_t>(mKBytes[3]) & 0xFF);

        qDebug() << __PRETTY_FUNCTION__ << " mK " << mK;
        return true;
    }
};

#endif // DAIMLERSTANDARDSECURITYALGO_H
