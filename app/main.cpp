#include <iostream>

#include <bit_magic/magic.hpp>
#include <bit_magic/print.hpp>

int
main()
{
  int64_t x{260};
  int64_t y{9000};

  bit_magic::types::Bytes bin_fmt{bit_magic::types::byte};
  bool format{true};

  bit_magic::types::bit_operations bit_op{
      bit_magic::types::bit_operations::exor};

  bit_magic::print::select_bit_operation(x, y, bit_op, true);

  return 0;
}

