#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>

using namespace std;

class Matrix {

public:
  int m, n;
  int *arr;
  Matrix();
  Matrix(int m, int n);

  void print_dimensions();
  void print_matrix();
  void read_matrix();

  Matrix operator+(const Matrix &otherMatrix);
  
  friend ostream &operator<<(ostream &output, const Matrix &m) {
    output << "M : " << m.m << " N : " << m.n;
    return output;
  }
};

#endif