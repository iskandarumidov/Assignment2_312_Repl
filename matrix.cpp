#include "matrix.h"

using namespace std;

Matrix::Matrix() {
  this->m = 0;
  this->n = 0;
}

Matrix::Matrix(int m, int n) {
  this->m = m;
  this->n = n;
  this->arr = new int[m * n];
}

//  void Matrix::print_example() {
//   cout << "e.g." << endl;
//   cout << "3 2" << endl;
//   cout << "1 1" << endl;
//   cout << "1 1" << endl;
//   cout << "1 1" << endl;
//   cout << endl;
// }

Matrix Matrix::operator+(const Matrix &otherMatrix) {
  Matrix newMatrix(this->m, this->n);
  int *newMatrixArr = newMatrix.arr;
  int *otherMatrixArr = otherMatrix.arr;

  if (this->m != otherMatrix.m | this->n != otherMatrix.n) {
    cout << "MATRICES HAVE DIFFERENT DIMENSIONS" << endl;
    exit(0);
  }

  for (int i = 0; i < this->m; i++) {
    for (int j = 0; j < this->n; j++) {
      *(newMatrixArr + i * n + j) =
          *(arr + i * n + j) + *(otherMatrixArr + i * n + j);
    }
  }

  return newMatrix;
}
