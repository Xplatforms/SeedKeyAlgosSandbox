// DaimlerStandardSecurityAlgo.h

#pragma once
#include "ISecurityAlgorithmInterface.h"
#include "IParameterProvider.h"


class DaimlerStandardSecurityAlgo : public ISecurityAlgorithm {
public:
    DaimlerStandardSecurityAlgo(IParameterProvider* paramIParameterProvider);
    VKeyGenResultEx GenerateKey(const std::vector<uint8_t>& paramArrayOfByte1, int paramInt, const std::string& paramString1, const std::string& paramString2, std::vector<uint8_t>& paramArrayOfByte2, Parameter<int>& paramParameter) override;


private:
    bool InitializeParameters(int paramInt);

    IParameterProvider* provider;
    uint64_t mK;
    std::vector<uint8_t> mKBytes;
};