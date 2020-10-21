///
/// @file tool.cc
/// @author Pierrick Guillaume
/// @date 19/10/2020.
///

#include "data_structures/tools/abstract_tool.hh"

#include "data_structures/tools/tool_box.hh"

namespace GMPF::Tool {
  AbstractTool::AbstractTool(const std::string& name)
      : position_(Position()) {
    ToolBox::registerTool(name, this);
  }

  AbstractTool::~AbstractTool() = default;
}  // namespace GMPF
