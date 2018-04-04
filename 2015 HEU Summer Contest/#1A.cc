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
using namespace std;
int main(){
    ll i,t,j,k,m,n;
    ll res, sum, ans, key;
    ll number[100005];
        scanf("%lld",&t);
        while(t--){
            scanf("%lld%lld",&n,&k);

            for(i = 0; i < n; i++ )
                 scanf("%lld", &number[i]);

            sort(number,number + n);

            sum = 0;

            for(i = 0; i < n; i++) {
             ll left = i + 1;
             ll right = n - 1;

                while(left <= right) {
                    ll mid = (left + right) / 2;

                    if(number[mid] - number[i] > k)
                        right = mid - 1;
                    else
                        left = mid + 1;
                }

            sum += right - i;
            }

            cout << sum <<endl;
        }
return 0;
}
