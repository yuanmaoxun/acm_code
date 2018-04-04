
#include <cstdio>
#include <cstring>
char s[200], con[] = "anniversary";

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s);
        int len = strlen(s);
        bool flag = false;
        for(int i = 0; i <= 8; i++)
        {
            for(int j = i + 1; j <= 9; j++)
            {
                int k = 0;
                while(k < len && strncmp(con, s + k, i + 1) != 0)
                    k ++;
                if(k == len)
                    break;
                k += i + 1;
                while(k < len && strncmp(con + i + 1, s + k, j - i) != 0)
                    k ++;
                if(k == len)
                    break;
                k += j - i;
                while(k < len && strncmp(con + j + 1, s + k, 10 - j) != 0)
                    k ++;
                if(k != len)
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
            puts("YES");
        else
            puts("NO");
    }
}
