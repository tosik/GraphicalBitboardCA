#pragma once

struct Color
{
  Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) :
    R(r), G(g), B(b), A(a) {}
  Uint8 R, G, B, A;
};
