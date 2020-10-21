///
/// @file tool.hh
/// @author Pierrick Guillaume
/// @date 19/10/2020.
///

#pragma once

#include <string>

#include "data_structures/position.hh"
#include "misc/singleton.hh"

namespace GMPF::Tool {
  /**
   * @class AbstractTool
   * @brief Represent an abstract tool.
   */
  class AbstractTool {
  public:
    /// @name Dtor.
    /// @{
    virtual ~AbstractTool();
    /// @}

    /**
     * @brief Use the tool. Each tool implementation should override this method
     * to take effect. Implementation may need more arguments, which should be
     * provided using setters.
     * @return true if the usage took place, false otherwise.
     */
    virtual bool use() = 0;

  protected:
    Position position_;

  protected:
    explicit AbstractTool(const std::string& name);
  };
}  // namespace GMPF
