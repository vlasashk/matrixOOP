#include "test.h"

TEST(Inverse, simpleTest) {
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
  auto B = A.InverseMatrix();
  must(0, 0) = 1;
  must(0, 1) = -1;
  must(0, 2) = 1;
  must(1, 0) = -38;
  must(1, 1) = 41;
  must(1, 2) = -34;
  must(2, 0) = 27;
  must(2, 1) = -29;
  must(2, 2) = 24;
  EXPECT_TRUE(B.EqMatrix(must));
}

TEST(Inverse, failSquare) {
  S21Matrix A(3, 4);
  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;
  EXPECT_ANY_THROW(A.InverseMatrix());
}

TEST(Inverse, simpleFloatTest) {
  S21Matrix A(2, 2), must(2, 2);
  A(0, 0) = 5;
  A(0, 1) = 6;
  A(1, 0) = 5;
  A(1, 1) = 1;
  auto B = A.InverseMatrix();
  must(0, 0) = -0.04;
  must(0, 1) = 0.24;
  must(1, 0) = 0.2;
  must(1, 1) = -0.2;
  EXPECT_TRUE(B.EqMatrix(must));
}

TEST(Inverse, hardTest) {
  S21Matrix A(3, 3), must(3, 3);
  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(2, 0) = 5;
  A(2, 1) = -4;
  A(2, 2) = -3;
  auto B = A.InverseMatrix();
  must(0, 0) = -0.1014492754;
  must(0, 1) = 0.1884057971;
  must(0, 2) = 0.01449275362;
  must(1, 0) = -0.5507246377;
  must(1, 1) = 0.5942028986;
  must(1, 2) = -0.4927536232;
  must(2, 0) = 0.5652173913;
  must(2, 1) = -0.4782608696;
  must(2, 2) = 0.347826087;
  EXPECT_TRUE(B.EqMatrix(must));
}

TEST(Inverse, simpleSingleTest_1) {
  S21Matrix A(1, 1), must(1, 1);
  A(0, 0) = 8;
  auto B = A.InverseMatrix();
  must(0, 0) = 0.125;
  EXPECT_TRUE(B.EqMatrix(must));
}

TEST(Inverse, simpleSingleTest_2) {
  S21Matrix A(1, 1), must(1, 1);
  A(0, 0) = 19;
  auto B = A.InverseMatrix();
  must(0, 0) = 0.05263157895;
  EXPECT_TRUE(B.EqMatrix(must));
}

TEST(Inverse, zeroDetTest) {
  S21Matrix A(2, 2);
  A(0, 0) = 9;
  A(0, 1) = 9;
  A(1, 0) = 9;
  A(1, 1) = 9;
  EXPECT_ANY_THROW(A.InverseMatrix());
}
