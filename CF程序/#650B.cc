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
    int n;
    int num[Maxn];
    int a;
    while(~scanf("%d",&n)) {
        Clear(num,0);
        for(int i = 0; i < n; i++) {
            scanf("%d",&a);
            num[a]++;
        }
        int sum = 1005;
        int res = 0;
        int  k = 0;
        while(sum>1) {
            sum = 0;
            for(int i = 1; i <= 1000;i++){
                if(num[i]>0){
                    num[i]--;
                    sum++;
                }
            }
            if(sum < 1)
                break;
            //cout <<"sum " <<sum <<endl;
            res += (sum-1);
        }
        printf("%d\n",res-k);
    }
return 0;
}





