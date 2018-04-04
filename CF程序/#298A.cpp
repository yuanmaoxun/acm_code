#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
int main(){
    int i,j,k,m,n;
    while(~scanf("%d",&n)){
        if(n>4){
                cout << n <<endl;
            cout << "1";
            for(i=3;i<=n;i+=2)
                cout << " " << i;
            for(i=2;i<=n;i+=2)
                cout << " " << i ;
                cout << endl;
        }
        else
           if(n==3){
              cout << "2" << endl;
              cout << "1 3" << endl;
           }
           else if(n==4){
                cout << "4" <<endl;
              cout << "3 1 4 2"<< endl;
              }
        else{
                cout << "1" << endl;
                cout  << "1" << endl;
            }
        }
return 0;
}
