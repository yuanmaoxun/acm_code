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
#define PI  3.1415926535898
#define ll long long
#define inf 0xffff
#define Maxn 50005

using namespace std;
int main(){
    int i,t,j,k,m,n;
    int res, sum, ans, key;
    int number[Maxn];
    int lsum[Maxn],rsum[Maxn];

    scanf("%d",&t);

    while(t--) {

        scanf("%d",&n);

        for(i = 1; i <= n; i++){
            scanf("%d", &number[i]);
        }

        if(n == 2) {
           cout << (number[1] + number[2]) <<endl;
           continue;
        }

        lsum[0] = 0;

        for(i = 1; i <= n; i++)
            if(lsum[i - 1] > 0)
                lsum[i] = lsum[i-1] + number[i];
            else
                lsum[i] = number[i];

        for(i = n ; i > 0; i--)
            if(rsum[i+1] > 0)
                rsum[i] = rsum[i+1] + number[i];
            else
                rsum[i] = number[i];

        for(i = 1; i <= n; i++)
            if(lsum[i] < lsum[i-1])
                lsum[i] = lsum[i-1];

        for(i = n; i > 0; i--)
            if(rsum[i] < rsum[i+1])
                rsum[i] = rsum[i+1];

        res = -inf;

        for(i = 1;i <= n; i++)
            if(res < lsum[i] + rsum[i+1])
                res = lsum[i] + rsum[i+1];

        cout << res << endl;
    }

return 0;
}
