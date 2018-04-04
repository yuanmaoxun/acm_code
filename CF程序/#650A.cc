//kengkeng
#include<bits/stdc++.h>
#define Maxn 100005
#define Maxm 5005
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

int main() {
//    char str[Maxn];
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int T;
    int n,m;
    while(~scanf("%d %d",&n,&m)) {
        int ans = 0;
        if(n == 1 && m== 1){
            printf("0\n");
           continue;
        }
        while(n>0 && m>0) {
            if(n > m) {
                n=n-2;
                m++;
                ans++;
            }
            else{
                m = m-2;
                n++;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
return 0;
}





