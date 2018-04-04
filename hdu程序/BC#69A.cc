#include <stdio.h>
#include <string.h>


int main()
{
    int i, j, T, a, b, C, i0, j0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &a, &b, &C);
        if(C % 2 == 0)
        {
            i0 = j0 = 1005;
            for(i = 0; i <= 1000; i++)
                for(j = 0; j <= 1000; j++)
                    if((i * a + j * b == C / 2) && (i + j < i0 + j0)) { i0 = i; j0 = j; }
            if((i0 == 1005) && (j0 == 1005)) printf("Impossible\n");
            else printf("%d %d\n", i0 * 2, j0 * 2);
        }
        else printf("Impossible\n");
    }
    return 0;
}
