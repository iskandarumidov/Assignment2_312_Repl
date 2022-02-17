#include "matrix.h"
#include <iostream>
using namespace std;

// void Rectangle::set_values (int x, int y) {
//   width = x;
//   height = y;
// }

int main() {
  Matrix m1;
  m1.print_dimensions();

  m1.read_matrix();
  m1.print_matrix();

  return 0;
}