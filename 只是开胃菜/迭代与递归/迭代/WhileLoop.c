#include <stdio.h>

//while循环
int WhileLoop(int n)
{
  int res = 0;
  int i = 1;
  while (i <= n)
  {
    res += i;
    i++;
  }
  return res;
}

int main()
{
  int n = 5;
  int res = WhileLoop(n);
  printf("%d\n", res);
  return 0;
}