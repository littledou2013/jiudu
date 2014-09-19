#include <stdio.h>
//使用C语言
int main(void)
{
	int h, m;
	double h_place;
	while (scanf("%d:%d", &h, &m) != EOF)
	{
		h_place = (h % 12) * 5 + m / 60.0 * 5;
		h_place = (h_place > m ? h_place - m : m - h_place);
		if (h_place > 30)
			h_place = 60 - h_place;
		printf("%.02f\n", h_place * 180.0 / 30);
	}
	return 0;
}
