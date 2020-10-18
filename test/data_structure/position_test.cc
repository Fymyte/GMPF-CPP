#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by Pierrick on 25/09/2020.
//

#include "data_structure/position.hh"

#include <gtest/gtest.h>

class PositionTest : public ::testing::Test {
protected:
  GMPF::Position pos1 = GMPF::Position(1, 2);
  GMPF::Position pos2 = GMPF::Position(3, 4);
};

TEST_F(PositionTest, Create_with_good_arguments) {
  GMPF::Position pos1;

  ASSERT_EQ(pos1.getX(), 0);
  ASSERT_EQ(pos1.getY(), 0);

  GMPF::Position pos = GMPF::Position(1, 2);

  ASSERT_EQ(pos.getX(), 1);
  ASSERT_EQ(pos.getY(), 2);
}

TEST_F(PositionTest, Copy_assignement_is_correct) {
  GMPF::Position pos(pos1);

  ASSERT_EQ(pos.getX(), 1);
  ASSERT_EQ(pos.getY(), 2);
}

TEST_F(PositionTest, Addition_function_is_correct) {
  GMPF::Position add = pos1.add(pos2);
  pos1 += pos2;

  ASSERT_EQ(add.getX(), 4);
  ASSERT_EQ(add.getY(), 6);
  ASSERT_EQ(pos1.getX(), 7);
  ASSERT_EQ(pos1.getY(), 10);
}

TEST_F(PositionTest, Addition_between_2_Position_is_correct) {
  GMPF::Position add = pos1 + pos2;

  ASSERT_EQ(add.getX(), 4);
  ASSERT_EQ(add.getY(), 6);
  ASSERT_EQ(pos1.getX(), 1);
  ASSERT_EQ(pos1.getY(), 2);
}

TEST_F(PositionTest, Subtraction_function_is_correct) {
  GMPF::Position sub = pos1.sub(pos2);
  pos1 -= pos2;

  ASSERT_EQ(sub.getX(), -2);
  ASSERT_EQ(sub.getY(), -2);
  ASSERT_EQ(pos1.getX(), -5);
  ASSERT_EQ(pos1.getY(), -6);
}

TEST_F(PositionTest, Subtraction_between_2_Position_is_correct) {
  GMPF::Position sub = pos1 -pos2;

  ASSERT_EQ(sub.getX(), -2);
  ASSERT_EQ(sub.getY(), -2);
  ASSERT_EQ(pos1.getX(), 1);
  ASSERT_EQ(pos1.getY(), 2);
}

TEST_F(PositionTest, Unary_minus_correct) {
  GMPF::Position sub = -pos1;

  ASSERT_EQ(sub.getX(), -1);
  ASSERT_EQ(sub.getY(), -2);
  ASSERT_EQ(pos1.getX(), 1);
  ASSERT_EQ(pos1.getY(), 2);
}

TEST_F(PositionTest, Comparison_is_correct) {
  ASSERT_FALSE(pos1 == pos2);
  ASSERT_TRUE(pos1 != pos2);

  ASSERT_TRUE(pos1 == GMPF::Position(1, 2));
}


#pragma clang diagnostic pop