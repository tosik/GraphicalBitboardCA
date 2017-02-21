#pragma once

#include <cstddef>
#include "GenerationOuterTotalisticCa.h"

namespace BCA = BitboardCA;

// your class
// define user rules on like this class.
class InnerCAForStarwars
  : public BCA::OuterTotalisticCA
{
  public:
    InnerCAForStarwars(std::size_t size_x, std::size_t size_y)
      : BCA::OuterTotalisticCA(size_x, size_y)
    {
    }

  protected:
    BCA::Bitboard Rule(
        BCA::Bitboard board,
        BCA::Bitboard s0, BCA::Bitboard s1, BCA::Bitboard s2,
        BCA::Bitboard s3, BCA::Bitboard s4, BCA::Bitboard s5,
        BCA::Bitboard s6, BCA::Bitboard s7, BCA::Bitboard s8 )
    {
      // starwars
      return ( board & ( s3 | s4 | s5 ) ) | ( ~board & s2 );
    }
};
