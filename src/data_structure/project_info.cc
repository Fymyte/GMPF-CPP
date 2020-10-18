///
/// @file project.cc
/// @author Pierrick Guillaume
/// @date 18/10/2020.
///

#include "data_structure/project_info.hh"

namespace GMPF {
  const std::string& ProjectInfo::getFilename() { return instance().filename; }
  const Size& ProjectInfo::getSize() { return instance().size; }
  void ProjectInfo::setFilename(const std::string& filename) {
    instance().filename = filename;
  }
  void ProjectInfo::setSize(const Size& size) { instance().size = size; }
}