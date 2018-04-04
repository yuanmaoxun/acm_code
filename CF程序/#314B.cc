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
int flag[1000005];
int main() {
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[105];
    int num[5005];
    int score[30][10];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int ai[105], mi[105];
    res = 0;sum = 0;
    scanf("%d", &n);
    memset(flag, 0, sizeof(flag));
    for (i = 0; i < n; i++) {
        scanf("%s %d", str, &m);
        if (str[0] == '+') {         //正常进出
            flag[m] = 1;
            sum++;
            res = max(sum, res);
        }
        else {
            if (flag[m]){
                flag[m] = 0;
                sum--;
            }                        //正常进出
            else
                res++;               //一直在的人，特殊处理
        }
    }

    cout << res << endl;
    return 0;
}





