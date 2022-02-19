#include <iostream>
using namespace std;

int main() {

  int m1[2][3] = {{1, 2, 3}, {1, 1, 1}};
  int m2[3][2] = {{1, 2}, {1, 3}, {1, 1}};
  int i, j, k;
  int r1 = 2;
  int c1 = 3;
  int r2 = 3;
  int c2 = 2;
  int a[10][10];
  int b[10][10];
  int mult[10][10];

  // int a[10][10], b[10][10], mult[10][10], r1, c1, r2, c2, i, j, k;

  // Storing elements of first matrix.
  // cout << endl << "Enter elements of matrix 1:" << endl;
  // for (i = 0; i < r1; ++i)
  //   for (j = 0; j < c1; ++j) {
  //     cout << "Enter element a" << i + 1 << j + 1 << " : ";
  //     cin >> a[i][j];
  //   }

  // Storing elements of second matrix.
  // cout << endl << "Enter elements of matrix 2:" << endl;
  // for (i = 0; i < r2; ++i)
  //   for (j = 0; j < c2; ++j) {
  //     cout << "Enter element b" << i + 1 << j + 1 << " : ";
  //     cin >> b[i][j];
  //   }

  // Initializing elements of matrix mult to 0.
  for (i = 0; i < r1; ++i)
    for (j = 0; j < c2; ++j) {
      mult[i][j] = 0;
    }

  // Multiplying matrix a and b and storing in array mult.
  for (i = 0; i < r1; ++i)
    for (j = 0; j < c2; ++j)
      for (k = 0; k < c1; ++k) {
        mult[i][j] += a[i][k] * b[k][j];
      }

  // Displaying the multiplication of two matrix.
  cout << endl << "Output Matrix: " << endl;
  for (i = 0; i < r1; ++i)
    for (j = 0; j < c2; ++j) {
      cout << " " << mult[i][j];
      if (j == c2 - 1)
        cout << endl;
    }

  return 0;
}