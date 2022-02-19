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
  cout << "ADDED FROM FILE:" << endl;
  cout << mRead;

  ifstream myfile2("sub.out");
  if (myfile2.is_open()) {
    myfile2 >> mRead;
    myfile2.close();
  } else
    cout << "Unable to open file";
  cout << "SUBTRACTED FROM FILE:" << endl;
  cout << mRead;

  printf("---READER CHILD ENDING---\n");
  exit(0);
  return 0;
}

// g++ reader.cpp matrix.cpp -o reader.out