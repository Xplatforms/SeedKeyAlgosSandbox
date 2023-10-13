#include <map>
#include <vector>
#include <string>
#include "IParameterProvider.h"
#include "Parameter.h"


class ParameterProvider_MED40 : public IParameterProvider {
public:
    std::map<std::string, std::map<int, std::vector<int8_t>>> ByteArrays;
    std::map<std::string, std::map<int, bool>> Booleans;
    std::map<std::string, std::map<int, std::vector<bool>>> BooleanArrays;
    std::map<std::string, std::map<int, int>> Integers;

    void initializeParameters();

    bool GetBool(const std::string& paramString, int paramInt, Parameter<bool>& paramParameter);
    bool GetBoolArray(const std::string& paramString, int paramInt, std::vector<bool>& paramArrayOfBoolean);
    bool GetInt(const std::string& paramString, int paramInt, Parameter<int>& paramParameter);
    
};