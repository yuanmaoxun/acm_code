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
#define Maxn 55
#define debug puts("bug");
using namespace std;
int main(){
    int i, t, j, k, m, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char str[105];
    int score[30][10];
    int num[500010];
    int *p,*q;
    while(~scanf("%d",&n)) {
        for(i = 0; i < n; i++) {
            cin >> num[i];
        }
        sort(num, num + n);
        int mid = n / 2;
        for(p = num + mid - 1,q = num + n -1;p >= num;) {
            if(*q >= 2*(*p)) {
                p--;
                q--;
            }
            else {
                p--;
            }
        }
        cout << q - num + 1 << endl;
    }
return 0;
}





