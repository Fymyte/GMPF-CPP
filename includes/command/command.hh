//
// Created by Pierrick on 08/10/2020.
//

#pragma once

namespace GMFP {
  class Command {
  public:
    virtual ~Command() = 0;

    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual void redo() = 0;
  };
}
