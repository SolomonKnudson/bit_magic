#include <bit_magic/util.hpp>
#include <private_include/util.hpp>
#include <string>

using namespace bit_magic::types;
namespace bit_magic
{
  namespace util
  {
    std::ostream&
    operator<<(std::ostream& os, const BitOperations op)
    {
      switch (op)
      {
        case BitOperations::Or:
          os << "|";
          break;

        case BitOperations::And:
          os << "&";
          break;

        case BitOperations::Exor:
          os << "^";
          break;

        case BitOperations::LeftShift:
          os << "<<";
          break;

        case BitOperations::RightShift:
          os << ">>";
          break;
      }

      return os;
    }

    size_t
    do_bit_operation(const size_t x, const size_t y, const BitOperations op)
    {
      size_t ret{};

      switch (op)
      {
        case BitOperations::Or:
          ret = x | y;
          break;

        case BitOperations::And:
          ret = x & y;
          break;

        case BitOperations::Exor:
          ret = x ^ y;
          break;

        case BitOperations::LeftShift:
          ret = x << y;
          break;

        case BitOperations::RightShift:
          ret = x >> y;
          break;
      }

      return ret;
    }

    void
    dash_line(const Bytes size)
    {
      for (size_t i{0}; i < (size + 2); ++i)
      {
        std::cout << "-";
      }
      std::cout << '\n';
    }

    size_t
    get_bit_size(size_t n)
    {
      if (n == 0)
      {
        return 1;
      }

      size_t bits{1};

      while ((n /= 2) != 0)
      {
        ++bits;
      }

      return bits;
    }

    Bytes
    get_byte_size(const size_t n)
    {
      //Number of bits to
      //represent n in binary
      size_t bit_size{(get_bit_size(n))};
      Bytes will_fit_in{};

      for (size_t i{8}; i <= Bytes::Byte_8; i *= 2)
      {
        //find the smallest byte
        //that can hold {bit_size}
        //amount of bits
        if ((will_fit_in = Bytes{static_cast<types::Bytes>(i)}) >= bit_size)
        {
          break;
        }
      }

      return will_fit_in;
    }

    bool
    is_valid_binary_format(size_t n, Bytes binary_format)
    {

      size_t byte_size{get_byte_size(n)};

      if (!(binary_format >= byte_size))
      {
        std::cerr << "Truncation detected: " + std::to_string(binary_format) +
                         " is not enough bits to display " + std::to_string(n) +
                         " in binary!";

        std::cerr << "\nDefaulting to: " + std::to_string(byte_size) +
                         " bits!\n";
        return false;
      }

      return true;
    }

  } // namespace util
} // namespace bit_magic
