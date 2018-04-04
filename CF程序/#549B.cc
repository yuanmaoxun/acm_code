// #549B.cpp
#include <bits/stdc++.h>
#define LL long long
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define PI 3.1415926535897932626
#define EXIT exit(0);
#define PAUSE system("pause");
#define DEBUG puts("Here is a BUG");
#define SYNC_CLOSE ios::sync_with_stdio(false);
#define what_is(x) cout << #x << " is " << x << endl;
#define CLEAR(name, init) memset(name, init, sizeof(name));
const double eps = 1e-8;
const int MAXN = (int)1e9 + 5;
using namespace std;
int n,a[111][111];
int cnt[111],num[111];
vector<int> ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\Desktop\\ACM\\input.txt", "r", stdin);
#endif
    while(~scanf("%d",&n)){
    	for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%1d",&a[i][j]);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    int flag=1;
    while(flag)
    {
        flag=0;
        for(int i=1;i<=n;i++)
            if(cnt[i]==num[i])
            {
                flag=1;
                ans.push_back(i);
                for(int j=1;j<=n;j++)
                    if(a[i][j])
                        cnt[j]++;
            }
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    }
    return 0;
}