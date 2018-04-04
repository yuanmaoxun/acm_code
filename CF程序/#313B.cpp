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
int main(){
    int t, i, j, k, m, n;
    int sum, res, ans, key, temp;
    int a1,a2,a3,b1,b2,b3;
    scanf("%d %d",&a1,&b1);
        cin >> a2 >> b2;
        cin >> a3 >> b3;
        temp = 0;
        if((a2 + a3) <= a1 && max(b2,b3) <= b1)
            temp = 1;  //cout << "temp" <<  temp;
        if((a2 + b3) <= a1 && max(b2,a3) <= b1)
            temp = 1;//cout << "temp" <<  temp;
        if((b2 + a3) <= a1 && max(b3,a2) <= b1)
            temp = 1;//cout << "temp" <<  temp;
        if((b2 + b3) <= a1 && max(a3,a2) <= b1)
            temp = 1;//cout << "temp" <<  temp;
        if((a2 + a3) <= b1 && max(b2,b3) <= a1)
            temp = 1;//cout << "temp" <<  temp;
        if((a2 + b3) <= b1 && max(b2,a3) <= a1)
            temp = 1;//cout << "temp" <<  temp;
        if((b2 + a3) <= b1 && max(b3,a2) <= a1)
            temp = 1;//cout << "temp" <<  temp;
        if((b2 + b3) <= b1 && max(a3,a2) <= a1)
            temp = 1;//cout << "temp" <<  temp;
        if(temp == 1)
            cout << "YES" ;
        else
            cout << "NO"  ;

return 0;
}

