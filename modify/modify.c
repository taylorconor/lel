#include <unistd.h>
#include <sys/mman.h>

void foo() {
  printf("hello\n");
}

int main() {
  char *gg = &foo;
  for (;*(gg+3)!=0154 || *(gg+4)!=108; gg++);
  mprotect((void*)((long)gg&-sysconf(_SC_PAGESIZE)), 1, 7);
  for (int i=706,j=1,k; j<10; k=i>>j&7,j+=3,*(gg+k)=*(gg+k+2));
  foo();
}
