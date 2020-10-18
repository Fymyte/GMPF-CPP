///
/// @author Pierrick Guillaume
/// @date 27/09/2020.
///

#pragma once

#include "misc/type.hh"

namespace GMPF {
  /**
   * @class Position
   * @brief Hold coordinates on an image based on pixels.
   *
   * This class implements multiples operators to ease manipulation
   * of coordinates.
   */
  class Position {
  public:
    /// @name Ctor / Dtor.
    /// @{
    /**
     * @brief Create a new instance of position with x and y coordinates
     * to 0.
     */
    Position();
    /**
     * @brief Create a new instance of position with x and y set to given
     * ones.
     * @param x The abscissa coordinate.
     * @param y The ordinate coordinate.
     */
    Position(int64 x, int64 y);
    virtual ~Position();
    /// @}

    /// @name Basic operations.
    /// @{
    /**
     * @brief Add \a other position to \a this.
     * @param other The position to add.
     * @return This position with \a other added.
     */
    Position& add(const Position& other);
    /**
     * @brief Subtract \a other position to \a this.
     * @param other The position to subtract.
     * @return This position with \a other subtracted.
     */
    Position& sub(const Position& other);
    /// @}

    /// @name Operators.
    /// @{
    /**
     * @brief Create new Position which is the addition of both \a this and
     * \a other.
     * @param other The position to add to \a this.
     * @return The newly created position.
     */
    Position operator+(const Position& other) const;
    /**
     * @brief Create new Position which is the subtraction of both \a this and
     * \a other.
     * @param other The position to subtract to \a this.
     * @return The newly created position.
     */
    Position operator-(const Position& other) const;

    /**
     * @brief Add \a other position to \a this.
     * @param other The position to add.
     * @return This position with \a other added.
     */
    Position& operator+=(const Position& other);
    /**
     * @brief Subtract \a other position to \a this.
     * @param other The position to subtract.
     * @return This position with \a other subtracted.
     */
    Position& operator-=(const Position& other);

    /**
     * @brief Create new position which is the invert of \a this.
     * @return The newly created position.
     */
    Position operator-() const;

    /**
     * @brief Compare \a this to \a other to check if abscissa and
     * ordinate are equals.
     * @param other The position to compare.
     * @return true if they are equals, false if not.
     */
    bool operator==(const Position& other) const;
    /**
     * @brief Compare \a this to \a other to check if abscissa or ordinate
     * are different.
     * @param other The position to compare.
     * @return true if they are different, false if not.
     */
    bool operator!=(const Position& other) const;
    /// @}

    /// @name Getters.
    /// @{
    /**
     * @brief Retrieve the abscissa.
     * @return The abscissa.
     */
    [[nodiscard]] int64 getX() const;
    /**
     * @brief Retrieve the ordinate.
     * @return The ordinate.
     */
    [[nodiscard]] int64 getY() const;
    /// @}

  private:
    int64  x_;
    int64  y_;
  };
}
