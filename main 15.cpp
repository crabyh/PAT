//
//  main.cpp
//  PAT1059
//
//  Created by Myh on 2/17/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int prime[2000];
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> v;
    int N;
    cin>>N;
    if(N==1){
        cout<<"1=1";
        return 0;
    }
    int n=N;
    int index=0;
    for(int i=2;i<min((int)sqrt(N)+10,5000);++i){
        int flag=1;
        for(int j=2;j<i;++j){
            if(i%j==0)
                flag=0;
        }
        if(flag==1){
            prime[index]=i;
            index++;
        }
    }
    for(int i=0;prime[i]<=n;){
        if(n%prime[i]==0){
            v.push_back(prime[i]);
            n/=prime[i];
        }
        else
            ++i;
    }
    sort(v.begin(),v.end());
    cout<<N<<"="<<v[0];
    for(int i=1;i<v.size();i++){
        if(v[i]==v[i-1]){
            int k=1;
            int m=v[i-1];
            while(v[i]==m&&i<v.size()){
                k++;
                i++;
            }
            cout<<"^"<<k;
        }
        if(i<v.size())
            cout<<"*"<<v[i];
    }
    return 0;
}
