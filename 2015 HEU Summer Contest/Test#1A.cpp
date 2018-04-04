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
struct schoolship{
    ll scr;
    ll num;
}van[100005];
int comp(schoolship a, schoolship b) {
    return a.num < b.num;
}
int main() {
    ll i, t, j, k, m, n, r, l;
    ll res, sum, ans, key, len;
    int year, mon, day;
    char str[105];
    int num[5005];
    int score[30][10];
    ll avg;
    #ifndef ONLINE_JUDGE
        freopen("F://input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    while(~scanf("%lld%lld%lld",&n,&r,&avg)) {
        sum = 0; res = 0;
        for(i = 0; i < n; i++) {
            scanf("%d%d", &van[i].scr, &van[i].num);
            sum += van[i].scr;
        }
  //      cout << sum <<endl;
        if(sum  >= avg * n)
            {cout << "0" << endl;continue;}
        else {
            sort(van, van + n, comp);
            ll sum1 = n * avg - sum;
            ll k = 0;
           // for(i = 0; i < n; i++ )
             //  cout << van[i].scr << endl;
            // cout <<sum << " " << avg * n <<endl;
            for(i = 0; i < n && k < sum1; i++){
                if(van[i].scr < r){
                    int num1 = min(r - van[i].scr, sum1 - k);
                    res += num1 * van[i].num;
                    van[i].scr += num1;
                    k += num1;
                }
          // cout << res <<endl;
            }
        }
        printf("%lld\n", res);
    }
return 0;
}






