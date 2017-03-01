#include <vector>
#include "Position.h"

class Bresenham
{
public:
    static std::vector<Position> GetPoints(int x1, int y1, int const x2, int const y2);
};
