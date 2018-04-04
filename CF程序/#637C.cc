//kengkeng
#include<bits/stdc++.h>
#define Maxn 100005
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
//    int num[Maxn];
#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int n;
    char key[Maxn][10];
    while(~scanf("%d",&n)) {
        for(int i = 0; i < n; i++){
            scanf("%s",key[i]);
        }
        int ans = 6;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int temp = 0;
                for(int k = 0; k < 6; k++){
                    if(key[i][k] != key[j][k]){
                        temp ++;
                    }
                }
                ans = min(ans,(temp-1)/2);
            }
        }
        printf("%d\n",ans);
    }
return 0;
}




