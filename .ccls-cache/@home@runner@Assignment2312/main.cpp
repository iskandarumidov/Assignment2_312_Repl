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
  cout << "Please enter M1, then N1 on one line" << endl;
  cout << "After that, enter the matrix" << endl;
  Matrix m1;
  cin >> m1;

  cout << "Please enter M2, then N2 on one line" << endl;
  cout << "After that, enter the matrix" << endl;
  Matrix m2;
  cin >> m2;

  // FORK STUFF - ADDING MATRICES
  int pid;
  int status;

  printf("---PARENT ID---: %d\n", getpid());

  pid = fork();
  if (pid == 0) {
    int m, n;
    printf("---CHILD ID---: %d\n", getpid());
    Matrix mRes = m1 + m2;

    ofstream myfile;
    myfile.open("add.out");
    myfile << mRes;
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