#include "test.h"

TEST(Determinant, matrix_5_5) {
  S21Matrix A(5, 5);
  double res = 0.0;
  double must = 1116.0;
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(0, 3) = 3;
  A(0, 4) = 3;
  A(1, 0) = 8;
  A(1, 1) = 5;
  A(1, 2) = 1;
  A(1, 3) = 2;
  A(1, 4) = 2;
  A(2, 0) = 4;
  A(2, 1) = 5;
  A(2, 2) = 2;
  A(2, 3) = 9;
  A(2, 4) = 0;
  A(3, 0) = 4;
  A(3, 1) = 4;
  A(3, 2) = 0;
  A(3, 3) = 4;
  A(3, 4) = 1;
  A(4, 0) = 3;
  A(4, 1) = 3;
  A(4, 2) = 8;
  A(4, 3) = 1;
  A(4, 4) = 0;
  res = A.Determinant();
  EXPECT_NEAR(res, must, EPS_DOUBLE);
}

TEST(Determinant, matrix_1_1) {
  S21Matrix A(1, 1);
  double res = 0.0;
  double must = 9.0;
  A(0, 0) = 9;
  res = A.Determinant();
  EXPECT_NEAR(res, must, EPS_DOUBLE);
}

TEST(Determinant, wrongMatrixTest) {
  S21Matrix A(1, 2);
  A(0, 0) = 9;
  EXPECT_ANY_THROW(A.Determinant());
}
