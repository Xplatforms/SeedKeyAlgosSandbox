#pragma once

#include <string>
#include <array>
#include <memory>
#include "ISeedKeyInterface.h"
#include "ISecurityAlgorithmInterface.h"
#include "ParameterProvider_CR61_12_33_00_20194915044915.h"
#include "DaimlerStandardSecurityAlgo.h"
#include "PowertrainSecurityAlgo.h"

class CR61_12_33_00_20194915044915 : public ISeedKey {
public:
    std::vector<int> GetConfiguredAccessTypes() override;
    int GetSeedLength(int paramInt) override;
    int GetKeyLength(int paramInt) override;
    std::string GetECUName() override;
    VKeyGenResultEx GenerateKey(const std::vector<uint8_t>& paramArrayOfByte1, int paramInt, const std::string& paramString1, const std::string& paramString2, std::vector<uint8_t>& paramArrayOfByte2, Parameter<int>& paramParameter) override;
};
