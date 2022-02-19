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
  int pid, status, pid2, status2, pid3, status3;

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
  waitpid(pid, &status, 0);

  pid2 = fork();
  if (pid2 == 0) {
    int m, n;
    printf("---SUBTRACTOR CHILD ID---: %d\n", getpid());
    Matrix mRes = m1 - m2;

    ofstream myfile;
    myfile.open("sub.out");
    myfile << mRes;
    myfile.close();

    printf("---ADDER CHILD ENDING---\n");
    exit(EXIT_SUCCESS);
  }
  waitpid(pid2, &status2, 0);



  pid = fork();
  if (pid == 0) {
    char *argv[3] = {NULL};
    execv("reader.out", argv);
  }

  waitpid(pid, &status, 0);

  printf("---PARENT ENDING---\n");
  return 0;
}