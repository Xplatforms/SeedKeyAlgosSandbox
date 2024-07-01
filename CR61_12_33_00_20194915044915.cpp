#include "CR61_12_33_00_20194915044915.h"
#include <memory>

std::vector<int> CR61_12_33_00_20194915044915::GetConfiguredAccessTypes() {
    return { 5, 9, 11 };
}

int CR61_12_33_00_20194915044915::GetSeedLength(int paramInt) {
    switch (paramInt) {
        case 5:
            return 4;
        case 9:
            return 8;
        case 11:
            return 4;
        default:
            return -1;
    }
}

int CR61_12_33_00_20194915044915::GetKeyLength(int paramInt) {
    switch (paramInt) {
        case 5:
        case 9:
        case 11:
            return 4;
        default:
            return -1;
    }
}

std::string CR61_12_33_00_20194915044915::GetECUName() {
    return "CR61";
}

VKeyGenResultEx CR61_12_33_00_20194915044915::GenerateKey(const std::vector<uint8_t>& paramArrayOfByte1, int paramInt, const std::string& paramString1, const std::string& paramString2, std::vector<uint8_t>& paramArrayOfByte2, Parameter<int>& paramParameter) 
{
    std::unique_ptr<ISecurityAlgorithm> securityAlgo;
    VKeyGenResultEx vKeyGenResultEx = VKeyGenResultEx::KGRE_UnspecifiedError;

    switch (paramInt) {
        case 5:
            securityAlgo = std::make_unique<PowertrainSecurityAlgo>(new ParameterProvider_CR61_12_33_00_20194915044915());
            break;
        case 9:
            securityAlgo = std::make_unique<DaimlerStandardSecurityAlgo>(new ParameterProvider_CR61_12_33_00_20194915044915());
            break;
        case 11:
            securityAlgo = std::make_unique<PowertrainSecurityAlgo>(new ParameterProvider_CR61_12_33_00_20194915044915());
            break;
        default:
            return VKeyGenResultEx::KGRE_SecurityLevelInvalid;
    }

    vKeyGenResultEx = securityAlgo->GenerateKey(paramArrayOfByte1, paramInt, paramString1, paramString2, paramArrayOfByte2, paramParameter);
    return vKeyGenResultEx;
}
