#include <stdio.h>
#include <pthread.h>

int sum = 0;
pthread_mutex_t lock;

void* worker(void* arg){
  for(int i = 0; i < 1000000; i++) {
    pthread_mutex_lock(&lock);
    sum = sum + 10;
    pthread_mutex_unlock(&lock);
  }
}

int main() {
  char *name[] = {"Thread 0", "Thread 1"};
  pthread_t tid[2];
  pthread_attr_t attr[2];

  pthread_attr_init(&attr[0]);
  pthread_attr_init(&attr[1]);

  pthread_mutex_init(&lock, NULL);
  pthread_create(&tid[0], &attr[0], worker, name[0]);
  pthread_create(&tid[1], &attr[1], worker, name[1]);

  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);

  printf("sum = %d\n", sum);

  pthread_mutex_destroy(&lock);
  return 0;

}
