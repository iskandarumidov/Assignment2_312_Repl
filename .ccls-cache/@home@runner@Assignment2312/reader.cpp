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
  return 0;
}