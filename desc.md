fork & exec
multiprocess
matrix addition, subtraction, multiplication


read 2 matrices: row, col
m1xn1 and m2xn2
After you read each matrix size you should read each
matrix one row at a time.

Example:

   Enter the size of matrix 1: 4 5
   Enter matrix 1 rows:
     1 2 3 4 5
     -1 2 3 -5 6
     8 3 0 -3 1
     5 0 0 1 -6

     Do the same thing for Matrix 2.


parent process to fork 3 children, each of the children is going to
peroform one of the operations mentioned above matrix multiplication, addition,
and subtraction. After the computation, each child should write the output of
their process to a file, let's call files mult.out, add.out, and sub.out to
reflect the name of the process which they performed.

Your main parent process should wait for all 3 children to finish (waitpid). Once
they finish, the parent process should exec a different process that will perform
opening the 3 files and printing their results out to the screen. In this case you
have to write a simple program that opens 3 files and prints their formatted results
out to the screen (must be organized and clean output).


So, what you will have is 2 programs, the multiprocessed program with a parent and
3 children, and another program that should replace the main process once the children
finish to open the files and print their results.


Submit only two source code programs
Code: readable, well-documented