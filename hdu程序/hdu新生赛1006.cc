
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;


int a[1000005];

int Max;
int b[10000];

void DFS(int n,int i,int len)
{
    if(n%i==0&&n!=1)
    {
        b[len]=i;
        DFS(n/i,i+1,len+1);
    }
    else if(len>Max)
    {
        Max=len;
        for(int j=0; j<Max; j++)
            a[j]=b[j];
    }
}

int main()
{
    int n;
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(scanf("%d",&n)!=EOF)
    {
        Max=0;
        for(int i=2; i*i<=n; i++)
        {
            DFS(n,i,0);
        }
        if(Max == 0)
        {
            Max = 1;
            a[0] = n;
        }
        printf("%d\n",Max);
        printf("%d",a[0]);
        for(int i=1; i<Max; i++)
            printf("*%d",a[i]);

        printf("\n");

    }
    return 0;
}
