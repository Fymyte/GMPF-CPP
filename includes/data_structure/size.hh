///
/// @author Pierrick Guillaume
/// @date 28/09/2020.
///

#pragma once

#include "misc/type.hh"

namespace GMPF {
  /**
   * @class Size
   * @brief Hold size information.
   *
   * This class implements multiples operators to ease manipulation
   * of size.
   */
  class Size {
  public:
    /// @name Ctor / Dtor.
    /// @{
    /**
     * @brief Create a new instance of size with width and height to 0.
     */
    Size();
    /**
     * @brief Create a new instance of size with width and height set to given
     * ones.
     * @param width The width.
     * @param height The height.
     */
    Size(int64 width, int64 height);
    virtual ~Size();
    /// @}

    /// @name Basic operations.
    /// @{
    /**
     * @brief Add \a other to \a this.
     * @param other The size to add.
     * @return This position with \a other added.
     */
    Size& add(const Size& other);
    /**
     * @brief Subtract \a other size to \a this.
     * @param other The size to subtract.
     * @return This size with \a other subtracted.
     */
    Size& sub(const Size& other);
    /// @}

    /// @name Operators.
    /// @{
    /**
     * @brief Create new size which is the addition of both \a this and
     * \a other.
     * @param other The size to add to \a this.
     * @return The newly created size.
     */
    Size operator+(const Size& other) const;
    /**
     * @brief Create new size which is the subtraction of both \a this and
     * \a other.
     * @param other The size to subtract to \a this.
     * @return The newly created size.
     */
    Size operator-(const Size& other) const;

    /**
     * @brief Add other size to this size.
     * @param other The size to add.
     * @return This size with other added.
     */
    Size& operator+=(const Size& other);
    /**
     * @brief Subtract \a other to \a this.
     * @param other The size to subtract.
     * @return \a This with \a other subtracted.
     */
    Size& operator-=(const Size& other);

    /**
     * @brief Create new size which is the invert of \a this.
     * @return The newly created size.
     */
    Size operator-() const;

    /**
     * @brief Compare \a this to \a other to check if width and height are
     * equals.
     * @param other The size to compare.
     * @return true if they are equals, false if not.
     */
    bool operator==(const Size& other) const;
    /**
     * @brief Compare \a this to \a other to check if width and height are
     * different.
     * @param other The size to compare.
     * @return true if they are different, false if not.
     */
    bool operator!=(const Size& other) const;
    /// @}

    /// @name Getters.
    /// @{
    /**
     * @brief Retrieve the width.
     * @return The width.
     */
    [[nodiscard]] int64 getWidth() const;
    /**
     * @brief Retrieve the height.
     * @return The height.
     */
    [[nodiscard]] int64 getHeight() const;
    /// @}

  private:
    int64 width_;
    int64 height_;
  };
}
