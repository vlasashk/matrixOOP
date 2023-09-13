#ifndef SRC_MATRIX_H_
#define SRC_MATRIX_H_

#include <iomanip>
#include <iostream>
#include <vector>

class S21Matrix {
 private:
  std::vector<std::vector<double>> matrix;
  int rows;
  int columns;
  bool validateSumSub(const S21Matrix &other);
  bool validateMul(const S21Matrix &other);
  double determinantRecursive();
  void minorReshape(S21Matrix *result, int row, int column);

 public:
  S21Matrix();
  S21Matrix(int rowsAssign, int columnsAssign);
  S21Matrix(const S21Matrix &copyFrom);
  S21Matrix(S21Matrix &&moveFrom);
  ~S21Matrix();

  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(const S21Matrix &other);
  S21Matrix operator*(const double number);
  bool operator==(const S21Matrix &other);
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(const double number);
  double &operator()(int i, int j);

  bool PrintMatrix();
};
#endif  //  SRC_MATRIX_H_
