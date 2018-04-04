//kengkeng
#include<bits/stdc++.h>
#define Maxn 105
#define Maxm 100005
#define INF 0xffff;
#define ll long long
#define Exit exit(0);
#define Mod 1000000007
#define PI  3.1415926535898
#define Pause system("pause");
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define debug puts("here is a BUG");
#define Clear(name, num) memset(name, num, sizeof(name));
using namespace std;

int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    //char str[Maxn];
    int num[Maxm];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(~scanf("%d",&n)) {
        int flag = 0;
        for(i = 0,k=0; i < n; i++) {
            scanf("%d", &m);
            if(m == 1) {
                flag = 1;
            }
            if(flag == 1) {
                num[k++] = m;
            }
        }
        cout << " k:"<<k << endl;
        sum = k;
        for(i = 1; i < k; i++) {
            if(num[i] == 0 ) {
                sum--;
                continue;
            }
            if(num[i] == 1 && num[i-1] == 0 && num[i-2]!=0) {
                sum ++;
                continue;
            }
        }
        cout << sum << endl;
    }
return 0;
}





