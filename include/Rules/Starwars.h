#include <memory>
#include "Rules/IRule.h"
#include "IBasicBitboardCA.h"

class Starwars : public IRule
{
public:
    std::unique_ptr<BCA::IBasicBitboardCA> CreateCA()
    {
        std::unique_ptr<BCA::GenerationOuterTotalisticCA> dest(new BCA::GenerationOuterTotalisticCA(480, 400, 4));
        // FIXME: leaks memories
        InnerCAForStarwars * starwars = new InnerCAForStarwars(dest->GetSizeX(), dest->GetSizeY());
        dest->SetInnerCAInstance(starwars);

        dest->Randomize();
        return std::move(dest);
    }
    
    std::vector<Color> GetColorScheme()
    {
        std::vector<Color> dest
        {
            Color(0, 0, 0, 255), // space
            Color(127, 0, 0, 255), // 1
            Color(255, 0, 0, 255), // 2
            Color(255, 255, 0, 255), // 3
        };

        return std::move(dest);
    }
};
