/*
 * 
	题目描述：
	在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
	输入：
	输入可能包含多个测试样例，对于每个测试案例，
	输入的第一行为两个整数m和n(1<=m,n<=1000)：代表将要输入的矩阵的行数和列数。
	输入的第二行包括一个整数t(1<=t<=1000000)：代表要查找的数字。
	接下来的m行，每行有n个数，代表题目所给出的m行n列的矩阵(矩阵如题目描述所示，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
	输出：
	对应每个测试案例，
	输出”Yes”代表在二维数组中找到了数字t。
	输出”No”代表在二维数组中没有找到数字t。
 * 此题曾在网易笔试题目中出现过，应聘者分析问题应从一个具体的例子找出其中的规律
 */
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1000;
int arr[N][N];
/*
 * 方法1：逐渐缩小查找范围
 */
//二维矩阵左上角元素坐标为(i1, j1), 右下角元素坐标为(i2 - 1， j2 - 1)
/*bool findT(int i1, int i2, int j1, int j2, int value)
{
	if (arr[i1][j1] > value || arr[i2 - 1][j2 - 1] < value)
		return false;
	int i, j;
	for (i = i1; i < i2; ++i)
	{
		if (value == arr[i][j1])
			return true;
		else if (value < arr[i][j1])
			break;
	}
	for (j = j1; j < j2; ++j)
	{
		if (value == arr[i1][j])
			return true;
		else if (value < arr[i1][j])
			break;
	}
	int p, q;
	for (p = j1; p < j; ++p)
	{
		if (value == arr[i-1][p])
			return true;
		else if (value < arr[i-1][p])
			break;
	}
	for (q = i1; q < i; ++q)
	{
		if (value == arr[q][j-1])
			return true;
		else if (value < arr[q][j-1])
			break;
	}
	//现在的范围缩小到左上角元素为(q, p),右下角元素为（i, j)
	return findT(q, i, p , j, value);
}

int main(void)
{
	int m, n, t;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		scanf("%d", &t);
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
				scanf("%d", &arr[i][j]);
			
		}
		if (findT(0, m, 0, n, t))
			printf("Yes\n");
		else 
			printf("No\n");

	}
	return 0;
}*/

/*
 * 方法二：从中心作为比较点寻找符合条件的块
 */
/*bool findT(int i1, int i2, int j1, int j2, int value)
{
	if (i1 >= i2 || j1 >= j2)
		return false;
	int midi = (i1 + i2) / 2;
	int midj = (j1 + j2) / 2;
	if (arr[midi][midj] == value)
		return true;
	else if (arr[midi][midj] > value)
		return findT(midi, i2, j1, midj, value) || findT(i1, midi, j1, midj, value) || findT(i1, midi, midj, j2, value);
	else
		return findT(midi + 1, i2, j1, midj + 1, value) || findT(midi + 1, i2, midj + 1, j2, value) || findT(i1, midi + 1, midj + 1, j2, value);
}
*/
/*
 * 方法三：逐步剔除的方式
 */
/*
bool findT(int i1, int i2, int j1, int j2, int value)
{
    if (i1 >= i2 || j1 >= j2 || arr[i1][j1] > value || arr[i2 - 1][j2 - 1] < value)
        return false;
    int j;
    for (j = j2 - 1; j >= j1; --j)
    {
        if (arr[i1][j] == value)
            return true;
        else if (arr[i1][j] < value)
            break;
    }
    int i;
    for (i = i1; i < i2; ++i)
    {
        if (arr[i][j] == value)
            return true;
        else if (arr[i][j] > value)
            break;
    }
    return findT(i, i2, j1, j, value);
}
 */
/*
 * 采用非递归方式
 */
bool findT(int rows, int columns, int value)
{
	int r = 0, c = columns - 1;
	bool hasV = false;
	/*while (r < rows && c >= 0)
	{
		while (c >= 0 && arr[r][c] > value)
			--c;
		if (c >= 0 && arr[r][c] == value)
		{
			hasV = true;
			break;
		}
		if (c < 0)
			break;
		while (r < rows && arr[r][c] < value)
			++r;
		if (r < rows && arr[r][c] == value)
		{
			hasV = true;
			break;
		}
		if (r == rows)
			break;
	}*/
	while (r < rows && c >= 0)
	{
		if (arr[r][c] == value)
		{
			hasV = true;
			break;
		}
		else if (arr[r][c] > value)
			--c;
		else 
			++r;
	}
	return hasV;
}
int main(void)
{
    int m, n, t;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        scanf("%d", &t);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
                scanf("%d", &arr[i][j]);
             
        }
        if (findT(m, n, t))
            printf("Yes\n");
        else
            printf("No\n");
 
    }
    return 0;
}
