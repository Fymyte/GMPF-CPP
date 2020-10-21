#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by Pierrick on 29/09/2020.
//

#include "data_structures/angle.hh"

#include <gtest/gtest.h>

class AngleTest : public ::testing::Test {
protected:
  GMPF::Angle angle1 = GMPF::Angle(350);
  GMPF::Angle angle2 = GMPF::Angle(10);
};

TEST_F(AngleTest, Create_with_default_contructor) {
  GMPF::Angle angle = GMPF::Angle();

  ASSERT_EQ(angle.getAngle(), 0);
}

TEST_F(AngleTest, Create_with_good_arguments) {
  GMPF::Angle angle = GMPF::Angle(128);

  ASSERT_EQ(angle.getAngle(), 128);
}

TEST_F(AngleTest, Copy_assignement_is_correct) {
  GMPF::Angle angle(angle1);

  ASSERT_EQ(angle.getAngle(), 350);
}

TEST_F(AngleTest, Addition_function_is_correct) {
  GMPF::Angle add = angle1.add(angle2);
  angle1 += angle2;

  ASSERT_EQ(add.getAngle(), 0);
  ASSERT_EQ(angle1.getAngle(), 10);
}

TEST_F(AngleTest, Addition_function_with_int_is_correct) {
  GMPF::Angle add = angle1.add(20);
  angle1 += 20;

  ASSERT_EQ(add.getAngle(), 10);
  ASSERT_EQ(angle1.getAngle(), 30);
}

TEST_F(AngleTest, Addition_between_2_Angle_is_correct) {
  GMPF::Angle add = angle1 + angle2;

  ASSERT_EQ(add.getAngle(), 0);
  ASSERT_EQ(angle1.getAngle(), 350);
}

TEST_F(AngleTest, Addition_between_Angle_and_int_is_correct) {
  GMPF::Angle add = angle1 + 20;

  ASSERT_EQ(add.getAngle(), 10);
  ASSERT_EQ(angle1.getAngle(), 350);
}

TEST_F(AngleTest, Subtraction_function_is_correct) {
  GMPF::Angle sub = angle1.sub(angle2);
  angle1 -= angle2;

  ASSERT_EQ(sub.getAngle(), 340);
  ASSERT_EQ(angle1.getAngle(), 330);
}

TEST_F(AngleTest, Subtraction_function_with_int_is_correct) {
  GMPF::Angle sub = angle1.sub(355);
  angle1 -= 355;

  ASSERT_EQ(sub.getAngle(), 355);
  ASSERT_EQ(angle1.getAngle(), 0);
}

TEST_F(AngleTest, Subtraction_between_2_Angle_is_correct) {
  GMPF::Angle sub = angle1 - angle2;

  ASSERT_EQ(sub.getAngle(), 340);
  ASSERT_EQ(angle1.getAngle(), 350);
}


TEST_F(AngleTest, Subtraction_between_Angle_and_int_is_correct) {
  GMPF::Angle sub = angle1 - 355;

  ASSERT_EQ(sub.getAngle(), 355);
  ASSERT_EQ(angle1.getAngle(), 350);
}

#pragma clang diagnostic pop
