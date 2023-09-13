#include "test.h"

TEST(Sum, simple) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  S21Matrix must(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 0;
  A(1, 1) = 4;
  A(1, 2) = 5;
  A(2, 0) = 0;
  A(2, 1) = 0;
  A(2, 2) = 6;

  B(0, 0) = 1;
  B(0, 1) = 0;
  B(0, 2) = 0;
  B(1, 0) = 2;
  B(1, 1) = 0;
  B(1, 2) = 0;
  B(2, 0) = 3;
  B(2, 1) = 4;
  B(2, 2) = 1;

  A.SumMatrix(B);
  must(0, 0) = 2;
  must(0, 1) = 2;
  must(0, 2) = 3;
  must(1, 0) = 2;
  must(1, 1) = 4;
  must(1, 2) = 5;
  must(2, 0) = 3;
  must(2, 1) = 4;
  must(2, 2) = 7;

  EXPECT_TRUE(A.EqMatrix(must));
}

TEST(Sum, simpleSingleTest) {
  S21Matrix A(1, 1), B(1, 1), must(1, 1);
  A(0, 0) = 45.98;
  B(0, 0) = 67.9808;
  A.SumMatrix(B);
  must(0, 0) = 45.98 + 67.9808;
  EXPECT_TRUE(A.EqMatrix(must));
}

TEST(Sum, loopTest) {
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j < 20; j++) {
      S21Matrix m1(i, j), m2(j, i);
      if (i == j) {
        EXPECT_NO_THROW(m1.SumMatrix(m2));
      } else {
        EXPECT_ANY_THROW(m1.SumMatrix(m2));
      }
    }
  }
}
