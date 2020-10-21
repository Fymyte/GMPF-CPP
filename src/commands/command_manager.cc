///
/// @file command_manager.cc
/// @author Pierrick Guillaume
/// @date 19/10/2020.
///

#include "commands/command_manager.hh"

namespace GMPF {
  CommandManager::CommandManager(SingletonToken) {}

  void CommandManager::add(Command* command) {
    instance().undoCommands.push(command);
  }

  bool CommandManager::undo() {
    auto& manager = instance();
    if (manager.undoCommands.empty())
      return false;

    manager.undoCommands.top()->undo();
    manager.redoCommands.push(manager.undoCommands.top());
    manager.undoCommands.pop();
    return true;
  }

  bool CommandManager::redo() {
    auto& manager = instance();
    if (manager.redoCommands.empty())
      return false;

    manager.redoCommands.top()->redo();
    manager.undoCommands.push(manager.redoCommands.top());
    manager.redoCommands.pop();
    return true;
  }
}  // namespace GMPF
