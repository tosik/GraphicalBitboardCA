#include "Rules/IRule.h"
#include "IBasicBitboardCA.h"

class Wireworld : public IRule
{
public:
    std::unique_ptr<BCA::IBasicBitboardCA> CreateCA()
    {
        std::unique_ptr<BCA::IBasicBitboardCA> dest(new WireworldCA(480, 400));

        for (int x = 10; x < 50; x ++)
            dest->SetCellState(x, 90, 1);
        for (int y = 0; y < 500; y ++)
            dest->SetCellState(49, y, 1);
        dest->SetCellState(9, 90, 2);

        return std::move(dest);
    }
    
    std::vector<Color> GetColorScheme()
    {
        std::vector<Color> dest
        {
            Color(0, 0, 0, 255), // space
            Color(255, 255, 0, 255), // cable
            Color(0, 0, 255, 255), // electron head
            Color(255, 0, 0, 255), // electron tail
        };

        return std::move(dest);
    }
};
