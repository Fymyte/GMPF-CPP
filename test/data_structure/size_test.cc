#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by Pierrick on 29/09/2020.
//

#include "gtest/gtest.h"
#include <data_structure/size.hh>

class SizeTest : public ::testing::Test {
protected:
  GMPF::Size size1 = GMPF::Size(1, 2);
  GMPF::Size size2 = GMPF::Size(3, 4);
};

TEST_F(SizeTest, Create_with_good_arguments) {
  GMPF::Size pos1;

  ASSERT_EQ(pos1.getWidth(), 0);
  ASSERT_EQ(pos1.getHeight(), 0);

  GMPF::Size pos = GMPF::Size(1, 2);

  ASSERT_EQ(pos.getWidth(), 1);
  ASSERT_EQ(pos.getHeight(), 2);
}

TEST_F(SizeTest, Copy_assignement_is_correct) {
  GMPF::Size size(size1);

  ASSERT_EQ(size.getWidth(), 1);
  ASSERT_EQ(size.getHeight(), 2);
}

TEST_F(SizeTest, Addition_function_is_correct) {
  GMPF::Size add = size1.add(size2);
  size1 += size2;

  ASSERT_EQ(add.getWidth(), 4);
  ASSERT_EQ(add.getHeight(), 6);
  ASSERT_EQ(size1.getWidth(), 7);
  ASSERT_EQ(size1.getHeight(), 10);
}

TEST_F(SizeTest, Addition_between_2_Size_is_correct) {
  GMPF::Size add = size1 + size2;

  ASSERT_EQ(add.getWidth(), 4);
  ASSERT_EQ(add.getHeight(), 6);
  ASSERT_EQ(size1.getWidth(), 1);
  ASSERT_EQ(size1.getHeight(), 2);
}

TEST_F(SizeTest, Subtraction_function_is_correct) {
  GMPF::Size sub = size1.sub(size2);
  size1 -= size2;

  ASSERT_EQ(sub.getWidth(), -2);
  ASSERT_EQ(sub.getHeight(), -2);
  ASSERT_EQ(size1.getWidth(), -5);
  ASSERT_EQ(size1.getHeight(), -6);
}

TEST_F(SizeTest, Subtraction_between_2_Size_is_correct) {
  GMPF::Size sub = size1 - size2;

  ASSERT_EQ(sub.getWidth(), -2);
  ASSERT_EQ(sub.getHeight(), -2);
  ASSERT_EQ(size1.getWidth(), 1);
  ASSERT_EQ(size1.getHeight(), 2);
}

TEST_F(SizeTest, Unary_minus_correct) {
  GMPF::Size sub = -size1;

  ASSERT_EQ(sub.getWidth(), -1);
  ASSERT_EQ(sub.getHeight(), -2);
  ASSERT_EQ(size1.getWidth(), 1);
  ASSERT_EQ(size1.getHeight(), 2);
}

TEST_F(SizeTest, Comparison_is_correct) {
  ASSERT_FALSE(size1 == size2);
  ASSERT_TRUE(size1 != size2);

  ASSERT_TRUE(size1 == GMPF::Size(1, 2));
}

#pragma clang diagnostic pop