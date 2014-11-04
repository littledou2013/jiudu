#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

/* 
 * 把字符串转换成整数，此题比较简单，一个字符可能为正负符号，其他字符必须全部是数字
 */
int getNum(string str, int i)
{
	int num = 0;
	int size = str.size();
	while (i < size)
	{
		if (str[i] > '9' || str[i] < '0')
			return -1;
		num = num * 10 + (str[i] - '0');
		++i;
	}
	return num;
}
int main(void)
{
	string str;
	while (cin >> str)
	{
		int i = 0;
		int pos = true;
		if (str.size() > 1)
		{
			if (str[0] == '+')
				++i;
			else if (str[0] == '-')
			{
				pos = false;
				++i;
			}
		}
		int num = getNum(str, i);
		if (num >= 0)
			printf("%d\n", pos == true ? num : -num);
		else
			printf("My God\n");
	}
	return 0;
}
