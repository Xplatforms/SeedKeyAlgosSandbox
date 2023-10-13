#include <memory>

#include "ISeedKeyInterface.h"
#include "ISecurityAlgorithmInterface.h"
#include "DaimlerStandardSecurityAlgo.h"
#include "ParameterProvider_MED40.h"


class MED40 : public ISeedKey {
public:
    std::vector<int> GetConfiguredAccessTypes() override {
        return {1, 5, 9};
    }
    
    int GetSeedLength(int paramInteger) override {
        switch (paramInteger) {
            case 1:
            case 5:
            case 9:
                return 8;
            default:
                return -1;
        }
    }
    
    int GetKeyLength(int paramInteger) override {
        switch (paramInteger) {
            case 1:
            case 5:
            case 9:
                return 4;
            default:
                return -1;
        }
    }
    
    std::string GetECUName() override {
        return "MED40";
    }
    
    VKeyGenResultEx GenerateKey(const std::vector<uint8_t>& paramArrayOfByte1, int paramInt, const std::string& paramString1,
     const std::string& paramString2, std::vector<uint8_t>& paramArrayOfByte2, Parameter<int>& paramParameter) override {
        VKeyGenResultEx vKeyGenResultEx = VKeyGenResultEx::KGRE_UnspecifiedError;
        std::unique_ptr<IParameterProvider> paramIParameterProvider;
        
        switch (paramInt) {
            case 1:
            case 5:
            case 9:
                paramIParameterProvider = std::make_unique<ParameterProvider_MED40>();
                break;
            default:
                return VKeyGenResultEx::KGRE_SecurityLevelInvalid;
        }
        
        DaimlerStandardSecurityAlgo daimlerStandardSecurityAlgo(paramIParameterProvider.get());
        vKeyGenResultEx = daimlerStandardSecurityAlgo.GenerateKey(paramArrayOfByte1, paramInt, paramString1, paramString2, paramArrayOfByte2, paramParameter);
        return vKeyGenResultEx;
    }
};

