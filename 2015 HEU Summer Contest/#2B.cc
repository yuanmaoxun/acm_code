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
ll solve(ll m, ll n ) {
    if(n == 0) return 0;
    if(m == n) return 1;
    if(m < n)  {
        ll temp = m;
        m = n;
        n = temp;
    }
    return m / n + solve(n,m % n);
}
int main(){
    int i, t, j, k, m, n;
    ll res, sum, ans, key, len;
    ll a,b;
    char String[105];
    int score[30][10];
    while(cin >> a >> b) {
        res = solve(a,b);
        cout << res << endl;
    }
return 0;
}












