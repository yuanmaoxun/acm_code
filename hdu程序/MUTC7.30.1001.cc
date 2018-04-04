//Ԭï�
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

bool judge(int m) {
    bool f[10];
    memset(f,false,sizeof(f));
    while(m)
    {
        if(f[m % 10] == false) {
            f[m % 10] = true;
            m /= 10;
        }

       else
           return false;
    }
    return true;
}
int main(){
    int i, t, j, k, n;
    int res, sum, ans, key, len;
    int year, mon, day;
    char String[105];
    int score[30][10],num[100005];
    bool flag[10];
    int a,b;
    ans = 0;
    for(i =1; i <= 100005; i++) {
        n = i;
        memset(flag,false,sizeof(flag));
        while(n){
            if( flag[n % 10] == false) {
                flag[ n % 10 ] = true;
                n /= 10;
            }
            else {
                break;
            }
        }
        if( n == 0) ans++;
        num[i] = ans;
    }
//    for(i =1; i <= 20; i++)
//        cout << num[i] << endl;
    while(cin >> t) {
        while(t--) {
            cin >> a >> b;
                if(judge(a))
                    {cout << num[b] - num[a] + 1<< endl;}
                else
                    cout << num[b] - num[a] << endl;
        }
    }
return 0;
}







