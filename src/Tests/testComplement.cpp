#include "test.h"

TEST(Complement, simple_3_3) {
  S21Matrix A(3, 3);
  S21Matrix must(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 0;
  A(1, 1) = 4;
  A(1, 2) = 2;
  A(2, 0) = 5;
  A(2, 1) = 2;
  A(2, 2) = 1;

  auto B = A.CalcComplements();
  must(0, 0) = 0;
  must(0, 1) = 10;
  must(0, 2) = -20;
  must(1, 0) = 4;
  must(1, 1) = -14;
  must(1, 2) = 8;
  must(2, 0) = -8;
  must(2, 1) = -2;
  must(2, 2) = 4;

  EXPECT_TRUE(B.EqMatrix(must));
}

TEST(Complement, failSquare) {
  S21Matrix A(3, 4);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 0;
  A(1, 1) = 4;
  A(1, 2) = 2;
  A(2, 0) = 5;
  A(2, 1) = 2;
  A(2, 2) = 1;

  EXPECT_ANY_THROW(A.CalcComplements());
}

TEST(Complement, simple_2_2) {
  S21Matrix A(2, 2);
  S21Matrix must(2, 2);
  A(0, 0) = 6;
  A(0, 1) = 5;
  A(1, 0) = 3;
  A(1, 1) = 7;

  auto B = A.CalcComplements();
  must(0, 0) = 7;
  must(0, 1) = -3;
  must(1, 0) = -5;
  must(1, 1) = 6;
  EXPECT_TRUE(B.EqMatrix(must));
}
