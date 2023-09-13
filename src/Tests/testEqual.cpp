#include "test.h"

TEST(Equal, simpleTest) {
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

  must(0, 0) = 2;
  must(0, 1) = 5;
  must(0, 2) = 7;
  must(1, 0) = 6;
  must(1, 1) = 3;
  must(1, 2) = 4;
  must(2, 0) = 5;
  must(2, 1) = -2;
  must(2, 2) = -3;
  EXPECT_TRUE(A.EqMatrix(must));
}

TEST(Equal, simpleFalseTest) {
  S21Matrix A(3, 4), must(3, 3);
  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;

  must(0, 0) = 2;
  must(0, 1) = 5;
  must(0, 2) = 7;
  must(1, 0) = 6;
  must(1, 1) = 3;
  must(1, 2) = 4;
  must(2, 0) = 5;
  must(2, 1) = -2;
  must(2, 2) = -3;
  EXPECT_FALSE(A.EqMatrix(must));
}

TEST(Equal, simpleTest_2) {
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

  must(0, 0) = 2;
  must(0, 1) = 5;
  must(0, 2) = 7;
  must(1, 0) = 6;
  must(1, 1) = 3;
  must(1, 2) = 4;
  must(2, 0) = 5;
  must(2, 1) = -2;
  must(2, 2) = -3.000000034534;
  EXPECT_TRUE(A.EqMatrix(must));
}

TEST(Equal, simpleTest_3) {
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

  must(0, 0) = 2;
  must(0, 1) = 5;
  must(0, 2) = 7;
  must(1, 0) = 1;
  must(1, 1) = 3;
  must(1, 2) = 4;
  must(2, 0) = 5;
  must(2, 1) = -2;
  must(2, 2) = -3;
  EXPECT_FALSE(A.EqMatrix(must));
}
