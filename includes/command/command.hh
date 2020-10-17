///
/// @file command.hh
/// @author Pierrick Guillaume
/// @date 08/10/2020.
///

#pragma once

namespace GMPF {
  /**
   * @class Command
   * @brief An interface for the command design pattern.
   *
   * This \a Command class is used to implement an undo / redo system
   * based on the command design pattern.
   */
  class Command {
  public:
    /// @name Ctor / Dtor.
    /// @{
    virtual ~Command() = 0;
    /// @}

    /// @name Actions.
    /// @{
    /** Execute the action of the command. */
    virtual void execute() = 0;
    /** Undo the action. */
    virtual void undo() = 0;
    /** Redo the action. */
    virtual void redo() = 0;
    /// @}
  };
}
