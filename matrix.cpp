#include "matrix.h"

using namespace std;

Matrix::Matrix()
{
  this->m = 0;
  this->n = 0;
}

Matrix::Matrix(int m, int n)
{
  this->m = m;
  this->n = n;
  this->arr = new int[m * n];
}

void Matrix::print_instructions()
{
  cout << "Please enter M, then N on one line" << endl;
  cout << "After that, enter the matrix" << endl;
}

void Matrix::print_example()
{
  cout << "e.g." << endl;
  cout << "3 2" << endl;
  cout << "1 1" << endl;
  cout << "1 1" << endl;
  cout << "1 1" << endl;
  cout << endl;
}

Matrix Matrix::operator+(const Matrix &otherMatrix)
{
  Matrix newMatrix(this->m, this->n);
  int *newMatrixArr = newMatrix.arr;
  int *otherMatrixArr = otherMatrix.arr;

  for (int i = 0; i < this->m; i++)
  {
    for (int j = 0; j < this->n; j++)
    {
      *(newMatrixArr + i * n + j) =
          *(arr + i * n + j) + *(otherMatrixArr + i * n + j);
    }
  }

  return newMatrix;
}

Matrix Matrix::operator-(const Matrix &otherMatrix)
{
  Matrix newMatrix(this->m, this->n);
  int *newMatrixArr = newMatrix.arr;
  int *otherMatrixArr = otherMatrix.arr;

  for (int i = 0; i < this->m; i++)
  {
    for (int j = 0; j < this->n; j++)
    {
      *(newMatrixArr + i * n + j) =
          *(arr + i * n + j) - *(otherMatrixArr + i * n + j);
    }
  }

  return newMatrix;
}

Matrix Matrix::operator*(const Matrix &otherMatrix)
{
  Matrix newMatrix(this->m, this->n);
  int *newMatrixArr = newMatrix.arr;
  int *otherMatrixArr = otherMatrix.arr;

  int r1 = this->m;
  int c1 = this->n;
  int r2 = otherMatrix.m;
  int c2 = otherMatrix.n;

  for (int i = 0; i < r1; ++i)
    for (int j = 0; j < c2; ++j)
      for (int k = 0; k < r2; ++k)
      {
        // Logic here is a bit complex
        // It helps though that we allow only square matrices (since all 3 operations can be performed only on square matrices)

        *(newMatrixArr + i * n + j) +=
            *(arr + i * n + k) * *(otherMatrixArr + k * n + j);
      }

  return newMatrix;
}