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
int AI[10010];
double beat[150][150], dp[10010][150];
int main() {
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char String[105];
    int score[30][10];

    while(~scanf("%d", &m)) {
        memset(AI, 0, sizeof(AI));
        memset(dp, 0.0, sizeof(dp));
        m = m * (m - 1) * (m - 2) / 6;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                scanf("%lf", &beat[i][j]);
            }
        }

        scanf("%d", &n);

        for(int i = n; i > 0; i--)
            scanf("%d", &AI[i]);
       for(int i = 0; i < 150; i++) {  //³õÊ¼»¯
            dp[0][i] = 1.0;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < m; j++) {
                if(dp[i - 1][j] > dp[i - 1][AI[i]])
                    dp[i][j] = beat[j][AI[i]] * dp[i - 1][j];
                else
                    dp[i][j] = beat[j][AI[i]] * dp[i - 1][AI[i]];
            }
        }
        double ans = -1.0;

        for(int i = 0; i < m; i++) {
            if(ans < dp[n][i])
                ans = dp[n][i];
        }
        printf("%lf\n", ans);
    }
    return 0;
}
