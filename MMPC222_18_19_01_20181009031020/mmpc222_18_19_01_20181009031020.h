#ifndef MMPC222_18_19__1_2_181__9_31_2__H
#define MMPC222_18_19__1_2_181__9_31_2__H

#include <QObject>
#include <QQmlEngine>

#include "RVC222_MPC222_FCW246_LRR3.h"


class MMPC222_18_19_01_20181009031020 : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit MMPC222_18_19_01_20181009031020(QObject *parent = nullptr);

    std::vector<int> GetConfiguredAccessTypes() {
        return {1};
    }

    // GetSeedLength method
    int GetSeedLength(int accessType) {
        switch (accessType) {
        case 1:
            return 4;
        default:
            return -1;
        }
    }

    // GetKeyLength method
    int GetKeyLength(int accessType) {
        switch (accessType) {
        case 1:
            return 4;
        default:
            return -1;
        }
    }

    // GetECUName method
    std::string GetECUName() const {
        return "MMPC222";
    }

    // GenerateKey method
    VKeyGenResultEx GenerateKey(const std::vector<uint8_t>& inputBytes,
                                int paramInt,
                                const std::string& paramString1,
                                const std::string& paramString2,
                                std::vector<uint8_t>& outputBytes,
                                Parameter<int>& outLength)
    {
        std::unique_ptr<RVC222_MPC222_FCW246_LRR3> keygenModule = nullptr;

        switch (paramInt) {
        case 1:
            keygenModule = std::make_unique<RVC222_MPC222_FCW246_LRR3>(
                std::make_unique<ParameterProvider_MMPC222_18_19_01_20181009031020>());
            break;
        default:
            return VKeyGenResultEx::KGRE_SecurityLevelInvalid;
        }

        if (!keygenModule) {
            return VKeyGenResultEx::KGRE_SecurityLevelInvalid;
        }

        return keygenModule->GenerateKey(inputBytes, paramInt, paramString1, paramString2, outputBytes, outLength);
    }

};

#endif // MMPC222_18_19__1_2_181__9_31_2__H
