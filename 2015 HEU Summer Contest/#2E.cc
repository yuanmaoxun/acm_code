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
#define Maxn 55
#define debug puts("bug");
using namespace std;
ll s[100005],p[100005],q,flag[100005];
int main(){
    int i, t, j, k, m, n;
    ll res, sum, ans, key, len;
    int year, mon, day;
    char String[105];
    int score[30][10];
    while (cin >> t) {
        while(t--){
            cin >> n >> m;
            for(i = 0;i < n; i++)
                cin >> s[i] >> p[i] ;
            memset(flag, 0, sizeof(flag));
            flag[n - 1] = s[n - 1] * p[n - 1];
            for(i = n - 2; i >= 0; i--) {
                flag[i] = min(flag[i + 1], s[i] * p[i]);
            }
            for(i = 0; i < m; i++) {
                cin >> q ;
                if(q >= s[n - 1])
                    cout << q * p[n - 1] <<endl;
                else {
                    ll temp = upper_bound(s, s + n, q) - s;
                    res = min((q * p[temp - 1]), flag[temp]);
                    cout << res <<endl;
                }
            }
        }
    }
return 0;
}






