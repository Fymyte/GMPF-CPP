///
/// @file tool_box.hh
/// @author Pierrick Guillaume
/// @date 19/10/2020.
///

#pragma once

#include "misc/singleton.hh"
#include "misc/type.hh"
#include "data_structures/position.hh"

namespace GMPF {
  class ToolBox: Singleton<ToolBox> {
  public:
  private:
    Position lastPosition_;
    Uint16 scaleFactor_;
    Tool selectedTool_;
  };
}  // namespace GMPF
