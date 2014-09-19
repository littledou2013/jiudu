#include <iostream>
#include <cstdio>
using namespace std;

//典型的使用并查集寻找连通子图个数
const int N = 100010;

int root[N];
//寻找结点的根，寻找结点的跟有两种方式，一种是递归，一种是循环
//注意在寻找根的同时要把中途遍历的点的根更新为最新的根
int findRoot(int n)
{
	//寻找根节点的同时更新遍历的结点的更节点
	/* 方法一：使用循环的方式找到根后，再更新结点的根
	int node = n;
	while (root[node] != -1)
		node = root[node];
	int temp;
	while (root[n] ！= -1）
	{
		temp = root[n];
		root[n] = node;
		n = temp;
	}
	return node;
	*/
	//方法二：使用递归的方式
	if (root[n] == -1)
		return n;
	return root[n] = findRoot(root[n]);
}

int main(void)
{
	int n, m;
	int a, b;
	while (scanf("%d", &n) != EOF && n != 0)
	{
		scanf("%d", &m);
		//注意这里在设置每个结点为根节点的方式有两种，一种是使root[i] = i,一种是使root[i] = -1;
		for (int i = 1; i <= n; ++i)
			root[i] = -1;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d", &a, &b);
			//注意一定要找到a,b的根，然后把根合并为只有一个根
			a = findRoot(a);
			b = findRoot(b);
			if (a != b)
				root[a] = b;
		}
		int count = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (root[i] == -1)
				++count;
		}
		printf("%d\n", count);
	}
	
	return 0;

}
