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
    int money[1005];
    while(~scanf("%d",&n)) {
        for(i = 1; i<=n; i++)
            cin >> money[i];
            temp = 0;
        for(i = 1;i <= n; i++)
            if(money[i] == 1) {
                temp = 1;
                break;
            }
        if(temp == 1)
            cout << "-1" << endl;
        else
            cout << "1" << endl;

    }
return 0;
}
