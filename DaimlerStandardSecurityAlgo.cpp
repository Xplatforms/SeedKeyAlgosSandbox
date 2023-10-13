// DaimlerStandardSecurityAlgo.cpp

#include "DaimlerStandardSecurityAlgo.h"


DaimlerStandardSecurityAlgo::DaimlerStandardSecurityAlgo(IParameterProvider* paramIParameterProvider)
    : provider(paramIParameterProvider), mK(0) {
    provider->initializeParameters();
}

bool DaimlerStandardSecurityAlgo::InitializeParameters(int paramInt) {
    mKBytes.resize(4);
    if (!provider->GetByteArray("K", paramInt, mKBytes))
        return false;

    mK = 0;
    mK += static_cast<uint64_t>(mKBytes[0] & 0xFF) << 24;
    mK += static_cast<uint64_t>(mKBytes[1] & 0xFF) << 16;
    mK += static_cast<uint64_t>(mKBytes[2] & 0xFF) << 8;
    mK += static_cast<uint64_t>(mKBytes[3] & 0xFF);

    return true;
}

VKeyGenResultEx DaimlerStandardSecurityAlgo::GenerateKey(const std::vector<uint8_t>& paramArrayOfByte1, int paramInt, const std::string& paramString1, const std::string& paramString2, std::vector<uint8_t>& paramArrayOfByte2, Parameter<int>& paramParameter)
{
    if (paramArrayOfByte1.size() != 8)
        return VKeyGenResultEx::KGRE_UnspecifiedError;

    if (paramArrayOfByte2.size() != 4)
        return VKeyGenResultEx::KGRE_BufferToSmall;

    if (!InitializeParameters(paramInt))
        return VKeyGenResultEx::KGRE_UnspecifiedError;
        

    uint32_t i = paramArrayOfByte1[0] & 0xFF;
    uint32_t j = paramArrayOfByte1[1] & 0xFF;
    uint32_t k = paramArrayOfByte1[2] & 0xFF;
    uint32_t m = paramArrayOfByte1[3] & 0xFF;
    uint32_t n = paramArrayOfByte1[4] & 0xFF;
    uint32_t i1 = paramArrayOfByte1[5] & 0xFF;
    uint32_t i2 = paramArrayOfByte1[6] & 0xFF;
    uint32_t i3 = paramArrayOfByte1[7] & 0xFF;

    uint64_t l1 = 0, l2 = 0, l3 = 0, l4 = 0, l5 = 0;
    uint64_t l6 = 1103515245;
    uint64_t l7 = 12345;

    l4 = i;
    l4 <<= 8;
    l4 += j;
    l4 <<= 8;
    l4 += k;
    l4 <<= 8;
    l4 += m;

    l5 = n;
    l5 <<= 8;
    l5 += i1;
    l5 <<= 8;
    l5 += i2;
    l5 <<= 8;
    l5 += i3;

    l1 = l6 * l4 + l7;
    l2 = l6 * l5 + l7;
    l3 = l1 ^ l2 ^ mK;

    paramArrayOfByte2[0] = static_cast<uint8_t>((l3 & 0xFF000000) >> 24);
    paramArrayOfByte2[1] = static_cast<uint8_t>((l3 & 0x00FF0000) >> 16);
    paramArrayOfByte2[2] = static_cast<uint8_t>((l3 & 0x0000FF00) >> 8);
    paramArrayOfByte2[3] = static_cast<uint8_t>(l3 & 0x000000FF);

    paramParameter = Parameter<int>(4);

    return VKeyGenResultEx::KGRE_Ok;
}

