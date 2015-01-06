剑指offer 35题

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[10001];
//用两个数组，一个数组保存出现的次数，一个数组按出现的先后顺序保存元素
int number[26] = {0};
char up[26];
int main(void)
{
	while (scanf("%s", str) != EOF)
	{
		memset(number, 0, sizeof(number));
		int index = 0, i;
		for (i = 0; str[i]; ++i)
		{
			if (number[str[i] - 'A'] == 0)
			{
				up[index++] = str[i];
			}
			number[str[i] - 'A']++;
		}
		for (i = 0; i < index; ++i)
		{
			if (number[up[i] - 'A'] == 1)
				break;
		}
		if (i != index)
			printf("%c\n", up[i]);
		else
			printf("-1\n");
	}
	return 0;
}
