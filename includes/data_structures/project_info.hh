///
/// @file project.hh
/// @author Pierrick Guillaume
/// @date 18/10/2020.
///

#pragma once

#include <string>

#include "misc/singleton.hh"
#include "data_structures/size.hh"

namespace GMPF {
  /**
   * @brief Hold project information.
   *
   * A project has a filename, which correspond to the file where the project
   * will be saved when the user ask for it. It also contain a size, which is
   * the size of the final image.
   */
  class ProjectInfo final: private Singleton<ProjectInfo> {
  public:
    /**
     * @brief Singleton constructor.
     *
     * Cannot be called since we need an instance of
     * `Singleton<ProjectInfo>::SingletonToken`.
     * This constructor is used by the \b Singleton to instantiate the unique
     * Logger.
     */
    explicit ProjectInfo(SingletonToken);
    /// @name Getters.
    /// @{
    /**
     * @brief Retrieve the filename where the project will be saved.
     * @return The filename of the project.
     */
    static const std::string& getFilename();
    /**
     * @brief Retrieve the size of the image the project is contained in.
     * @return The size of the project.
     */
    static const Size& getSize();
    /// @}

    /// @name Setters.
    /// @{
    /**
     * @brief Set the filename where the project will be saved.
     * @param filename The filename where the project will be saved after.
     */
    static void setFilename(const std::string& filename);
    /**
     * @brief Set the size of the image the project is contained in.
     * @param size The size the project will be contained in after.
     */
    static void setSize(const Size& size);
    /// @}

  private:
    std::string filename_;
    Size size_;
  };
}  // namespace GMPF
