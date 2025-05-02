#include <stdio.h>

//for循环
int ForLoop(int n)
{
  int res = 0;
  for (int i = 1; i <= n; i++)
  {
    res += i;
  }
  return res;
}

int main()
{
  int n = 5, res = 0;
  res = ForLoop(n);
  printf("%d\n", res);
  return 0;
}