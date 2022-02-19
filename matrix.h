#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>
#include <iostream>

using namespace std;

class Matrix
{

public:
  int m, n; // Dimensions
  int *arr; // Elements
  Matrix(); // Default constructor
  Matrix(int m, int n);

  static void print_instructions();
  static void print_example();

  // Overload operators
  Matrix operator+(const Matrix &otherMatrix);
  Matrix operator-(const Matrix &otherMatrix);
  Matrix operator*(const Matrix &otherMatrix);

  // Also overload >> and << for easy IO using Matrix class
  friend ostream &operator<<(ostream &output, const Matrix &m)
  {
    output << m.m << " " << m.n << endl;

    for (int i = 0; i < m.m; i++)
    {
      for (int j = 0; j < m.n; j++)
      {
        output << *(m.arr + i * m.n + j) << " ";
      }
      output << endl;
    }
    return output;
  }

  friend istream &operator>>(istream &input, Matrix &m)
  {
    input >> m.m >> m.n;
    m.arr = new int[m.m * m.n];
    for (int i = 0; i < m.m; i++)
    {
      for (int j = 0; j < m.n; j++)
      {
        input >> *(m.arr + i * m.n + j);
      }
    }
    return input;
  }
};

#endif