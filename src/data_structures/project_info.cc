///
/// @file project.cc
/// @author Pierrick Guillaume
/// @date 18/10/2020.
///

#include "data_structures/project_info.hh"

namespace GMPF {
  ProjectInfo::ProjectInfo(SingletonToken) {}

  const std::string& ProjectInfo::getFilename() { return instance().filename_; }
  const Size& ProjectInfo::getSize() { return instance().size_; }
  void ProjectInfo::setFilename(const std::string& filename) {
    instance().filename_ = filename;
  }
  void ProjectInfo::setSize(const Size& size) { instance().size_ = size; }
}
