#include <stdio.h>
#include <stdlib.h>
void foo(int b, int* c){
  printf("%d\n", b);
}

int main(void){
  int d = 0;
  int *e = (int *)malloc(10 * sizeof(int));
  for(int i=0; i<10; i++){
    e[i] = i;
    d += i;
  }
  printf("%p\n", &d);
  foo(d, e);
  return 0;
}
