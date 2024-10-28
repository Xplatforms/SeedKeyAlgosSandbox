#include "daimlerstandardsecurityalgo.h"

DaimlerStandardSecurityAlgo::DaimlerStandardSecurityAlgo(std::shared_ptr<IParameterProvider> paramProvider, QObject *parent)
    : QObject{parent}, mK(0)
{
    provider = paramProvider;
    provider->initializeParameters();

}
