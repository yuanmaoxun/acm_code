//Ԭï�
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
#define ll long long
#define Maxn 105
using namespace std;
int main(){
    int i,t,j,k,m,n;
    int res, sum, ans, key;
    int a,b;
    int num[Maxn][Maxn];
    int flag[Maxn];
    while(~scanf("%d%d",&n,&k)){

        memset(num,0,sizeof(num));
        memset(flag,0,sizeof(flag));

        for(i = 1;i <= n - 1;i++ ) {
            scanf("%d%d",&a,&b);
            flag[a]++;
            num[a][b] = 1;
            for(j = 1; j <= n; j++)
                if(num[j][a] == 1){
                    num[j][b] = 1;
                    flag[j]++;
                }
        }
        res = 0;
        for(i = 1;i <= n;i++)
            if(flag[i] == k){
                res++;
 //               cout << i<< endl;
                }
        cout << res <<endl;

    }
return 0;
}



