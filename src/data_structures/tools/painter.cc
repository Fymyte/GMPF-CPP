///
/// @file painter.cc
/// @author Pierrick Guillaume
/// @date 20/10/2020.
///

#include "data_structures/tools/painter.hh"

namespace GMPF::Tool {
  Painter::Painter(): AbstractTool("Painter") {}

  bool Painter::use() { return false; }

  Painter Painter::painter;
}  // namespace GMPF
