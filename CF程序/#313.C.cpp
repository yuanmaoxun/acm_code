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
    int a1,a2,a3,a4,a5,a6;
    scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6);
    sum = a1 + a2 + a3 ;
    sum *= sum;
    sum -= a1 * a1 + a3 * a3 + a5 * a5;
    cout << sum;
return 0;
}

