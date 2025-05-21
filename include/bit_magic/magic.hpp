#ifndef BIT_MAGIC_H
#define BIT_MAGIC_H
#include <cstddef>
#include <vector>

namespace bit_magic
{
  size_t
  count_set_bits(size_t n);

  size_t
  find_odd_occurrence(const std::vector<size_t>& arr,
                      bool reveal_magic = false);

  bool
  is_power_2(size_t n, bool reveal_magic = false);

  //Following functions do not
  //treat bits like an index
  //Ex. first bit = 1, second bit = 2
  size_t
  first_set_bit(size_t n, bool reveal_magic = false);

  bool
  is_bit_set(size_t n, size_t bit, bool reveal_magic = false);
} // namespace bit_magic
#endif // !BIT_MAGIC_H
