#include "matrix.h"
#include <iostream>
using namespace std;

int main() {
  Matrix m1;
  m1.print_dimensions();

  m1.read_matrix();
  m1.print_matrix();

  return 0;
}