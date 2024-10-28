// PowertrainSecurityAlgo.cpp

#include "PowertrainSecurityAlgo.h"

PowertrainSecurityAlgo::PowertrainSecurityAlgo(IParameterProvider* paramIParameterProvider)
    : provider(paramIParameterProvider) {
    provider->initializeParameters();
}

VKeyGenResultEx PowertrainSecurityAlgo::GenerateKey(const std::vector<uint8_t>& paramArrayOfByte1, int paramInt,
                                                    const std::string& paramString1, const std::string& paramString2,
                                                    std::vector<uint8_t>& paramArrayOfByte2, Parameter<int>& paramParameter) {
    if (paramArrayOfByte1.size() != 4) return VKeyGenResultEx::KGRE_UnspecifiedError;
    if (paramArrayOfByte2.size() != 4) return VKeyGenResultEx::KGRE_BufferToSmall;
    if (!InitializeParameters(paramInt)) return VKeyGenResultEx::KGRE_UnspecifiedError;
    InitializeXValueMatrix();

    std::array<int, 4> arrayOfInt = {
        paramArrayOfByte1[3] & 0xFF,
        paramArrayOfByte1[2] & 0xFF,
        paramArrayOfByte1[1] & 0xFF,
        paramArrayOfByte1[0] & 0xFF
    };

    int i = arrayOfInt[mi1] ^ arrayOfInt[mi2];
    int j = GetBitFromByte(arrayOfInt[mi3], mj1);
    int k = GetBitFromByte(arrayOfInt[mi4], mj2);
    int m = GetBitFromByte(i, mj3);
    int n = GetValueOfD(j, k, m);

    int i1 = 0;
    i1 = SetByteInInt(i1, arrayOfInt[0], 0);
    i1 = SetByteInInt(i1, arrayOfInt[1], 1);
    i1 = SetByteInInt(i1, arrayOfInt[2], 2);
    i1 = SetByteInInt(i1, arrayOfInt[3], 3);

    int i2 = i1 ^ n;
    int i3 = GetBitFromByte(arrayOfInt[mi5], mj4);
    int i4 = GetBitFromByte(i, mj5);
    int i5 = GetBitFromByte(GetByteFromInt(i2, mi6), mj6);
    int i6 = GetValueOfG(i3, i4, i5);
    int i7 = i2 ^ i6;

    paramArrayOfByte2[0] = static_cast<uint8_t>((i7 & 0xFF000000) >> 24);
    paramArrayOfByte2[1] = static_cast<uint8_t>((i7 & 0xFF0000) >> 16);
    paramArrayOfByte2[2] = static_cast<uint8_t>((i7 & 0xFF00) >> 8);
    paramArrayOfByte2[3] = static_cast<uint8_t>(i7 & 0xFF);

    paramParameter.data = 4;
    return VKeyGenResultEx::KGRE_Ok;
}

bool PowertrainSecurityAlgo::InitializeParameters(int paramInt) {
    if (!provider->GetInt("i1", paramInt, &mi1)) return false;
    if (!provider->GetInt("i2", paramInt, &mi2)) return false;
    if (!provider->GetInt("i3", paramInt, &mi3)) return false;
    if (!provider->GetInt("i4", paramInt, &mi4)) return false;
    if (!provider->GetInt("i5", paramInt, &mi5)) return false;
    if (!provider->GetInt("i6", paramInt, &mi6)) return false;
    if (!provider->GetInt("j1", paramInt, &mj1)) return false;
    if (!provider->GetInt("j2", paramInt, &mj2)) return false;
    if (!provider->GetInt("j3", paramInt, &mj3)) return false;
    if (!provider->GetInt("j4", paramInt, &mj4)) return false;
    if (!provider->GetInt("j5", paramInt, &mj5)) return false;
    if (!provider->GetInt("j6", paramInt, &mj6)) return false;

    if (!provider->GetByte("X00", paramInt, &mX00[0])) return false;
    if (!provider->GetByte("X01", paramInt, &mX00[1])) return false;
    if (!provider->GetByte("X02", paramInt, &mX00[2])) return false;
    if (!provider->GetByte("X03", paramInt, &mX00[3])) return false;

    if (!provider->GetByte("X10", paramInt, &mX10[0])) return false;
    if (!provider->GetByte("X11", paramInt, &mX10[1])) return false;
    if (!provider->GetByte("X12", paramInt, &mX10[2])) return false;
    if (!provider->GetByte("X13", paramInt, &mX10[3])) return false;

    if (!provider->GetByte("X20", paramInt, &mX20[0])) return false;
    if (!provider->GetByte("X21", paramInt, &mX20[1])) return false;
    if (!provider->GetByte("X22", paramInt, &mX20[2])) return false;
    if (!provider->GetByte("X23", paramInt, &mX20[3])) return false;

    if (!provider->GetByte("X30", paramInt, &mX30[0])) return false;
    if (!provider->GetByte("X31", paramInt, &mX30[1])) return false;
    if (!provider->GetByte("X32", paramInt, &mX30[2])) return false;
    if (!provider->GetByte("X33", paramInt, &mX30[3])) return false;

    if (!provider->GetByte("X40", paramInt, &mX40[0])) return false;
    if (!provider->GetByte("X41", paramInt, &mX40[1])) return false;
    if (!provider->GetByte("X42", paramInt, &mX40[2])) return false;
    if (!provider->GetByte("X43", paramInt, &mX40[3])) return false;

    if (!provider->GetByte("X50", paramInt, &mX50[0])) return false;
    if (!provider->GetByte("X51", paramInt, &mX50[1])) return false;
    if (!provider->GetByte("X52", paramInt, &mX50[2])) return false;
    if (!provider->GetByte("X53", paramInt, &mX50[3])) return false;

    if (!provider->GetByte("X60", paramInt, &mX60[0])) return false;
    if (!provider->GetByte("X61", paramInt, &mX60[1])) return false;
    if (!provider->GetByte("X62", paramInt, &mX60[2])) return false;
    if (!provider->GetByte("X63", paramInt, &mX60[3])) return false;

    if (!provider->GetByte("X70", paramInt, &mX70[0])) return false;
    if (!provider->GetByte("X71", paramInt, &mX70[1])) return false;
    if (!provider->GetByte("X72", paramInt, &mX70[2])) return false;
    if (!provider->GetByte("X73", paramInt, &mX70[3])) return false;

    return true;
}



void PowertrainSecurityAlgo::InitializeXValueMatrix() {
    for (int i = 0; i < 4; ++i) {
        mXValues[0][i] = mX00[i] & 0xFF;
        mXValues[1][i] = mX10[i] & 0xFF;
        mXValues[2][i] = mX20[i] & 0xFF;
        mXValues[3][i] = mX30[i] & 0xFF;
        mXValues[4][i] = mX40[i] & 0xFF;
        mXValues[5][i] = mX50[i] & 0xFF;
        mXValues[6][i] = mX60[i] & 0xFF;
        mXValues[7][i] = mX70[i] & 0xFF;
    }
}

int PowertrainSecurityAlgo::GetValueOfD(int paramInt1, int paramInt2, int paramInt3) {
    int j = 0;
    if (paramInt1 != 0) j = SetBitInByte(j, 2);
    if (paramInt2 != 0) j = SetBitInByte(j, 1);
    if (paramInt3 != 0) j = SetBitInByte(j, 0);
    int i = 0;
    i = SetByteInInt(i, mXValues[j][3], 0);
    i = SetByteInInt(i, mXValues[j][2], 1);
    i = SetByteInInt(i, mXValues[j][1], 2);
    i = SetByteInInt(i, mXValues[j][0], 3);
    return i;
}

int PowertrainSecurityAlgo::GetValueOfG(int paramInt1, int paramInt2, int paramInt3) {
    int j = 0;
    if (paramInt1 != 0) j = SetBitInByte(j, 2);
    if (paramInt2 != 0) j = SetBitInByte(j, 1);
    if (paramInt3 != 0) j = SetBitInByte(j, 0);
    int i = 0;
    i = SetByteInInt(i, mXValues[j][2], 0);
    i = SetByteInInt(i, mXValues[j][1], 1);
    i = SetByteInInt(i, mXValues[j][0], 2);
    i = SetByteInInt(i, mXValues[j][3], 3);
    return i;
}

int PowertrainSecurityAlgo::GetBitFromByte(int paramInt1, int paramInt2) {
    if (paramInt2 > 7) return paramInt1;
    paramInt1 &= 0xFF;
    return (paramInt1 >> paramInt2) & 0x1;
}

int PowertrainSecurityAlgo::GetByteFromInt(int paramInt1, int paramInt2) {
    if (paramInt2 > 3) return paramInt1;
    return (paramInt1 >> (8 * paramInt2)) & 0xFF;
}

int PowertrainSecurityAlgo::SetBitInByte(int paramInt1, int paramInt2) {
    if (paramInt2 > 7) return paramInt1;
    return paramInt1 | (1 << paramInt2);
}

int PowertrainSecurityAlgo::SetByteInInt(int paramInt1, int paramInt2, int paramInt3) {
    if (paramInt3 > 3) return paramInt1;
    uint8_t arrayOfByte[4] = {
        static_cast<uint8_t>(paramInt1),
        static_cast<uint8_t>(paramInt1 >> 8),
        static_cast<uint8_t>(paramInt1 >> 16),
        static_cast<uint8_t>(paramInt1 >> 24)
    };
    arrayOfByte[paramInt3] = static_cast<uint8_t>(paramInt2);
    return (arrayOfByte[3] << 24) + ((arrayOfByte[2] & 0xFF) << 16) +
           ((arrayOfByte[1] & 0xFF) << 8) + (arrayOfByte[0] & 0xFF);
}
