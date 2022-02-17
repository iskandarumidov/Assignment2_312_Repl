#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <fstream>

int main() {
  int fd[2];
  pipe(fd);
  printf("---PARENT ID---: %d\n", getpid());
  int id = fork();
  if (id == 0) {
    close(fd[0]);
    int x;
    printf("---CHILD ID---: %d\n", getpid());
    printf("Input: ");
    scanf("%d", &x);
    write(fd[1], &x, sizeof(int));
    close(fd[1]);

    //Write to file
    std::ofstream myfile;
    myfile.open("example.txt");
    myfile << x;
    myfile.close();

  } else {
    close(fd[1]);
    int y;
    read(fd[0], &y, sizeof(int));
    close(fd[0]);
    printf("Got from child: %d\n", y);
  }

  return 0;
}