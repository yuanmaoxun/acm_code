//  Ԭï�
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
using namespace std;
int flag[100005];
long long  sum;
int a[100005], r[100005], l[100005];
int main() {
    int i, j, k, m, n;
    int res,  ans ,temp;
    while(~scanf("%d",&n)) {
        sum = 0;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        for(int i = 1; i <= n; i++)
            flag[i] = 0;
        for(i = 1; i <= n; i++) {
             temp = 1;
            for(j = 1; j * j <= a[i]; j++) {
                if(a[i] % j == 0) {
                    temp = max(temp, flag[j] + 1);
                    temp = max(temp, flag[a[i]/j] + 1);
                }
            }
            l[i] = temp;
            flag[a[i]] = i;
        }
        for(int i = 1; i <= n; i++)
            flag[i] = n+1 ;
        for(i = n; i >= 1; i--) {
             temp = n;
            for(j = 1; j * j <= a[i]; j++) {
                if(a[i] % j == 0) {
                    temp = min(temp, flag[j] - 1);
                    temp = min(temp, flag[a[i]/j] - 1);
                }
            }
            r[i] = temp;
            flag[a[i]] = i;
        }
        for(i = 1; i <= n; i++) {
            sum += (i - l[i] + 1) * (r[i] - i + 1);
        }
        cout << sum % 1000000007 << endl;
    }
    return 0;
}
