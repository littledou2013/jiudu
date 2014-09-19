#include <iostream>
#include <cstdio>
#include <cstring> 
using namespace std;
 
const int N = 100001;
char str[N];
int main(void)
{
    int n;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        getchar();
        gets(str);
        int size = strlen(str);
        int i = 0, j = 0;
        bool flag = true;
        //寻找到每个子串的串尾就可以了
        while (j < size)
        {
            if (str[j] == ' ')
            {
                if (flag)
                {
                    flag = false;
                    for (int k = j - 1; k >= i; --k)
                        printf("%c", str[k]);
                    printf(" ");
                    i = j + 1;
                }
                else
                    ++i;
 
            }
            else
                flag = true;
            ++j;
        }
        for (int k = j - 1; k >= i; --k)
                printf("%c", str[k]);
        printf("\n");
    }
    return 0;
}
