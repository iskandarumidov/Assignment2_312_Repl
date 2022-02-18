#include "matrix.h"
#include <fstream>
#include <iostream>

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <cstdlib>
#include <stdio.h>

using namespace std;

int main() {
  Matrix m1;
  m1.print_dimensions();

  m1.read_matrix();
  m1.print_matrix();
  // Matrix m2(3,2);
  Matrix m2;
  m2.read_matrix();
  // Matrix mRes = m1 + m2;
  // mRes.print_matrix();

  // FORK STUFF - ADDING MATRICES
  int pid;
  int status;

  printf("---PARENT ID---: %d\n", getpid());

  pid = fork();
  if (pid == 0) {
    int m, n;
    printf("---CHILD ID---: %d\n", getpid());
    // printf("Printing matrix m1 M\n");
    Matrix mRes = m1 + m2;
    mRes.print_matrix();
    // cout << m << endl;

    ofstream myfile;
    myfile.open("example.txt");
    // myfile << "MATRIX: " << m << n << "\n";
    myfile << "MATRIX: " << mRes << "\n";
    myfile.close();

    printf("---CHILD ENDING---\n");
    exit(EXIT_SUCCESS);
  }

  // Comment from here to...
  // Parent waits process pid (child)
  waitpid(pid, &status, 0);
  printf("---PARENT ENDING---\n");
  return 0;
}