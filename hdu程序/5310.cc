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
#define ll  long long
using namespace std;
int main () {
    int i,j,k,m,n,p,q,t;
    int len, res, ans, key, sum, temp;
    int sum1,sum2,sum3;
    while(~scanf("%d",&t)) {
        while(t--){
            cin >> n >> m >> p >> q;
            sum1 = n * p;
            if( n % m != 0 )
                sum2 = ( n / m + 1) * q;
            else
                sum2 = ( n / m ) * q;
            sum3 = (n / m) *q + (n - n / m * m) * p;
            sum = min(sum1,sum2);
            sum = min (sum,sum3);
            cout << sum <<endl;
        }

    }
return 0;
}
