#include "test.h"

TEST(Constructor, simple) {
  S21Matrix A;
  S21Matrix must;
  EXPECT_TRUE(A.EqMatrix(must));
}

TEST(Constructor, simpleAssign) {
  S21Matrix A;
  S21Matrix must;
  A(0, 1) = 4;
  A(1, 1) = 0;
  must(0, 1) = 4;
  must(0, 0) = 0;
  EXPECT_TRUE(A.EqMatrix(must));
}

TEST(Constructor, simpleBadIndexAssign) {
  S21Matrix A;
  S21Matrix must;
  EXPECT_ANY_THROW(A(0, 2) = 4);
  A(1, 1) = 0;
  must(0, 1) = 4;
  must(0, 0) = 0;
}

TEST(Constructor, indexBadIndex) { EXPECT_ANY_THROW(S21Matrix A(4, -1)); }
TEST(Constructor, indexBadIndex_2) { EXPECT_ANY_THROW(S21Matrix A(0, 0)); }

TEST(Constructor, copyMatrix) {
  S21Matrix copyFrom(3, 3);
  copyFrom(0, 0) = 1;
  copyFrom(0, 1) = 2;
  copyFrom(0, 2) = 3;
  copyFrom(1, 0) = 0;
  copyFrom(1, 1) = 4;
  copyFrom(1, 2) = 2;
  copyFrom(2, 0) = 5;
  copyFrom(2, 1) = 2;
  copyFrom(2, 2) = 1;
  S21Matrix A(copyFrom);
  EXPECT_TRUE(A == copyFrom);
}

TEST(Constructor, copyMatrix_2) {
  S21Matrix copyFrom;
  S21Matrix A(copyFrom);
  EXPECT_TRUE(A == copyFrom);
}

TEST(Constructor, swapMatrix) {
  S21Matrix swapFrom(3, 3);
  S21Matrix mustAfter(3, 3);
  swapFrom(0, 0) = 1;
  swapFrom(0, 1) = 2;
  swapFrom(0, 2) = 3;
  swapFrom(1, 0) = 0;
  swapFrom(1, 1) = 4;
  swapFrom(1, 2) = 2;
  swapFrom(2, 0) = 5;
  swapFrom(2, 1) = 2;
  swapFrom(2, 2) = 1;

  mustAfter(0, 0) = 1;
  mustAfter(0, 1) = 2;
  mustAfter(0, 2) = 3;
  mustAfter(1, 0) = 0;
  mustAfter(1, 1) = 4;
  mustAfter(1, 2) = 2;
  mustAfter(2, 0) = 5;
  mustAfter(2, 1) = 2;
  mustAfter(2, 2) = 1;
  S21Matrix A(std::move(swapFrom));
  EXPECT_TRUE(A == mustAfter);
  EXPECT_FALSE(A == swapFrom);
}

TEST(Constructor, print) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 0;
  A(1, 1) = 4;
  A(1, 2) = 2;
  A(2, 0) = 5;
  A(2, 1) = 2;
  A(2, 2) = 1;
  EXPECT_TRUE(A.PrintMatrix());
}
