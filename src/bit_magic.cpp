#include <algorithm>
#include <array>
#include <bit_magic/magic.hpp>
#include <bit_magic/print.hpp>
#include <bit_magic/util.hpp>
#include <private_include/util.hpp>

using namespace bit_magic::types;
using namespace bit_magic::util;
namespace bit_magic
{
  static inline std::array<size_t, 256>
  init_table()
  {
    std::array<size_t, 256> table{};

    for (size_t i{1}; i < 255; ++i)
    {
      table[i] = table[(i & (i - 1))] + 1;
    }

    return table;
  }

  size_t
  count_set_bits(const size_t n)
  {
    static const std::array<size_t, 256> table{init_table()};

    return table[(n & 255)] + table[((n >> 8) & 255)] +
           table[((n >> 16) & 255)] + table[(n >> 24)];
  }

  bool
  is_power_2(const size_t n, bool reveal_magic)
  {
    if (reveal_magic)
    {
      print::formatted_bit_operation(
          n,
          (n - 1),
          bit_operations::and_,
          "n",
          (std::to_string(n) + " - 1"),
          (std::to_string(n) + " & " + std::to_string((n - 1))),
          get_byte_size(n));
    }

    return (n && ((n & (n - 1)) == 0));
  }

  //ex case { 4, 4, 7, 4, 8, 7, 7, 7, 8 }
  size_t
  find_odd_occurrence(const std::vector<size_t>& arr, const bool reveal_magic)
  {
    size_t odd_occurence{};

    for (const size_t i : arr)
    {
      if (reveal_magic)
      {
        print::formatted_bit_operation(
            odd_occurence,
            i,
            types::bit_operations::exor,
            "odd_occurence",
            "i",
            (std::to_string(odd_occurence) + " ^ " + std::to_string(i)),
            get_byte_size(*std::max_element(arr.begin(), arr.end())));
      }

      odd_occurence ^= i;
    }

    return odd_occurence;
  }

  bool
  is_bit_set(const size_t n, size_t bit, const bool reveal_magic)
  {
    //Treat bit as an index into
    //n's binary reprsentation
    (bit == 0) ? bit : --bit;

    if (reveal_magic)
    {
      print::formatted_bit_operation(
          n,
          bit,
          types::bit_operations::shift_right,
          "n",
          "bit",
          (std::to_string(n) + " >> " + std::to_string(bit)),
          get_byte_size(std::max(n, bit)));

      print::formatted_bit_operation(
          util::do_bit_operation(n, bit, types::bit_operations::shift_right),
          bit,
          types::bit_operations::and_,
          "n",
          "bit",
          ("(" + std::to_string(n) + " >> " + std::to_string(bit) + ") & 1"),
          get_byte_size(std::max(n, bit)));
    }

    return (((n >> bit) & 1) != 0);
  }

  size_t
  first_set_bit(const size_t n, const bool reveal_magic)
  {
    //zero has no set bits
    if (n == 0)
    {
      return 0;
    }

    if (reveal_magic)
    {
      print::formatted_bit_operation(n,
                                     1,
                                     types::bit_operations::and_,
                                     "n",
                                     "1",
                                     (std::to_string(n) + " & 1"),
                                     get_byte_size(n));
    }

    //if n is odd, its first bit will always be set
    if ((n & 1) != 0)
    {
      return 1;
    }

    for (size_t i{1}; i <= n; ++i)
    {
      if (reveal_magic)
      {
        print::formatted_bit_operation(
            n,
            i,
            types::bit_operations::shift_right,
            "n",
            "i",
            (std::to_string(n) + " >> " + std::to_string(i)),
            get_byte_size(n));

        print::formatted_bit_operation(
            util::do_bit_operation(n, i, types::bit_operations::shift_right),
            1,
            types::bit_operations::and_,
            "n",
            "1",
            ("(" + std::to_string(n) + " >> " + std::to_string(i) + ") & 1"),
            get_byte_size(n));
      }

      if (((n >> i) & 1) != 0)
      {
        return i + 1;
      }
    }

    //return in all control paths
    return 0;
  }
} // namespace bit_magic
