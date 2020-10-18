///
/// @file angle.hh
/// @author Pierrick Guillaume
/// @date 18/10/2020.
///

#pragma once

#include "misc/type.hh"

namespace GMPF {
  /**
   * @class Angle
   * @brief Hold an angle data.
   *
   * This class provide helpers function to manipulate angle.
   * An angle should always stay between 0 and 360, so basic operations take
   * this constrain into account and loop back to 0 (respectively 360) when
   * the addition (respectively subtraction) will go upper (respectively lower)
   * than 360 (respectively 0).
   */
  class Angle {
  public:
    /// @name Ctor / Dtor.
    /// @{
    /**
     * @brief Create an instance of \b Angle with angle set to given one.
     * @param angle The angle to set.
     */
    explicit Angle(Uint16 angle);
    virtual ~Angle();
    /// @}

    /// @name Basic operations.
    /// @{
    /**
     * @brief Add \a other to \a this.
     *
     * If overflow occur, then loop back to 0.
     * @param other The \a Angle to add.
     * @return \a This with \a other added.
     */
    Angle& add(const Angle& other);
    /**
     * @brief Add \a angle to \a this.
     *
     * If overflow occur, then loop back to 0.
     * @param angle The angle to add.
     * @return \a This with \a angle added.
     */
    Angle& add(Uint16 angle);
    /**
     * @brief Subtract \a other to \a this.
     * @param other The \b Angle to subtract.
     * @return \a This with \a other subtracted.
     */
    Angle& sub(const Angle& other);
    /**
     * @brief Subtract \a angle to \a this.
     * @param angle The angle to subtract.
     * @return \a This with \a angle subtracted.
     */
    Angle& sub(Uint16 angle);
    /// @}

    /// @name Operators.
    /// @{
    /**
     * @brief Create new \b Angle which is the addition of both \a this and
     * \a other.
     * @param other The \b Angle to add to \a this.
     * @return The newly created \b Angle.
     */
    Angle operator+(const Angle& other) const;
    /**
     * @brief Create new \b Angle which is \a this with \a angle added.
     * @param angle The angle to add.
     * @return The newly created \b Angle.
     */
    Angle operator+(Uint16 angle) const;
    /**
    * @brief Create new \b Angle which is the subtraction of both \a this and
    * \a other.
    * @param other The \b Angle to subtract to \a this.
    * @return The newly created \b Angle.
    */
    Angle operator-(const Angle& other) const;
    /**
    * @brief Create new \b Angle which is \a this with \a angle added.
    * @param angle The angle to subtract.
    * @return The newly created \b Angle.
    */
    Angle operator-(Uint16 angle) const;

    /**
     * @brief Add \a other to \a this.
     * @param other The \b Angle to add.
     * @return \a This with \a other added.
     */
    Angle& operator+=(const Angle& other);
    /**
     * @brief Add \a angle to \a this.
     * @param angle The angle to add.
     * @return \a This with \a other added.
     */
    Angle& operator+=(Uint16 angle);
    /**
     * @brief Subtract \a other to \a this.
     * @param other The \b Angle to subtract.
     * @return \a This with \a other subtracted.
     */
    Angle& operator-=(const Angle& other);
    /**
     * @brief Subtract \a angle to \a this.
     * @param other The angle to subtract.
     * @return \a This with \a angle subtracted.
     */
    Angle& operator-=(Uint16 angle);
    /// @}

    /// @name Getters.
    /// @{
    /**
     * @brief Retrieve the angle.
     * @return The angle
     */
    [[nodiscard]] Uint16 getAngle() const;
    /// @}

  private:
    Uint16 angle_;
  };
}
