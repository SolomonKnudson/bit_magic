#include <bit_magic/magic.hpp>
#include <bit_magic/print.hpp>
#include <iostream>

namespace bit_magic
{
  namespace print
  {
    void
    total_set_bits(const size_t n)
    {
      std::cout << "# of set bits in " << n << ": "
                << bit_magic::count_set_bits(n) << '\n';
    }

    void
    is_power_2(const size_t n)
    {
      std::cout << n
                << (bit_magic::is_power_2(n, false)
                        ? " is a power of 2!\n"
                        : " is not a power of 2!\n");
    }

    void
    first_set_bit(const size_t n)
    {
      std::cout << n
                << "'s first set bit is: " << bit_magic::first_set_bit(n, false)
                << '\n';
    }

    void
    is_bit_set(const size_t n, const size_t bit)
    {
      std::cout << n << "'s " << bit
                << (bit_magic::is_bit_set(n, bit, false) ? " bit is set!\n"
                                                         : " is not set!\n");
    }
  } // namespace print
} // namespace bit_magic
