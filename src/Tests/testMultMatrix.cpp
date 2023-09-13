#include "test.h"

TEST(Multiply, matrixSimpleTest) {
  S21Matrix A(3, 2), B(2, 3), must(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 4;
  A(1, 0) = 2;
  A(1, 1) = 5;
  A(2, 0) = 3;
  A(2, 1) = 6;

  B(0, 0) = 1;
  B(0, 1) = -1;
  B(0, 2) = 1;
  B(1, 0) = 2;
  B(1, 1) = 3;
  B(1, 2) = 4;

  must(0, 0) = 9;
  must(0, 1) = 11;
  must(0, 2) = 17;
  must(1, 0) = 12;
  must(1, 1) = 13;
  must(1, 2) = 22;
  must(2, 0) = 15;
  must(2, 1) = 15;
  must(2, 2) = 27;
  A.MulMatrix(B);
  EXPECT_TRUE(A.EqMatrix(must));
}

TEST(Multiply, matrixSimpleTest_2) {
  S21Matrix A(3, 3), MUL(3, 3), must(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 4;
  A(0, 2) = 2;
  A(1, 0) = 5;
  A(1, 1) = 3;
  A(1, 2) = 6;
  A(2, 0) = 5;
  A(2, 1) = 3;
  A(2, 2) = 6;

  MUL(0, 0) = 1;
  MUL(0, 1) = -1;
  MUL(0, 2) = 1;
  MUL(1, 0) = 2;
  MUL(1, 1) = 3;
  MUL(1, 2) = 4;
  MUL(2, 0) = 2;
  MUL(2, 1) = 3;
  MUL(2, 2) = 4;

  must(0, 0) = 13;
  must(0, 1) = 17;
  must(0, 2) = 25;
  must(1, 0) = 23;
  must(1, 1) = 22;
  must(1, 2) = 41;
  must(2, 0) = 23;
  must(2, 1) = 22;
  must(2, 2) = 41;

  A.MulMatrix(MUL);
  EXPECT_TRUE(A.EqMatrix(must));
}

TEST(Multiply, matrixSingleTest) {
  S21Matrix A(1, 1), B(1, 1), must(1, 1);
  A(0, 0) = 8;

  B(0, 0) = 1.33;

  must(0, 0) = 8 * 1.33;
  A.MulMatrix(B);
  EXPECT_TRUE(A.EqMatrix(must));
}
