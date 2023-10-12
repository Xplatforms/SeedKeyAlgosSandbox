#include <string>
#include <vector>
#include "Parameter.h"
#include "ISecurityAlgorithmInterface.h"


class ISeedKey {
public:
    virtual std::vector<int> GetConfiguredAccessTypes() = 0;
    
    virtual int GetSeedLength(int paramInteger) = 0;
    
    virtual int GetKeyLength(int paramInteger) = 0;
    
    virtual std::string GetECUName() = 0;
    
    virtual VKeyGenResultEx GenerateKey(const std::vector<uint8_t>& paramArrayOfByte1, int paramInt, const std::string& paramString1, const std::string& paramString2, std::vector<uint8_t>& paramArrayOfByte2, Parameter<int>& paramParameter) = 0;

    virtual ~ISeedKey() = default;
};

