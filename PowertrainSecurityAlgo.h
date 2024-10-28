// PowertrainSecurityAlgo.h

#pragma once

#include <array>

#include "ISecurityAlgorithmInterface.h"
#include "IParameterProvider.h"


class PowertrainSecurityAlgo : public ISecurityAlgorithm {

public:
    PowertrainSecurityAlgo(IParameterProvider* paramIParameterProvider);
    VKeyGenResultEx GenerateKey(const std::vector<uint8_t>& paramArrayOfByte1, int paramInt, const std::string& paramString1, const std::string& paramString2, std::vector<uint8_t>& paramArrayOfByte2, Parameter<int>& paramParameter) override;

private:
    IParameterProvider* provider;

    int mi1, mi2, mi3, mi4, mi5, mi6;
    int mj1, mj2, mj3, mj4, mj5, mj6;
    std::array<uint8_t, 4> mX00, mX01, mX02, mX03;
    std::array<uint8_t, 4> mX10, mX11, mX12, mX13;
    std::array<uint8_t, 4> mX20, mX21, mX22, mX23;
    std::array<uint8_t, 4> mX30, mX31, mX32, mX33;
    std::array<uint8_t, 4> mX40, mX41, mX42, mX43;
    std::array<uint8_t, 4> mX50, mX51, mX52, mX53;
    std::array<uint8_t, 4> mX60, mX61, mX62, mX63;
    std::array<uint8_t, 4> mX70, mX71, mX72, mX73;
    std::array<std::array<int, 4>, 8> mXValues;

    bool InitializeParameters(int paramInt);

    void InitializeXValueMatrix();

    int GetValueOfD(int paramInt1, int paramInt2, int paramInt3);
    int GetValueOfG(int paramInt1, int paramInt2, int paramInt3);

    int GetBitFromByte(int paramInt1, int paramInt2);

    int GetByteFromInt(int paramInt1, int paramInt2);

    int SetBitInByte(int paramInt1, int paramInt2);

    int SetByteInInt(int paramInt1, int paramInt2, int paramInt3);
};
