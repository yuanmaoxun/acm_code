
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
#define INF 0xffff;
#define PI  3.1415926535898
#define ll long long
#define Maxn 5005
#define debug puts("here is a BUG");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

int main(){
    int i, t, j, k, m, n, l;
    double res, sum, ans, key, len;
    int year, mon, day;
    char str[105];
    int num[5005];
    int score[30][10];
    #ifndef ONLINE_JUDGE
        freopen("F://input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    while(~scanf("%d%d",&n, &l)) {
        res = -INF;
        for(i = 0;i < n; i++){
            cin >> num[i];
        }
        sort(num, num + n);
        for(i = 1; i < n; i++) {
            res = max(res, 1.0*(num[i] - num[i - 1]) / 2);
         //cout << res << endl;
        }
       if(num[0] != 0)
            res = max(res, 1.0*(num[0] - 0));
       if(num[n - 1] != l)
            res =  max(res, 1.0*(l - num[n - 1]));
       printf("%.9lf\n",res);
    }
return 0;
}





