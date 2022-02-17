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
  // int fd[2];

  // pipe(fd);

  printf("---PARENT ID---: %d\n", getpid());

  // write(fd[1], &(m1.m), sizeof(int));
  // write(fd[1], &(m1.n), sizeof(int));

  // for (int i = 0; i < m1.m; i++) {
  //   for (int j = 0; j < m1.n; j++) {
  //     write(fd[1], &(*(m1.arr + i * m1.n + j)), sizeof(int));
  //     // cout << *(arr + i * n + j) << " ";
  //   }
  //   cout << "\n";
  // }

  // close(fd[1]);

  pid = fork();
  if (pid == 0) {
    int m, n;
    // read(fd[0], &m, sizeof(int));
    // read(fd[0], &n, sizeof(int));
    printf("---CHILD ID---: %d\n", getpid());
    printf("Printing matrix m1 M\n");
    cout << m1.m << endl;

    ofstream myfile;
    myfile.open("example.txt");
    myfile << "MATRIX: " << m << n << "\n";
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