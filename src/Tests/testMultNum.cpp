#include "test.h"

TEST(Multiply, numSimpleTest) {
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
  A.MulNumber(2.0);
  must(0, 0) = 2 * 2;
  must(0, 1) = 5 * 2;
  must(0, 2) = 7 * 2;
  must(1, 0) = 6 * 2;
  must(1, 1) = 3 * 2;
  must(1, 2) = 4 * 2;
  must(2, 0) = 5 * 2;
  must(2, 1) = -2 * 2;
  must(2, 2) = -3 * 2;
  EXPECT_TRUE(A.EqMatrix(must));
}

TEST(Multiply, numSingleTest) {
  S21Matrix A(1, 1), must(1, 1);
  A(0, 0) = 45.98;
  A.MulNumber(3.0);
  must(0, 0) = 45.98 * 3;
  EXPECT_TRUE(A.EqMatrix(must));
}
