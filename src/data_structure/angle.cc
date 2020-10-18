///
/// @file angle.cc
/// @author Pierrick Guillaume
/// @date 18/10/2020.
///

#include "data_structure/angle.hh"

namespace GMPF {
  Angle::Angle(Uint16 angle): angle_(angle) {}
  Angle::~Angle() = default;

  Angle& Angle::add(const Angle& other) {
    angle_ = (angle_ + other.angle_) % 360;
    return *this;
  }
  Angle& Angle::add(Uint16 angle) {
    angle_ = (angle_ + angle) % 360;
    return *this;
  }
  Angle& Angle::sub(const Angle& other) {
    angle_ = (angle_ + 360 - other.angle_) % 360;
    return *this;
  }
  Angle& Angle::sub(Uint16 angle) {
    angle_ = (angle_ + 360 - angle) % 360;
    return *this;
  }

  Angle Angle::operator+(const Angle& other) const {
    return Angle{ static_cast<Uint16>((angle_ + other.angle_) % Uint16(360)) };
  }
  Angle Angle::operator+(Uint16 angle) const {
    return Angle{ static_cast<Uint16>((angle_ + angle) % Uint16(360)) };
  }
  Angle Angle::operator-(const Angle& other) const {
    return Angle{ static_cast<Uint16>((angle_ + 360 - other.angle_) % Uint16(360)) };
  }
  Angle Angle::operator-(Uint16 angle) const {
    return Angle{ static_cast<Uint16>((angle_ + 360 - angle) % Uint16(360)) };
  }

  Angle& Angle::operator+=(const Angle& other) { return add(other); }
  Angle& Angle::operator+=(Uint16 angle) { return add(angle); }
  Angle& Angle::operator-=(const Angle& other) { return sub(other); }
  Angle& Angle::operator-=(Uint16 angle) { return sub(angle); }

  Uint16 Angle::getAngle() const { return angle_; }
}  // namespace GMPF
