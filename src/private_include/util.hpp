#ifndef BIT_PRIVATE_UTIL_H
#define BIT_PRIVATE_UTIL_H
#include <bit_magic/types.hpp>
#include <iostream>

namespace bit_magic
{
  namespace util
  {
    size_t
    do_bit_operation(size_t x, size_t y, types::BitOperations op);

    void
    dash_line(const types::Bytes size);

    bool
    is_valid_binary_format(size_t n, types::Bytes binary_format);
  } // namespace util
} // namespace bit_magic
#endif // BIT_PRIVATE_UTIL_H

