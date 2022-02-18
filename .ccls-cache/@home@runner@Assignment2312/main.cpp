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
void print_instructions() {
  cout << "Please enter M, then N on one line" << endl;
  cout << "After that, enter the matrix" << endl;
}

void print_example() {
  cout << "e.g." << endl;
  cout << "3 2" << endl;
  cout << "1 1" << endl;
  cout << "1 1" << endl;
  cout << "1 1" << endl;
  cout << endl;
}
int main() {
  print_instructions();
  print_example();
  Matrix m1;
  cin >> m1;

  print_instructions();
  Matrix m2;
  cin >> m2;

  // FORK STUFF - ADDING MATRICES
  int pid, status;

  printf("---PARENT ID---: %d\n", getpid());

  pid = fork();
  if (pid == 0) {
    int m, n;
    printf("---ADDER CHILD ID---: %d\n", getpid());
    Matrix mRes = m1 + m2;

    ofstream myfile;
    myfile.open("add.out");
    myfile << mRes;
    myfile.close();

    printf("---ADDER CHILD ENDING---\n");
    exit(EXIT_SUCCESS);
  }

  // Comment from here to...
  // Parent waits process pid (child)
  waitpid(pid, &status, 0);

  pid = fork();
  if (pid == 0) {
    int m, n;
    printf("---READER CHILD ID---: %d\n", getpid());
    Matrix mRead;

    ifstream myfile("add.out");
    if (myfile.is_open()) {
      myfile >> mRead;
      myfile.close();
    } else
      cout << "Unable to open file";
    cout << "READER READ THIS FROM FILE:" << endl;
    cout << mRead;

    printf("---READER CHILD ENDING---\n");
    exit(EXIT_SUCCESS);
  }

  printf("---PARENT ENDING---\n");
  return 0;
}