#include <stdio.h>
/*
  典型的使用并查集寻找连通子图个数
  下面方法应该是内存占有最少，时间也最优的方法
  内存：1232KB， 耗时：220ms(根据服务器会有些浮动）
  此方法的代码内存为什么会降下来：
  1、是没有包含iostream，包含iostream会使内存增加500KB左右
  2、使用C语言编译，C++编译执行会比C编译执行多100KB左右的开销
  3、root全局变量放到main函数内，会比放在main函数外少70KB的内存开销
*/
int root[100001] = {0};
int main(void)
{
	int n, m, a, b, i;
	while (scanf("%d", &n)  && n != 0)
	{
		scanf("%d", &m);
		for (i = 1; i <= n; ++i)
			root[i] = -1;
		for (i = 0; i < m; ++i)
		{
			scanf("%d%d", &a, &b);
      while (root[a] != -1)
           a = root[a];
       while (root[b] != -1)
            b = root[b];
			if (a < b)
				root[a] = b;
      if (a > b)
         root[b] = a;
		}
		int count = 0;
		for (i = 1; i <= n; ++i)
			if (root[i] == -1)
				++count;
		printf("%d\n", count);
	}
	return 0;

}
