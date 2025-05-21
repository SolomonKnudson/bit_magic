#ifndef BIT_MAGIC_TYPES_H
#define BIT_MAGIC_TYPES_H
#include <cmath>

namespace bit_magic
{
  namespace types
  {
    enum Bytes : size_t
    {
      byte = 8,
      byte_2 = 16,
      byte_4 = 32,
      byte_8 = 64,
    };

    enum class bit_operations
    {
      or_,
      and_,
      exor,
      shift_left,
      shift_right,
    };
  } // namespace types
} // namespace bit_magic
#endif
