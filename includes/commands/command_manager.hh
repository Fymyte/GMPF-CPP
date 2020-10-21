///
/// @file command_manager.hh
/// @author Pierrick Guillaume
/// @date 19/10/2020.
///

#pragma once

#include <stack>

#include "commands/command.hh"
#include "misc/singleton.hh"

namespace GMPF {
  /**
   * @brief Hold commands history and provide simple undo / redo interface.
   */
  class CommandManager: Singleton<CommandManager> {
  public:
    /**
     * @brief Singleton constructor.
     *
     * Cannot be called since we need an instance of
     * `Singleton<CommandManager>::SingletonToken`.
     * This constructor is used by the \b Singleton to instantiate the unique
     * Logger.
     */
    explicit CommandManager(SingletonToken);
    /**
     * @brief Add \a command to the undo stack.
     * @param command the \b Command to add to undo stack.
     */
    static void add(Command* command);
    /**
     * @brief Undo the last action, and put it in the redo stack.
     * @return true if it has undo a command, false if undo stack were empty.
     */
    static bool undo();
    /**
     * @brief Redo the undo last action, and put it in the undo stack.
     * @return true if it has redo a command, false if redo stack were empty.
     */
    static bool redo();
  private:
    std::stack<Command*> undoCommands;
    std::stack<Command*> redoCommands;
  };
}  // namespace GMPF
