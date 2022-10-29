#include <stdio.h>
int main(void) {
  int i = 0;
  int a;
  scanf("%d", &a);
  printf("Hello, user!\n");
  printf("a = %d\n", a);
  while (i<10) { 
    printf("a = %d = %#X\n",a * a, a * a);
    ++i;
    ++a;
   }
  return 0;
}
