///
/// @file tool_box.cc
/// @author Pierrick Guillaume
/// @date 19/10/2020.
///

#include "data_structures/tools/tool_box.hh"

#include "misc/logger.hh"

namespace GMPF {
  ToolBox::ToolBox()
      : availableTools_(std::unordered_map<std::string, Tool::AbstractTool*>())
      , selectedTool_(nullptr) {}

  void ToolBox::registerTool(const std::string& name,
                             Tool::AbstractTool* tool) {
    if (!instance().availableTools_.emplace(name, tool).second)
      throw std::runtime_error("Tool `" + name + "' already registered");
  }

  void ToolBox::selectTool(const std::string& name) {
    auto& availableTools = instance().availableTools_;

    auto tool = availableTools.find(name);
    if (tool == availableTools.end())
      throw std::runtime_error(name + ": no such tool available");

    instance().selectedTool_ = tool->second;
  }

  void ToolBox::use() { instance().selectedTool_->use(); }
}  // namespace GMPF
