#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
  int m, n;
  int *arr;

public:
  Matrix();
  Matrix(int m, int n);

  void print_dimensions();
  void print_matrix();
  void read_matrix();

  //   void set_values(int, int);
  //   int area() { return width * height; }

  Matrix operator+(const Matrix &otherMatrix);
};

#endif