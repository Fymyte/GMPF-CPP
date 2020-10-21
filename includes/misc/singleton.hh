///
/// @file singleton.hh
/// @author Pierrick Guillaume.
/// @date 06/10/2020.
///

#pragma once

/**
 * @brief An interface to implement singleton design pattern easily
 * @tparam T Type of the class that derived from singleton
 */
template<class T>
class Singleton {
public:
  /// @name Ctor.
  /// @{
  Singleton(Singleton const&) = delete;
  Singleton& operator=(Singleton const&) = delete;
  /// @}

  /**
   * Return a unique instance of the object
   * @return The unique instance of the implementing class
   */
  static T& instance() {
    static T instance_;
    return instance_;
  }

protected:
  Singleton() = default;
};
