#include "test.h"

TEST(Transpose, simpleTest) {
  S21Matrix A(3, 3), must(3, 3);
  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;
  auto B = A.Transpose();
  must(0, 0) = 2;
  must(0, 1) = 6;
  must(0, 2) = 5;
  must(1, 0) = 5;
  must(1, 1) = 3;
  must(1, 2) = -2;
  must(2, 0) = 7;
  must(2, 1) = 4;
  must(2, 2) = -3;
  EXPECT_TRUE(B.EqMatrix(must));
}

TEST(Transpose, singleTest) {
  S21Matrix A(1, 1), must(1, 1);
  A(0, 0) = 2;
  auto B = A.Transpose();
  must(0, 0) = 2;
  EXPECT_TRUE(B.EqMatrix(must));
}
