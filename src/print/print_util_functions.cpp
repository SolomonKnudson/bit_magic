#include <bit_magic/print.hpp>
#include <bit_magic/util.hpp>
#include <private_include/util.hpp>

#include <bitset>

using namespace bit_magic::types;
using namespace bit_magic::util;
namespace bit_magic
{
  namespace print
  {
    void
    to_binary(const size_t n, const bool raw_binary, const Bytes binary_format)
    {
      if (!raw_binary)
      {
        std::cout << n << " in binary(" << binary_format << " bits): ";
      }

      switch (binary_format)
      {
        case Bytes::Byte:
          std::cout << std::bitset<Byte>{n};
          break;

        case Bytes::Byte_2:
          std::cout << std::bitset<Byte_2>{n};
          break;

        case Bytes::Byte_4:
          std::cout << std::bitset<Byte_4>{n};
          break;

        case Bytes::Byte_8:
          std::cout << std::bitset<Byte_8>{n};
          break;
      }
    }

    void
    bit_operation(const size_t x,
                  const size_t y,
                  const BitOperations op,
                  const Bytes binary_format)
    {
      std::cout << "  ";
      to_binary(x, true, binary_format);
      std::cout << '\n';

      std::cout << op << '\n';

      std::cout << "  ";
      to_binary(y, true, binary_format);
      std::cout << '\n';

      dash_line(binary_format);

      std::cout << "  ";
      to_binary(do_bit_operation(x, y, op), true, binary_format);
      std::cout << '\n';
    }

    void
    formatted_bit_operation(const size_t x,
                            const size_t y,
                            const types::BitOperations op,
                            const std::string& x_name,
                            const std::string& y_name,
                            const std::string& result_name,
                            types::Bytes binary_format)
    {
      size_t largest_number{
          std::max(std::max(x, y), do_bit_operation(x, y, op))};

      if (!is_valid_binary_format(largest_number, binary_format))
      {
        binary_format = get_byte_size(largest_number);
      }

      std::cout << '\n';
      bit_operation(x, y, op, binary_format);
      std::cout << '\n';

      std::cout << x_name << ": ";
      to_binary(x, false, binary_format);
      std::cout << "\n\n";

      std::cout << y_name << ": ";
      to_binary(y, false, binary_format);
      std::cout << "\n\n";

      std::cout << result_name << ": ";
      to_binary(do_bit_operation(x, y, op), false, binary_format);
      std::cout << "\n\n";
    }

    void
    select_bit_operation(const size_t x,
                         const size_t y,
                         const types::BitOperations op,
                         const bool formatted,
                         const Bytes binary_format)
    {
      switch (op)
      {
        case BitOperations::Or:
          or_(x, y, formatted, binary_format);
          break;

        case BitOperations::And:
          and_(x, y, formatted, binary_format);
          break;

        case BitOperations::Exor:
          exor(x, y, formatted, binary_format);
          break;

        case BitOperations::LeftShift:
          shift_left(x, y, formatted, binary_format);
          break;

        case BitOperations::RightShift:
          shift_right(x, y, formatted, binary_format);
          break;
      }
    }
  } // namespace print
} // namespace bit_magic
