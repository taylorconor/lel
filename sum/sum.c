#include <unistd.h>
#include <sys/mman.h>

void foo();

int main() {
  foo();
  int x = 2 + 2;
  printf("x = %d\n", x);
}

void foo() {
  char *p = &main;
  while (*p != 4) {p++;}
  mprotect((void*)((long)p&-sysconf(_SC_PAGESIZE)), 1, 7);
  *p += 1;
}
