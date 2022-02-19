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
  Matrix m1;
  Matrix m2;
  // TODO
  int isInvalidInput = 1;
  while (isInvalidInput) {
    print_instructions();
    print_example();
    cin >> m1;

    print_instructions();
    cin >> m2;
    // Both matrices need to be square for addition and subtraction to work
    // For multiplication, rows of first need to == cols of second
    // But they still will have to be square matrices because of addition
    if ((m1.m == m1.n) & (m2.m == m2.n) & (m1.m == m2.m) & (m1.m > 0 & m1.n > 0 & m2.m > 0 & m2.n > 0)){
      isInvalidInput = 0;
    }else{
      cout << "INVALID INPUT" << endl;
    }
  }

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

    printf("---SUBTRACTOR CHILD ENDING---\n");
    exit(EXIT_SUCCESS);
  }
  waitpid(pid2, &status2, 0);

  pid3 = fork();
  if (pid3 == 0) {
    int m, n;
    printf("---MULTIPLICATOR CHILD ID---: %d\n", getpid());
    Matrix mRes = m1 * m2;

    ofstream myfile;
    myfile.open("mult.out");
    myfile << mRes;
    myfile.close();

    printf("---MULTIPLICATOR CHILD ENDING---\n");
    exit(EXIT_SUCCESS);
  }
  waitpid(pid3, &status3, 0);

  pid = fork();
  if (pid == 0) {
    char *argv[3] = {NULL};
    execv("reader.out", argv);
  }

  waitpid(pid, &status, 0);

  printf("---PARENT ENDING---\n");
  return 0;
}