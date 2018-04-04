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
    int i,t,j,k,m,n;
    int res, sum, ans, key;
    int Array[35][35];
    int Array1[35][35],Array2[35][35],Array3[35][35],Array4[35][35];
    while(~scanf("%d",&n)) {
        if(n == 0) break;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++) {
               scanf("%d",&Array[i][j]);}
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++){
                scanf("%d",&Array1[i][j]);}
        for( i = 0; i < n; i++)
           for( j = 0; j < n; j++)
               Array2[i][j] = Array1[j][n - i - 1];
        for( i = 0; i < n; i++)
           for( j = 0; j < n; j++)
               Array3[i][j] = Array2[j][n - i - 1];
        for( i = 0; i < n; i++)
           for( j = 0; j < n; j++)
               Array4[i][j] = Array3[j][n - i - 1];
        int res1 = 0,res2 = 0,res3 = 0,res4 =0;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++) {
                if(Array1[i][j] == Array[i][j]) res1++;
                if(Array2[i][j] == Array[i][j]) res2++;
                if(Array3[i][j] == Array[i][j]) res3++;
                if(Array4[i][j] == Array[i][j]) res4++;
            }
        res = 0;
        res = max(res,res1);
        res = max(res,res2);
        res = max(res,res3);
        res = max(res,res4);
        cout << res <<endl;
    }
return 0;
}
