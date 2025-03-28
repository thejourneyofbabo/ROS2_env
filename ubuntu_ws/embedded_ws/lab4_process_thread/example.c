#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int ret, wc;
  printf("Hello World! (PID : %d)\n", (int)getpid());

  ret = fork();
  if (ret < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (ret == 0) {
    printf("This is Child (PID : %d)\n", (int)getpid());

    char *args[3];
    args[0] = strdup("echo");
    args[1] = strdup("Goodbye World!");
    args[2] = NULL;

    execvp(args[0], args);
    printf("exec Error occurs");
  }
  else {
    wc = wait(NULL);
    printf("This is Parent (PID: %d)\n", (int)getpid());
  }
  return 0;
}

