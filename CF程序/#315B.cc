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
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[105];
    int num[10005];
    int temp[10005];
    int score[30][10];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int flag[10005];
    while(~scanf("%d",&n)) {
        Clear(flag, 0);
        for(i = 0; i < n; i++) {
            cin >> num[i];
            flag[num[i]]++;
        }
        sort(temp, temp + n);
        for(i = 0; i < n; i++) {
            if(temp[i] == i + 1)
                continue;
            else{
                for(j = i; j < n; j++)

            }
        }
    }
return 0;
}





