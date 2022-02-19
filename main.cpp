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

int main()
{
  Matrix m1;
  Matrix m2;

  // Flag to avoid invalid input
  int isInvalidInput = 1;
  while (isInvalidInput)
  {
    Matrix::print_instructions();
    Matrix::print_example();
    // Since I overloaded the >> operator in the matrix class, I can use this syntax
    cin >> m1;

    Matrix::print_instructions();
    cin >> m2;
    // Both matrices need to be square for addition and subtraction to work
    // For multiplication, rows of first need to == cols of second
    // But they still will have to be square matrices because of addition
    // Also - need to check if values are positive
    if ((m1.m == m1.n) & (m2.m == m2.n) & (m1.m == m2.m) & (m1.m > 0 & m1.n > 0 & m2.m > 0 & m2.n > 0))
    {
      isInvalidInput = 0;
    }
    else
    {
      cout << "INVALID INPUT" << endl;
    }
  }

  // This is required to keep track of children
  int pidAdd, pidSub, pidMult, pidReader, statusAdd, statusSub, statusMult, statusReader;

  printf("---PARENT ID---: %d\n", getpid());

  // Fork to calculate addition and write to add.out
  pidAdd = fork();
  if (pidAdd == 0)
  {
    int m, n;
    printf("---ADDER CHILD ID---: %d\n", getpid());
    // Since I overloaded the plus operator in the matrix class, I can use this syntax
    Matrix mRes = m1 + m2;

    ofstream myfile;
    myfile.open("./out/add.out");
    // Since I overloaded the << operator in the matrix class, I can use this syntax
    myfile << mRes;
    myfile.close();

    printf("---ADDER CHILD ENDING---\n");
    exit(EXIT_SUCCESS);
  }
  // Parent waits for the adder child to finish
  waitpid(pidAdd, &statusAdd, 0);

  // Fork to calculate subtraction and write to sub.out
  pidSub = fork();
  if (pidSub == 0)
  {
    int m, n;
    printf("---SUBTRACTOR CHILD ID---: %d\n", getpid());
    // Since I overloaded the minus operator in the matrix class, I can use this syntax
    Matrix mRes = m1 - m2;

    ofstream myfile;
    myfile.open("./out/sub.out");
    myfile << mRes;
    myfile.close();

    printf("---SUBTRACTOR CHILD ENDING---\n");
    exit(EXIT_SUCCESS);
  }
  // Parent waits for the subtractor child to finish
  waitpid(pidSub, &statusSub, 0);

  // Fork to calculate multiplication and write to mult.out
  pidMult = fork();
  if (pidMult == 0)
  {
    int m, n;
    printf("---MULTIPLICATOR CHILD ID---: %d\n", getpid());
    // Since I overloaded the multiply operator in the matrix class, I can use this syntax
    Matrix mRes = m1 * m2;

    ofstream myfile;
    myfile.open("./out/mult.out");
    myfile << mRes;
    myfile.close();

    printf("---MULTIPLICATOR CHILD ENDING---\n");
    exit(EXIT_SUCCESS);
  }
  // Parent waits for the multiplier child to finish
  waitpid(pidMult, &statusMult, 0);

  // Fork to read addition, subtraction and multiplication from files
  pidReader = fork();
  if (pidReader == 0)
  {
    printf("---READER CHILD ID---: %d\n", getpid());
    char *argv[3] = {NULL};
    execv("./out/reader.out", argv);
    printf("---READER CHILD ENDING---\n");
    exit(EXIT_SUCCESS);
  }
  // Parent waits for the reader to finish
  waitpid(pidReader, &statusReader, 0);

  printf("---PARENT ENDING---\n");
  return 0;
}