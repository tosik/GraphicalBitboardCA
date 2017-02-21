#pragma once

#include <cstddef>
#include "GenerationOuterTotalisticCa.h"
#include "NeumannOuterTotalisticCa.h"

namespace BCA = BitboardCA;

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


class InnerWireworldCA
  : public BCA::OuterTotalisticCA
{
  public:
    InnerWireworldCA(std::size_t size_x, std::size_t size_y) : BCA::OuterTotalisticCA(size_x, size_y) {}
  protected:
    BCA::Bitboard Rule(
        BCA::Bitboard board,
        BCA::Bitboard s0, BCA::Bitboard s1, BCA::Bitboard s2,
        BCA::Bitboard s3, BCA::Bitboard s4, BCA::Bitboard s5,
        BCA::Bitboard s6, BCA::Bitboard s7, BCA::Bitboard s8 )
    {
      // 1 or 2
      return s1 | s2;
    }
};

class WireworldCA
  : public BCA::MultiStateOuterTotalisticCA
{
  InnerWireworldCA _ca;
  public:
    WireworldCA(std::size_t size_x, std::size_t size_y)
      : BCA::MultiStateOuterTotalisticCA(size_x, size_y, 4)
      , _ca(size_x, size_y)
    {
    }

    void Step()
    {
      unsigned int size_x = _ca.GetSizeX();
      unsigned int size_y = _ca.GetSizeY();

      // step(state 1) => _ca
      _ca.Copy(m_pWeakList[2]);
      _ca.Step();

      // _ca & state 1 => _ca
      _ca.And(m_pWeakList[1]);

      // state 1 - _ca => A
      BCA::LargeBitboard A(size_x, size_y);
      A.Copy(m_pWeakList[1]);
      A.Or(&_ca);
      A.Xor(&_ca);

      // A or state 3 => A
      A.Or(m_pWeakList[3]);

      // A -> state 1
      m_pWeakList[1]->Copy(&A);
      // state 2 -> state 3
      m_pWeakList[3]->Copy(m_pWeakList[2]);

      m_pWeakList[2]->Copy(&_ca);
    }

};
