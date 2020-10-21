///
/// @file tool_box.hh
/// @author Pierrick Guillaume
/// @date 19/10/2020.
///

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "data_structures/position.hh"
#include "data_structures/tools/abstract_tool.hh"
#include "misc/singleton.hh"
#include "misc/type.hh"

namespace GMPF {
  /**
   * @class ToolBox
   * @brief Register all implemented tools and make them available by providing
   * access to them by their defined names.
   */
  class ToolBox: Singleton<ToolBox> {
  public:
    /**
     * @brief Register a \b Tool and make it available to usage using the
     * provided name.
     *
     * This function may throw a `std::runtime_error` if a tool with the same
     * name has already been registered.
     * @param name The name which will then be used to access the \a tool.
     * @param tool The tool to register.
     */
    static void registerTool(const std::string& name, Tool::AbstractTool* tool);
    /**
     * @brief Mark the tool with corresponding \a name as selected for future
     * operations.
     * @param name
     */
    static void selectTool(const std::string& name);

    /**
     * @brief Use the selected tool
     */
    static void use();

  private:
    friend ToolBox& Singleton<ToolBox>::instance();
    ToolBox();

    std::unordered_map<std::string, Tool::AbstractTool*> availableTools_;
    Tool::AbstractTool* selectedTool_;
  };
}  // namespace GMPF
