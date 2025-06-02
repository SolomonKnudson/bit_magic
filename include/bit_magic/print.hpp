#ifndef BIT_PRINT_H
#define BIT_PRINT_H
#include <bit_magic/types.hpp>
#include <string>

namespace bit_magic
{
  //name clashes will happen if
  //print namespace is un-wrapped
  //eg. using namespace bit_magic::print
  //namespace used to bypass print_ prefix

  //Only not(n) accepts negative numbers
  namespace print
  {
    //std::bitset uses size_t to set the size
    //negative n will wrap
    void
    to_binary(size_t n,
              bool raw_binary,
              types::Bytes binary_format = types::Bytes::byte);

    void
    or_(size_t x,
        size_t y,
        bool formatted,
        types::Bytes binary_format = types::Bytes::byte);

    void
    and_(size_t x,
         size_t y,
         bool formatted,
         types::Bytes binary_format = types::Bytes::byte);

    void
    exor(size_t x,
         size_t y,
         bool formatted,
         types::Bytes binary_format = types::Bytes::byte);

    //Does not print binary
    //not(n) must be called by itself
    void
    not_(int64_t n);

    void
    shift_left(size_t n,
               size_t shift_by,
               bool formatted,
               types::Bytes binary_format = types::Bytes::byte);

    void
    shift_right(size_t n,
                size_t shift_by,
                bool formatted,
                types::Bytes binary_format = types::Bytes::byte);

    void
    total_set_bits(size_t n);

    void
    is_power_2(size_t n);

    //Following functions do not
    //treat bits like an index
    //Ex. first bit = 1, second bit = 2
    void
    first_set_bit(size_t n);

    void
    is_bit_set(size_t n, size_t bit);

    void
    bit_operation(size_t x,
                  size_t y,
                  types::BitOperations op,
                  types::Bytes binary_format = types::Bytes::byte);

    void
    formatted_bit_operation(size_t x,
                            size_t y,
                            types::BitOperations op,
                            const std::string& x_name,
                            const std::string& y_name,
                            const std::string& result_name,
                            types::Bytes binary_format = types::Bytes::byte);

    void
    select_bit_operation(size_t x,
                         size_t y,
                         types::BitOperations op,
                         bool formatted = false,
                         types::Bytes binary_format = types::Bytes::byte);
  } // namespace print
} // namespace bit_magic
#endif // !BIT_MAGIC_H
