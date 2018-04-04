#include<bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#define PI  3.1415926535898
using namespace std;
int main() {
    int i,j,k,m,n;
    int l,r,Max;
    int a[100005],flag[1000005];
    while(~scanf("%d",&n)) {
        memset(flag, 0, sizeof(flag));
        for(i = 1; i <= n; i++) {
            cin >> a[i];
            flag[a[i]]++;
        }
        Max = 0;
        l = 100001; r = 0;
        for(i = 1; i <= n; i++) {
            Max = max(Max, flag[i]);
        }
        for(i = 1; i <= n; i++)
            if( Max == flag[i] )
                for(j = 1; j <= n; j++)
                    if ( a[j] == i ) {
                        l = min(j, l);
                        r = max(j, r);
                    }
    }
return 0;
}
