#include "matrix.h"

bool S21Matrix::PrintMatrix() {
  bool res = true;
  if (rows > 0 && columns > 0 && !matrix.empty()) {
    auto maxSize = rows * columns - 1;
    int reserve = 0;
    while (maxSize > 0) {
      maxSize /= 10;
      reserve++;
    }
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        std::cout << std::setw(reserve) << matrix[i][j] << " ";
      }
      std::cout << "\n";
    }
  } else {
    std::cout << "ERROR: Wrong matrix\n";
    res = false;
  }
  return res;
}

double S21Matrix::determinantRecursive() {
  double res = 0.0;
  if (rows == 2) {
    res = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  } else {
    for (int i = 0; i < rows; i++) {
      S21Matrix minor(this->rows - 1, this->columns - 1);
      this->minorReshape(&minor, i, 0);
      int sign = (i % 2 == 0) ? 1 : -1;
      res += sign * matrix[i][0] * minor.determinantRecursive();
    }
  }
  return res;
}

void S21Matrix::minorReshape(S21Matrix *result, int row, int column) {
  for (int i = 0, k = 0; i < rows; i++, k++) {
    if (i == row) {
      i++;
    }
    for (int j = 0, m = 0; j < columns; j++, m++) {
      if (j == column) {
        j++;
      }
      if (i < rows && j < columns) {
        result->matrix[k][m] = matrix[i][j];
      }
    }
  }
}

bool S21Matrix::validateSumSub(const S21Matrix &other) {
  bool res = true;
  if (rows != other.rows || columns != other.columns) {
    res = false;
  }
  return res;
}

bool S21Matrix::validateMul(const S21Matrix &other) {
  bool res = true;
  if (columns != other.rows) {
    res = false;
  }
  return res;
}
