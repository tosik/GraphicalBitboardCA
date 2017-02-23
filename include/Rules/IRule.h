#pragma once

#include <vector>
#include "IBasicBitboardCA.h"

class IRule
{
public:
    virtual std::vector<Color> GetColorScheme() = 0;
    virtual std::unique_ptr<BitboardCA::IBasicBitboardCA> CreateCA() = 0;
};
