//Ԭï�
#include<bits/stdc++.h>
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
int Mut (int n) {
    ll sum,sum1 = 1,sum2 = 1;
    for(int i = n - n/2 + 1; i <= n; i++)
        sum1 *= i;
    for(int i = n/2; i>=1; i--)
        sum2 *= i;
    sum = sum1/sum2;
return sum;
}
int main(){
    int t, i, j, k, m, n;
    ll sum, res, ans, key, temp;
    int number[10];
    int x[1000],y[1000];
    scanf("%d",&t);
    while(t--){
        cin >> n >> m;
        memset(number,0,sizeof(number));
        for(i = 1; i <= m; i++) {
            cin >> x[i] >> y[i];
            number[x[i]]++;
            number[y[i]]++;
        }
        for(i = 1;i <= n; i++) {
            if(number[i] % 2 != 0||m % 2 != 0) {
                cout << "0" << endl;
                break;
                }
            else {
                int Min = 100000000000;
                for(i = 1; i <= n; i++ )
                    Min = min(Min,number[i]);
                ans = Mut(Min);
                cout << ans << endl;
            }
        }
    }

return 0;
}



