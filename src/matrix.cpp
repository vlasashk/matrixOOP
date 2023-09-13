#include "matrix.h"

S21Matrix::S21Matrix() : rows(2), columns(2) {
  matrix =
      std::vector<std::vector<double>>(rows, std::vector<double>(columns, 0.0));
}

S21Matrix::S21Matrix(int rowsAssign, int columnsAssign)
    : rows(rowsAssign), columns(columnsAssign) {
  if (rows > 0 && columns > 0) {
    matrix = std::vector<std::vector<double>>(
        rows, std::vector<double>(columns, 0.0));
  } else {
    throw std::out_of_range("ERROR: Invalid index");
  }
}

S21Matrix::S21Matrix(const S21Matrix &copyFrom) {
  rows = copyFrom.rows;
  columns = copyFrom.columns;
  matrix.resize(rows);
  for (int i = 0; i < rows; i++) {
    matrix[i].resize(columns);
    for (int j = 0; j < columns; j++) {
      matrix[i][j] = copyFrom.matrix[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&moveFrom)
    : matrix(std::move(moveFrom.matrix)),
      rows(moveFrom.rows),
      columns(moveFrom.columns) {
  moveFrom.matrix.clear();
  moveFrom.columns = 0;
  moveFrom.rows = 0;
}

S21Matrix::~S21Matrix() { matrix.clear(); }

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool res = true;
  if (rows == other.rows && columns == other.columns) {
    for (int i = 0; i < rows && res == true; i++) {
      for (int j = 0; j < columns && res == true; j++) {
        if (std::abs(matrix[i][j] - other.matrix[i][j]) > 1e-7) {
          res = false;
        }
      }
    }
  } else {
    res = false;
  }
  return res;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (this->validateSumSub(other)) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        matrix[i][j] += other.matrix[i][j];
      }
    }
  } else {
    throw std::invalid_argument(
        "ERROR: Matrix dimensions are not compatible for summ");
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (this->validateSumSub(other)) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        matrix[i][j] -= other.matrix[i][j];
      }
    }
  } else {
    throw std::invalid_argument(
        "ERROR: Matrix dimensions are not compatible for substraction");
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (this->validateMul(other)) {
    std::vector<std::vector<double>> res(
        rows, std::vector<double>(other.columns, 0.0));
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < other.columns; j++) {
        for (int k = 0; k < columns; k++) {
          res[i][j] += matrix[i][k] * other.matrix[k][j];
        }
      }
    }
    matrix = res;
    columns = other.columns;
  } else {
    throw std::invalid_argument(
        "ERROR: Matrix dimensions are not compatible for multiplication");
  }
}

double S21Matrix::Determinant() {
  double res = 0.0;
  if (rows == columns) {
    if (rows == 1) {
      res = matrix[0][0];
    } else {
      res = this->determinantRecursive();
    }
  } else {
    throw std::invalid_argument("ERROR: Matrix must be squared");
  }
  return res;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix res(columns, rows);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      res.matrix[i][j] = matrix[j][i];
    }
  }
  return res;
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix res(rows, columns);
  if (rows == columns) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        S21Matrix minor(this->rows - 1, this->columns - 1);
        this->minorReshape(&minor, i, j);
        double tempDet = minor.Determinant();
        int sign = ((i + j) % 2 == 0) ? 1 : -1;
        res.matrix[i][j] = sign * tempDet;
      }
    }
  } else {
    throw std::invalid_argument("ERROR: Matrix must be squared");
  }
  return res;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (rows != columns) {
    throw std::invalid_argument("ERROR: Matrix must be squared");
  }
  double det = this->Determinant();
  if (std::abs(det) < 1e-6) {
    throw std::invalid_argument("ERROR: Determinant is 0");
  }
  S21Matrix res(rows, columns);
  if (rows != 1) {
    auto minor = this->CalcComplements();
    auto tempTrans = minor.Transpose();
    for (int i = 0; i < res.rows; i++) {
      for (int j = 0; j < res.columns; j++) {
        res.matrix[i][j] = tempTrans.matrix[i][j] / det;
      }
    }
  } else {
    res.matrix[0][0] = 1.0 / det;
  }
  return res;
}
