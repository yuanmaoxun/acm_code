#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#define INF 0xffff;
#define PI  3.1415926535898
#define ll long long
#define Maxn 105
#define Maxm 500
#define Mod 1000000007
#define Clear(name, num) memset(name, num, sizeof(name));
#define debug puts("here is a BUG");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

int main(){
    int i, t, j, k, m, s, q, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[105];
    int num[5005];
    int score[30][10];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(cin >> t >> s>> q) {
        for(i = 1; s * q < t; i++ ) {
            s = s * q;
        }
        cout << i << endl;
    }
return 0;
}





