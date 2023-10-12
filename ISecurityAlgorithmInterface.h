// ISecurityAlgorithm.h

#pragma once
#include <cstdint>
#include <vector>
#include <string>

#include "Parameter.h"

enum class VKeyGenResultEx {
        KGRE_Ok,
        KGRE_BufferToSmall,
        KGRE_SecurityLevelInvalid,
        KGRE_VariantInvalid,
        KGRE_UnspecifiedError
};

class ISecurityAlgorithm {
public:
    virtual VKeyGenResultEx GenerateKey(const std::vector<uint8_t>& paramArrayOfByte1, int paramInt, const std::string& paramString1, const std::string& paramString2, std::vector<uint8_t>& paramArrayOfByte2, Parameter<int>& paramParameter) = 0;
};

