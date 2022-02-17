#include "matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix() {
  cout << "M?" << endl;
  cin >> this->m;
  cout << "N?" << endl;
  cin >> this->n;
  this->arr = new int[m * n];
}

Matrix::Matrix(int m, int n) {
  this->m = m;
  this->n = n;
  this->arr = new int[m * n];
}

void Matrix::print_dimensions() { cout << "m: " << m << " n: " << n << "\n"; }

void Matrix::print_matrix() {
  for (int i = 0; i < this->m; i++) {
    for (int j = 0; j < this->n; j++) {
      cout << *(arr + i * n + j) << " ";
    }
    cout << "\n";
  }
}

void Matrix::read_matrix() {
  int val;

  for (int i = 0; i < this->m; i++) {
    for (int j = 0; j < this->n; j++) {
      cin >> val;
      *(arr + i * n + j) = val;
    }
  }
}

Matrix Matrix::operator+(const Matrix &otherMatrix) {
  Matrix newMatrix(this->m, this->n);
  int* newMatrixArr = newMatrix.arr;
  int* otherMatrixArr = otherMatrix.arr;

  if (this->m != otherMatrix.m | this->n != otherMatrix.n) {
    cout << "MATRICES HAVE DIFFERENT DIMENSIONS" << endl;
    exit(0);
  }

  for (int i = 0; i < this->m; i++) {
    for (int j = 0; j < this->n; j++) {
      *(newMatrixArr + i * n + j) = *(arr + i * n + j) + *(otherMatrixArr + i * n + j);      
    }
  }

  return newMatrix;
}
