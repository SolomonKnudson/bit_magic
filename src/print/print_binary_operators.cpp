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
                       bit_operations::or_,
                       "Top Operand",
                       "Lower Operand",
                       (std::to_string(x) + " | " + std::to_string(y)),
                       binary_format)
                 : bit_operation(x, y, bit_operations::or_, binary_format));
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
                       bit_operations::and_,
                       "Top Operand",
                       "Lower Operand",
                       (std::to_string(x) + " & " + std::to_string(y)),
                       binary_format)
                 : bit_operation(x, y, bit_operations::and_, binary_format));
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
                       types::bit_operations::exor,
                       "Top Operand",
                       "Lower Operand",
                       (std::to_string(x) + " ^ " + std::to_string(y)),
                       binary_format)
                 : bit_operation(x, y, bit_operations::exor, binary_format));
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
                       types::bit_operations::shift_left,
                       "n",
                       "shift_by",
                       (std::to_string(n) + " << " + std::to_string(shift_by)),
                       binary_format)
                 : bit_operation(
                       n, shift_by, bit_operations::shift_left, binary_format));
    }

    void
    shift_right(const size_t n,
                const size_t shift_by,
                const bool formatted,
                const Bytes binary_format)
    {
      (formatted
           ? formatted_bit_operation(
                 n,
                 shift_by,
                 types::bit_operations::shift_right,
                 "n",
                 "shift_by",
                 (std::to_string(n) + " >> " + std::to_string(shift_by)),
                 binary_format)
           : bit_operation(
                 n, shift_by, bit_operations::shift_right, binary_format));
    }
  } // namespace print
} // namespace bit_magic
