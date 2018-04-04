#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,dis[55][55],a[110],dp[110][55];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
			scanf("%d",&dis[i][j]);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(a[1]!=-1)
			dp[1][a[1]]=0;
		else
			for(int i=1;i<=m;i++)
				dp[1][i]=0;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(dp[i-1][j]!=-1)
				{

					if(a[i]!=-1)
						dp[i][a[i]]=max(dp[i][a[i]],dp[i-1][j]+dis[j][a[i]]);
					else
						for(int k=1;k<=m;k++)
							dp[i][k]=max(dp[i][k],dp[i-1][j]+dis[j][k]);
				}
			}
		}
		int ans=-INF;
		for(int i=1;i<=m;i++)
			ans=max(ans,dp[n][i]);
		printf("%d\n",ans);

	}
    return 0;
}
