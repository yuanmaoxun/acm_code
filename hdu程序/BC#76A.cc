#include<stdio.h>
#include<algorithm>
#define Maxn 1005
#define Maxm 5005
#define INF 0xffff
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
    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int T;
    int n;
    while(~scanf("%d",&T)) {
        while(T--) {
            scanf("%d",&n);
            for(int i = 0; i < n; i++) {
                scanf("%d",&num[i]);
            }
            double x = n*(n-1);
            sort(num,num+n);
            int sum = 0;
            for(int i=0; i <n; i++ ) {
                int temp = num[i];
                for(int j=i+1; j < n; j++) {
                    if(num[j] > temp){
                        sum++;
                    }
                }
            }
            double ans = sum*1.0/x;
            printf("%.6lf\n",ans);
        }
    }
return 0;
}





