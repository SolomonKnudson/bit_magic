#include <bit_magic/print.hpp>
#include <iostream>

using namespace bit_magic::types;
namespace bit_magic
{
  namespace print
  {
    void
    or_(const size_t x,
        const size_t y,
        const bool formatted,
        const Bytes binary_format)
    {
      (formatted ? formatted_bit_operation(
                       x,
                       y,
                       BitOperations::Or,
                       "Top Operand",
                       "Lower Operand",
                       (std::to_string(x) + " | " + std::to_string(y)),
                       binary_format)
                 : bit_operation(x, y, BitOperations::Or, binary_format));
    }

    void
    and_(const size_t x,
         const size_t y,
         const bool formatted,
         const Bytes binary_format)
    {
      (formatted ? formatted_bit_operation(
                       x,
                       y,
                       BitOperations::And,
                       "Top Operand",
                       "Lower Operand",
                       (std::to_string(x) + " & " + std::to_string(y)),
                       binary_format)
                 : bit_operation(x, y, BitOperations::And, binary_format));
    }

    void
    exor(const size_t x,
         const size_t y,
         const bool formatted,
         const Bytes binary_format)
    {
      (formatted ? formatted_bit_operation(
                       x,
                       y,
                       types::BitOperations::Exor,
                       "Top Operand",
                       "Lower Operand",
                       (std::to_string(x) + " ^ " + std::to_string(y)),
                       binary_format)
                 : bit_operation(x, y, BitOperations::Exor, binary_format));
    }

    //only print function that supports negative numbers
    void
    not_(const int64_t n)
    {
      std::cout << ((n >= 0) ? "~" : "~ ") << n << " = " << (~n) << '\n';
    }

    void
    shift_left(const size_t n,
               const size_t shift_by,
               const bool formatted,
               const Bytes binary_format)
    {
      (formatted ? formatted_bit_operation(
                       n,
                       shift_by,
                       types::BitOperations::LeftShift,
                       "n",
                       "shift_by",
                       (std::to_string(n) + " << " + std::to_string(shift_by)),
                       binary_format)
                 : bit_operation(
                       n, shift_by, BitOperations::LeftShift, binary_format));
    }

    void
    shift_right(const size_t n,
                const size_t shift_by,
                const bool formatted,
                const Bytes binary_format)
    {
      (formatted ? formatted_bit_operation(
                       n,
                       shift_by,
                       types::BitOperations::RightShift,
                       "n",
                       "shift_by",
                       (std::to_string(n) + " >> " + std::to_string(shift_by)),
                       binary_format)
                 : bit_operation(
                       n, shift_by, BitOperations::RightShift, binary_format));
    }
  } // namespace print
} // namespace bit_magic
