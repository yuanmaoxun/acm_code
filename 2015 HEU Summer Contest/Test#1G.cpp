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
    ll num;
    ll fir[200005],sec[200005];
int main(){
    ll i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[105];
    int score[30][10];
    #ifndef ONLINE_JUDGE
        freopen("F://input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    while(~scanf("%lld",&n)) {
        j = k = 0;
        for(i =0; i < n; i++){
            scanf("%lld",&num);
            if(num > 0) fir[j++] = num;
            if(num < 0) sec[k++] = -num;
        }
        ll sumf = 0,sums = 0;
        for(i = 0; i < j; i++)
            sumf += fir[i];
        for(i = 0; i < k; i++)
            sums += sec[i];
        if(sumf > sums)
            cout << "first" << endl;
        else
            if(sumf < sums)
                cout << "second" << endl;
        else{
            for(i = 0;i < min(j,k);i++) {
                if(fir[i] > sec[i]) {
                    cout << "first" << endl;
                    break;
                }
                else if(fir[i] < sec[i]) {
                    cout << "second" << endl;
                    break;
                }
            }
            if(i == min(j,k)) {
            if(i > j) {
                cout << "first" << endl;
                continue;
            }
            if(i < j) {
                cout << "second" << endl;
                continue;
            }
                if(num > 0)
                    cout <<"first" <<endl;
                else
                    cout << "second" << endl;
            }
        }
    }
return 0;
}


