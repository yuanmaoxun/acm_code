//kengkeng
#include<stdio.h>
#include<queue>
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

long long  bfs(long long n) {
    queue<long long > Q;
    Q.push(1);
    while(!Q.empty()) {
        long long ans = Q.front();
        Q.pop();
        if(ans % n==0){
            printf("%lld\n",ans);
            return ans;

        }

        Q.push(ans*10);
        Q.push(ans*10+1);
    }
}

int main(){
//    char str[Maxn];
//    int num[Maxn];

   long long int n;
    while(~scanf("%lld",&n)&&n) {
        long long res = bfs(n);
    }
return 0;
}




