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
    ll res, sum, sum1, ans, key, len;
    int year, mon, day;
    char String[105];
    int score[30][10];
    ll R,Y,B;
    while(cin >> R >> Y >>B) {
        sum = 0;res = 0;
        if(R > 2) {sum += R - 2; R = 2;}
        if(Y > 2) {sum += Y - 2; Y = 2;}
        if(B > 2) {sum += B - 2; B = 2;}
        sum1 = R + Y + B;
        if(sum1 == 0) ans = 0;
        if(sum1 == 1) ans = 0;
        if(sum1 == 2) ans = 1;
        if(sum1 == 3) ans = 3;
        if(sum1 == 4) ans = 6;
        if(sum1 == 5) ans = 10;
        if(sum1 == 6) ans = 15;
        res = ans + sum1 * sum;
        cout << res << endl;
    }
return 0;
}




