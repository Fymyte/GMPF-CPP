///
/// @file painter.hh
/// @author Pierrick Guillaume
/// @date 20/10/2020.
///

#pragma once

#include "data_structures/tools/abstract_tool.hh"
#include "misc/singleton.hh"

#include <string>

namespace GMPF::Tool {
  class Painter final: public AbstractTool {
  public:
    bool use() override;

  private:
    static Painter painter;
    Painter();
  };
}  // namespace GMPF
