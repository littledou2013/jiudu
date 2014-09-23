#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100000;
int a[N];
int b[N];
long long int calCount(int v, int m, int n)
{
	int max, min, mid;
	long long count = 0;
	/*
	  计算a数组中每一个数与b数组中相加小于或等于v的个数
	  对于a数组中的a[i]元素，计算a[i]与b中最小元素b[0]和最大元素b[n-1]之后，
	  如果a[i] + b[0] < v说明a[i]元素与b中的所有元素相加都会大于v，并且a[i]之后的元素与b中的所有元素相加更会大于v，所以可以break直接返回count;
	  如果a[i] + b[n-1] >= v说明a[i]元素与b中所有元素相加都会小于等于v，那么这些n个元素都可以加到count；
	  如果v处于a[i] + b[0] 和a[i] + b[n-1]中间值，则需要计算这n个数有多少个数是小于或等于v的，因为是有序，可以采用二分查找的方法
	  int min = 0, max = n - 1, mid; min和max标志的是下标
	  while (min <= max)
	  {
		mid = (min + max) / 2;
		if v大，则max = min - 1;
		if v小，则min = mid + 1;
		if v等于，则min = mid + 1;//可能mid + 1也刚好等于v，等于v的也需要计算进来
	  }
	  先需判断b[min] + a[i]是否和v一样大，如果一样大那么count会多加1
	*/
	for (int i = 0; i < m; ++i)
	{
		min = a[i] + b[0];
		max = a[i] + b[n - 1];
		if (v < min)
			break;
		if (v >= max)
		{
			count += n;
			continue;
		}
		min = 0; max = n - 1;
		while (min <= max)
		{
			mid = (min + max) / 2;
			if (v < a[i] + b[mid]) 
				max = mid - 1;
			else 
				min = mid + 1;
		}
		if (a[i] + b[min] == v) 
			++min;
		count += min;
	}
	return count;
}
//calCount1比calCount的效率高
long long int calCount1(int v, int m, int n)
{
	int max, min, mid, j = n - 1;
	long long count = 0;
	/*
	  使用贪心算法比使用二分查找快，这个贪心算法的策略需要认真理解
	  初始条件, j指向b数组的最后一个元素的下标
	  当i = 0时，如果a[i] 和所有的b[j] 是小于等于v的，内部循环结束，如果a[i] + b[j] > v，那么寻找倒数最后一个大于或者等于v的j值，假设这个j = t的话，
	  那么对于i = 1的a[i] + b[k+1 ……n - 1]的值都是大于v的不需要在去遍历这些值了，我们只需要遍历a[i] + b[0……k]，求出倒数最后一个大于或者等于v的k值
	  依次类推直到j < 0。
	*/
	for (int  i = 0; i < m; ++i)
	{
		while (j >= 0 && a[i] + b[j] > v) --j;
		if (j < 0) break;
		count += j + 1;
	}
	return count;
}

long long int calCount(int v, int m, int n)
{
	int max, min, mid, j = n - 1;
	long long count = 0;
	/*
	  使用贪心算法比使用二分查找快，这个贪心算法的策略需要认真理解
	  初始条件, j指向b数组的最后一个元素的下标
	  当i = 0时，如果a[i] 和所有的b[j] 是小于等于v的，内部循环结束，如果a[i] + b[j] > v，那么寻找倒数最后一个大于或者等于v的j值，假设这个j = t的话，
	  那么对于i = 1的a[i] + b[k+1 ……n - 1]的值都是大于v的不需要在去遍历这些值了，我们只需要遍历a[i] + b[0……k]，求出倒数最后一个大于或者等于v的k值
	  依次类推直到j < 0。
	*/
	for (int  i = 0; i < m; ++i)
	{
		while (j >= 0 && a[i] + b[j] > v) --j;
		if (j < 0) break;
		count += j + 1;
	}
	return count;
}

int findK(int min, int max, long long int k, int m, int n)
{
	/*
		二分查找法：
		1、求min和max的中间值mid
		2、求在数组中小于或等于mid值的个数calCount(mid)
		3、calCount(mid)的值与k进行比较，分为三种情况
		--calCount(mid) > k
		  第k大的值小于mid，则继续二分查找min和mid - 1区间
		--calCount(mid) < k
		  第k大的值大于mid，则继续二分查找mid + 1和max区间
		--calCount(mid) == k
		  是max = mid - 1，其实这里有些难于理解的，这个时候也分为两种情况
		  一种是mid这个值在数组中不存在刚好比第k个值大；
		  一种是mid这个值在数组中存在并且刚好就是第k个值。
		  对于mid这个值在数组中存在的情况，使用max = mid - 1和使用min = mid + 1都是来看一下是否都合理，
		  比如使用max = mid - 1，因为mid是第k大的值，那么对于重新更新的mid = (min + max) / 2所处位置肯定比k小,接下来If条件都是calCount(mid) < k
		  在此条件下会更新min = mid + 1,直到min比max多1刚好回到第k大的值。
		  如果在等于条件下使用min = max + 1, 因为mid是第k大的值，那么对于重新更新的mid = (min + max) / 2所处位置肯定比k大,接下来If条件都是可能calCount(mid) == k
		  也可能calCount(mid） > k,从这里可以看出使用max = mid - 1合理。
		  对于mid这个值在数组中不存也需要使用max = mid - 1,各位在自己补脑一下吧
	*/
	int mid;
	while (min <= max)
	{
		mid = ((long long int)min + (long long int)max) / 2;
		if (calCount(mid, m, n) >= k)
			max = mid - 1;
		else 
			min = mid + 1;
	}
	return min;
}
int main(void)
{
	int m, n;
	long long int k;
	while (scanf("%d%d%lld", &m, &n, &k)!= EOF)
	{
		for (int i = 0; i < m; ++i)
			scanf("%d", &a[i]);
		sort(a, a + m);
		for (int i = 0; i < n; ++i)
			scanf("%d", &b[i]);
		sort(b, b + n);
		printf("%d\n", findK(a[0] + b[0], a[m - 1] + b[n - 1], k, m, n));
	}
	return 0;
}
