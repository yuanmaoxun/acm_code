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
#define Maxn 15
#define Maxm 15
#define Mod 1000000007
#define debug puts("here is a BUG");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

struct fag {
    int index;
    int num;
} lack[Maxn];

bool comp(fag a, fag b) {
    return a.num > b.num;
}

int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[105];
    int num[5005];
    int score[30][10];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int edge[Maxn][Maxm];
    bool flag;
    scanf("%d", &t);
    while(t--) {
        scanf("%d",&n);
        flag = true;
        memset(edge, 0, sizeof(edge));
        for(i = 0; i < n; i++){
            scanf("%d", &lack[i].num);
            lack[i].index = i;
        }

        for(i = 0; i < n && flag; i++) {
            sort(lack, lack + n, comp);
            if(lack[i].num > n-i-1) {
                flag = false;
            }

            for(j = i+1; j < i+1+lack[i].num && flag; j++) {
                if(lack[j].num <= 0)
                    flag = 0;
                lack[j].num--;
                edge[lack[i].index][lack[j].index] = edge[lack[j].index][lack[i].index] = 1;
            }
        }
        if(flag) {
            cout << "YES" << endl;
            for(i = 0; i < n; i++)
                for(j = 0; j < n; j++) {
                    if(j == n - 1)
                        cout << edge[i][j] << endl;
                    else
                        cout << edge[i][j] << " ";
                }
            if(t != 0) cout << endl;
        }
        else {
            cout << "NO" <<endl;
            if(t != 0) cout << endl;
        }

    }
return 0;
}






