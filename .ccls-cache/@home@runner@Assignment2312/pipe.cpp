// C program to illustrate
// pipe system call in C
#include <stdio.h>
#include <unistd.h>
#define MSGSIZE 16
char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";
int matrix[3][2] = {{0,1}, {4,5}, {8,9}};

int main()
{
  printf("HI\n");
	int inbuf[5];
	int p[2], i;

	if (pipe(p) < 0)
    return 1;
		// exit(1);

	/* continued */
	/* write pipe */
  int arrTest[] = {4, 7, 3, 1, 9};

  for (i = 0; i < 5; i++) {
	  write(p[1], &arrTest[i], sizeof(int));
  }
  printf("HI\n");

	// write(p[1], msg1, MSGSIZE);
	// write(p[1], msg2, MSGSIZE);
	// write(p[1], msg3, MSGSIZE);

	for (i = 0; i < 5; i++) {
		/* read pipe */
		printf("%ld", read(p[0], inbuf, sizeof(int)));
		// printf("%d\n", inbuf);
	}
	return 0;
}
