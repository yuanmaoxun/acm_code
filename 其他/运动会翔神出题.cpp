#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
int Cin[1000005],a[1000005],b[1000005];
int main() {
    int i, j, k, n, m;
    long long ans, key, res;
    while(cin >>  n){
        cin >> Cin[0];
        ans = Cin[0];
        for(i = 1; i < n; i++) {
            cin >> Cin[i];
            ans ^= Cin[i];
        }
        long long  x = 0;
        while(1) {
            key = ans & (1 << (x++));
            //cout << key <<endl;
            if(key)
                break;
          }
          //cout << "x为" << x <<" key为"<< key <<endl;
        j = 0;k = 0;
        --x;
        for(i = 0; i < n; i++) {
            if(Cin[i] & (1 << x))
                a[j++] = Cin[i];
            else
                b[k++] = Cin[i];
        }
    /*for(i = 0; i < j; i++)
         cout << "a数组"<<a[i] << " " <<endl;
      for(i=0;i<k;i++)
         cout << "b数组"<<b[i] << " " <<endl;
    */
        res = a[0];
        for(i = 1; i < j; i++)
            res ^= a[i];
        cout << res << endl;
            res = b[0];
        for(i = 1; i < k; i++)
            res ^= b[i];
        cout << res << endl;
    }
return 0;
}
