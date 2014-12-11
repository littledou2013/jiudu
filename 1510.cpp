/*
 * 在网络编程中，如果URL参数中含有特殊字符，如空格、‘#’等，可能导致服务器端无法获得正确的参数值，需要将这些特殊符号转换成服务器可以识别的字符
 * 转换规则是在'%'后面跟上ASCII码的两位十六进制的表示
 * 一种是在原来的字符串上做替换，
 */

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
/*
 * 方法一：仅仅是输出了结果并没有存储结果
 */
/*int main(void)
{
	string str;
	getline(cin, str);
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == ' ')
		//	printf("%20");如果这样输出，则会没有输出
			printf("%%20");
		else
			printf("%c", str[i]);
	}
	printf("\n");
	return 0;
}*/

void replaceS(string &str)
{
	int size = str.size();
	int count = 0;
	for (int i = 0; i < size; ++i)
	{
		if (str[i] == ' ')
			++count;
	}
	int length = size + count * 2;
	str.resize(length);
	--length;
	//for (int i = size - 1; i >= 0; --i) 优化此句
	for(int i = size - 1; i != length; --i)
	{
		if (str[i] == ' ')
		{
			str[length--] = '0';
			str[length--] = '2';
			str[length--] = '%';
		}
		else
			str[length--] = str[i];
	}
	
}
int main(void)
{
	string str;
	getline(cin, str);
	replaceS(str);
	for (int i = 0; i < str.size(); ++i)
		printf("%c", str[i]);
	printf("\n");
	return 0;
}
