#include <stdio.h>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    map <int , vector<int> > mapreduce;
    map <int , vector <int> > ::iterator it;
    int t, n, key, value;
    cin >> t ;
    while(t--){
        mapreduce.clear();
        cin >> n ;
        for(int i = 0; i < n; i++){
            cin >> key >> value;
            mapreduce[key].push_back(value);
        }
        for(it = mapreduce.begin(); it != mapreduce.end(); it++)
            sort((it->second).begin(), (it->second).end());
        for(it = mapreduce.begin(); it != mapreduce.end(); it++){
            cout << it->first ;
            for(int i = 0; i < (it->second).size(); i++)
                cout  <<" "<<(it->second)[i]  ;
            cout <<  endl;
        }
    }

    return 0;
}
