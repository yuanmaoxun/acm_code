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
int a[6];
int main() {
    int i, t, j, k, m, n;
    int ans, sum, res, key, len;
    int year, mon, day;
    char str[105];
    int num[5005];
    int score[30][10];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    while (scanf("%d", &n) != EOF) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        if (n >= 0 && n <= 3) {
            printf("1024\n");
            continue;
        }
        if (n == 5) {
            res = 0;
            for (i = 0; i < 5; i++)
                for (j = i + 1; j < 5; j++)
                    for (k = j + 1; k < 5; k++)
                        if ((a[i] + a[j] + a[k]) % 1024 == 0) {
                            int temp = sum - a[i] - a[j] - a[k];
                            while (temp > 1024)
                                temp -= 1024;
                            res = temp;
                        }
            cout << res << endl;
            continue;
        }

        if (n == 4) {
            res = 0;
            for ( i = 0; i < 4; i++)
                for ( j = i + 1; j < 4; j++)
                    for ( k = j + 1; k < 4; k++)
                        if ((a[i] + a[j] + a[k]) % 1024 == 0) {
                            res = 1024;
                        }
            if (res > 0) {
                cout << res << endl;
                continue;
            }
            for ( i = 0; i < 4; i++)
                for ( j = i + 1; j < 4; j++) {
                    int temp = a[i] + a[j];
                    while (temp > 1024)temp -= 1024;
                    res = max(temp, res);
                }
            printf("%d\n", res);
        }
    }
    return 0;
}
