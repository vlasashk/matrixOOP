#include "test.h"

TEST(Overload, equalSimpleTest) {
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
  EXPECT_TRUE(A == must);
}

TEST(Overload, equalSimpleFalseTest) {
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
  EXPECT_FALSE(A == must);
}

TEST(Overload, equalSimpleTest_2) {
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
  EXPECT_TRUE(A == must);
}

TEST(Overload, equalSimpleTest_3) {
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
  EXPECT_FALSE(A == must);
}

TEST(Overload, mulMatrixSimpleTest) {
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
  A *= B;
  EXPECT_TRUE(A == must);
}

TEST(Overload, mulMatrixSimpleTest_2) {
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

  auto C = A * MUL;
  EXPECT_TRUE(C == must);
}

TEST(Overload, mulMatrixFalseSimpleTest) {
  S21Matrix A(3, 4), MUL(3, 3), must(3, 3);
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

  EXPECT_ANY_THROW(A = A * MUL);
}

TEST(Overload, mulMatrixSingleTest) {
  S21Matrix A(1, 1), B(1, 1), must(1, 1);
  A(0, 0) = 8;

  B(0, 0) = 1.33;

  must(0, 0) = 8 * 1.33;
  auto C = A * B;
  EXPECT_TRUE(C.EqMatrix(must));
}

TEST(Overload, wrongIndex) {
  S21Matrix A(1, 1);
  A(0, 0) = 8;
  EXPECT_ANY_THROW(A(0, 1) = 8);
}

TEST(Overload, wrongIndex_2) {
  S21Matrix A(1, 1);
  A(0, 0) = 8;
  EXPECT_ANY_THROW(A(-1, -1) = 8);
}

TEST(Overload, simpleSum) {
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

  A += B;
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

TEST(Overload, simpleSumSingleTest) {
  S21Matrix A(1, 1), B(1, 1), must(1, 1);
  A(0, 0) = 45.98;
  B(0, 0) = 67.9808;
  auto C = A + B;
  must(0, 0) = 45.98 + 67.9808;
  EXPECT_TRUE(C.EqMatrix(must));
}

TEST(Overload, simpleSub) {
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

  A -= B;
  must(0, 0) = 0;
  must(0, 1) = 2;
  must(0, 2) = 3;
  must(1, 0) = -2;
  must(1, 1) = 4;
  must(1, 2) = 5;
  must(2, 0) = -3;
  must(2, 1) = -4;
  must(2, 2) = 5;

  EXPECT_TRUE(A.EqMatrix(must));
}

TEST(Overload, simpleSubSingleTest) {
  S21Matrix A(1, 1), B(1, 1), must(1, 1);
  A(0, 0) = 45.98;
  B(0, 0) = 67.9808;
  auto C = A - B;
  must(0, 0) = 45.98 - 67.9808;
  EXPECT_TRUE(C.EqMatrix(must));
}

TEST(Overload, mulNumSimpleTest) {
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
  auto C = A * 2.0;
  must(0, 0) = 2 * 2;
  must(0, 1) = 5 * 2;
  must(0, 2) = 7 * 2;
  must(1, 0) = 6 * 2;
  must(1, 1) = 3 * 2;
  must(1, 2) = 4 * 2;
  must(2, 0) = 5 * 2;
  must(2, 1) = -2 * 2;
  must(2, 2) = -3 * 2;
  EXPECT_TRUE(C.EqMatrix(must));
}

TEST(Overload, mulNumSingleTest) {
  S21Matrix A(1, 1), must(1, 1);
  A(0, 0) = 45.98;
  A *= 3.0;
  must(0, 0) = 45.98 * 3;
  EXPECT_TRUE(A.EqMatrix(must));
}

TEST(Overload, equalCopyNewTest) {
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
  auto B = A;
  must(0, 0) = 2;
  must(0, 1) = 5;
  must(0, 2) = 7;
  must(1, 0) = 6;
  must(1, 1) = 3;
  must(1, 2) = 4;
  must(2, 0) = 5;
  must(2, 1) = -2;
  must(2, 2) = -3;
  EXPECT_TRUE(B == must);
}

TEST(Overload, equalCopyResizeLowerTest) {
  S21Matrix B(5, 5), A(3, 3), must(3, 3);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(0, 3) = 3;
  B(0, 4) = 3;
  B(1, 0) = 8;
  B(1, 1) = 5;
  B(1, 2) = 1;
  B(1, 3) = 2;
  B(1, 4) = 2;
  B(2, 0) = 4;
  B(2, 1) = 5;
  B(2, 2) = 2;
  B(2, 3) = 9;
  B(2, 4) = 0;
  B(3, 0) = 4;
  B(3, 1) = 4;
  B(3, 2) = 0;
  B(3, 3) = 4;
  B(3, 4) = 1;
  B(4, 0) = 3;
  B(4, 1) = 3;
  B(4, 2) = 8;
  B(4, 3) = 1;
  B(4, 4) = 0;

  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;

  B = A;
  must(0, 0) = 2;
  must(0, 1) = 5;
  must(0, 2) = 7;
  must(1, 0) = 6;
  must(1, 1) = 3;
  must(1, 2) = 4;
  must(2, 0) = 5;
  must(2, 1) = -2;
  must(2, 2) = -3;
  EXPECT_TRUE(B == must);
}

TEST(Overload, equalCopyResizeUpperTest) {
  S21Matrix A(5, 5), B(3, 3), must(5, 5);
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

  B(0, 0) = 2;
  B(0, 1) = 5;
  B(0, 2) = 7;
  B(1, 0) = 6;
  B(1, 1) = 3;
  B(1, 2) = 4;
  B(2, 0) = 5;
  B(2, 1) = -2;
  B(2, 2) = -3;

  B = A;

  must(0, 0) = 1;
  must(0, 1) = 2;
  must(0, 2) = 3;
  must(0, 3) = 3;
  must(0, 4) = 3;
  must(1, 0) = 8;
  must(1, 1) = 5;
  must(1, 2) = 1;
  must(1, 3) = 2;
  must(1, 4) = 2;
  must(2, 0) = 4;
  must(2, 1) = 5;
  must(2, 2) = 2;
  must(2, 3) = 9;
  must(2, 4) = 0;
  must(3, 0) = 4;
  must(3, 1) = 4;
  must(3, 2) = 0;
  must(3, 3) = 4;
  must(3, 4) = 1;
  must(4, 0) = 3;
  must(4, 1) = 3;
  must(4, 2) = 8;
  must(4, 3) = 1;
  must(4, 4) = 0;
  EXPECT_TRUE(B == must);
}
