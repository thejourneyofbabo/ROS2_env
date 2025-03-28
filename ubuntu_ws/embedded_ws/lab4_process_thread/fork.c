#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int ret, wc;
  printf("Hello World! (PID : %d)\n", (int)getpid());

  ret = fork();
  if(ret < 0) {
    fprintf(stderr, "fork failed\n");
  }
  else if (ret == 0) {
    // Child process routine
    printf("This is Child (PID : %d)\n", (int)getpid());
  }
  else {
    // Parent routine
    wc = wait(NULL);
    printf("This is Parent (PID: %d)\n", (int)getpid());
  }
  return 0;
}
