#include "matrix.h"
/*
 ---------------------------------------------------------
|                                                         |
|                   OPERATORS OVERLOAD                    |
|                                                         |
 ---------------------------------------------------------
*/

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double number) {
  S21Matrix result(*this);
  result.MulNumber(number);
  return result;
}

bool S21Matrix::operator==(const S21Matrix &other) {
  return this->EqMatrix(other);
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this != &other) {
    rows = other.rows;
    columns = other.columns;
    this->matrix.resize(other.rows);
    for (int i = 0; i < rows; i++) {
      this->matrix[i].resize(other.columns);
      for (int j = 0; j < columns; j++) {
        matrix[i][j] = other.matrix[i][j];
      }
    }
  }
  return *this;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const double number) {
  MulNumber(number);
  return *this;
}

double &S21Matrix::operator()(int i, int j) {
  if (i < rows && j < columns && i >= 0 && j >= 0) {
    return matrix[i][j];
  } else {
    throw std::out_of_range("ERROR: Invalid index");
  }
}
