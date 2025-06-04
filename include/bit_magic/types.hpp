#ifndef BIT_MAGIC_TYPES_H
#define BIT_MAGIC_TYPES_H
#include <cmath>

namespace bit_magic
{
  namespace types
  {
    enum Bytes : size_t
    {
      Byte = 8,
      Byte_2 = 16,
      Byte_4 = 32,
      Byte_8 = 64,
    };

    enum class BitOperations
    {
      Or,
      And,
      Exor,
      LeftShift,
      RightShift,
    };
  } // namespace types
} // namespace bit_magic
#endif
