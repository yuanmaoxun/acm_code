#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<functional>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;

__int64 qfabs(__int64 n)
{
	if(n<0) return -n;
	return n;
}

__int64 dmap[20][20];

int main()
{
	int nn,ii,i,j,k,m,n;
	__int64 sum,dmax,ans,x,y,a[10],b[10];

	scanf("%d",&nn);
	__int64 l=1e+9+7;
	while(nn--)
	{
		ans=0;
		memset(a,0,sizeof(a));
		memset(dmap,0,sizeof(dmap));
		scanf("%d%d",&m,&n);
		for(i=1;i<=3;i++)
		{
			scanf("%I64d%I64d",&a[i],&b[i]);
			a[i+3]=b[i];
		}

		for(i=1;i<=6;i++)
			for(j=1;j<=6;j++)
			dmap[i][j]=qfabs(a[i]-a[j]);
		for(i=1;i<=3;i++)
			dmap[i][i+3]=dmap[i+3][i]=1;
		for(k=1;k<=6;k++)
			for(i=1;i<=6;i++)
				for(j=1;j<=6;j++)
					if(dmap[i][j]>dmap[i][k]+dmap[k][j]) dmap[i][j]=dmap[i][k]+dmap[k][j];

		for(ii=1;ii<=n;ii++)
		{
			scanf("%I64d%I64d",&x,&y);
			dmax=qfabs(x-y);
			for(i=1;i<=6;i++)
				for(j=1;j<=6;j++)
				{
					sum=qfabs(a[i]-x)+dmap[i][j]+qfabs(a[j]-y);
					if(sum<dmax) dmax=sum;
				}
			ans=(ans+(dmax*ii))%l;
		}

		printf("%I64d\n",ans);
	}

	return 0;
}
