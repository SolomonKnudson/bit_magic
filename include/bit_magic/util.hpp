#ifndef BIT_UTIL_H
#define BIT_UTIL_H
#include <bit_magic/types.hpp>
#include <iostream>

namespace bit_magic
{
  namespace util
  {
    types::Bytes
    get_byte_size(size_t n);

    std::ostream&
    operator<<(std::ostream& os, types::bit_operations op);
  } // namespace util
} // namespace bit_magic
#endif // !BIT_UTIL_H
