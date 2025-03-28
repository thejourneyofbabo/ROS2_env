#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void *print_usage(int argc, char *argv[]) {
  printf("Usage: %s serial|parallel num_tasks\n", argv[0]);
  exit(1);
}

void *task(int id) {
  printf("Task %d started\n", id);
  double result = 0.0;
  for (long i = 0; i < 10000000; i++) {
    result = result + sin(i) * tan(i);
  }
  printf("Task %d completed with result %e\n", id, result);
}

void *serial(int num_tasks) {
  int i;
  for (i = 0; i < num_tasks; i++)
    task(i);
}

void *threaded_task(void *t) {
  long id = (long) t;
  printf("Thread %ld started\n", id);
  task(id);
  printf("Thread %ld done\n", id);
  pthread_exit(0);
}

void *parallel(int num_tasks) {
  int num_threads = num_tasks;
  pthread_t thread[num_threads];
  int rc;
  long t;
  for (t = 0; t < num_threads; t++) {
    printf("Creating thread %ld\n", t);
    rc = pthread_create(&thread[t], NULL, threaded_task, (void *)t);
    if(rc) {
      printf("ERROR: return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }
  for (t = 0; t < num_threads; t++)
    pthread_join(thread[t], NULL);
}

int main(int argc, char *argv[]) {
  if (argc != 3)
    print_usage(argc, argv);

  int num_tasks = atoi(argv[2]);

  if(!strcmp(argv[1], "serial")) {
    serial(num_tasks);
  } else if (!strcmp(argv[1], "parallel")) {
    parallel(num_tasks);
  }
  else {
    print_usage(argc, argv);
  }

  printf("Main completed\n");
  pthread_exit(NULL);
}
