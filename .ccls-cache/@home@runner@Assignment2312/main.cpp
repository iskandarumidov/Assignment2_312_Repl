#include "matrix.h"
#include <iostream>
using namespace std;

int main() {
  Matrix m1;
  m1.print_dimensions();

  m1.read_matrix();
  m1.print_matrix();
  // Matrix m2(3,2);
  Matrix m2;
  m2.read_matrix();
  Matrix mRes = m1+m2;
  mRes.print_matrix();

  

  return 0;
}