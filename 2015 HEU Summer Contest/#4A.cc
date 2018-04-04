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
    int i, t, j, k, m, n;
    int res, sum, ans, key, cnt;
    int year, mon, day;
    char str[1005][505];
    int num[5005];
    int score[30][10];
    int l[1005], r[1005], len[1005];
    unsigned int hash[1010], ha = 137;
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    hash[0] = 1;
    for(i = 1; i < 1010; i++)
        hash[i] = hash[i - 1] * ha;
    scanf("%d",&t);
    for(cnt = 1; cnt <= t; cnt++ ){
        cin >> n;
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        for(i = 0; i < n; i++) {
            scanf("%s", str[i]);
            len[i] = strlen(str[i]);
        }
        for( i = 0; i < n; i++) {
            for(j = 0; j < len[i]; j++){
                l[i] +=(int)(str[i][j] - 'a') * hash[j];
                r[i] += (int)(str[i][len[i]-j-1] - 'a') * hash[j];
            }
        }
        res = 0;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(i == j) continue;
                if(l[i] + l[j] * hash[len[i]] == r[j] + r[i] * hash[len[j]])
                    res++;
            }
        }
        printf("Case #%d: %d\n", cnt, res);
    }
return 0;
}


