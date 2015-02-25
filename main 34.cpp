//
//  main.cpp
//  PAT1048
//
//  Created by Myh on 2/13/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> coin;
short have[1100]={};
int main(int argc, const char * argv[]) {
    // insert code here...
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;++i){
        int x;
        cin>>x;
        coin.push_back(x);
        have[x]++;
    }
    sort(coin.begin(),coin.end());
    int i;
    int flag=0;
    for(i=0;i<N;++i){
        if(have[M-coin[i]]>=1){
            flag=1;
            break;
        }
    }
    if(M-coin[i]==coin[i]&&have[coin[i]]<2)
        flag=0;
    if(flag==1)
        cout<<coin[i]<<" "<<M-coin[i];
    else
        cout<<"No Solution";
    return 0;
}
