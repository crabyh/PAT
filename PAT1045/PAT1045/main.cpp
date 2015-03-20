//
//  main.cpp
//  PAT1045
//
//  Created by Myh on 2/12/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> color[300];
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin>>N;
    int M;
    cin>>M;
    vector<int> order;
    for(int i=1;i<=M;++i){
        int x;
        cin>>x;
        order.push_back(x);
    }
    int L;
    cin>>L;
    for(int i=1;i<=L;++i){
        int x;
        cin>>x;
        color[x].push_back(i);
    }
    int length=0;
    vector<int> v;
    int seq[11000];
    for(int i=0;i<order.size();++i){
        for(int j=0;j<color[order[i]].size();++j){
            v.push_back(color[order[i]][j]);
            seq[color[order[i]][j]]=(int)v.size();
        }
    }
    int len[11000]={};
    //dynamic programing
    for(int i=1;i<=L;++i){
        if(seq[i]!=0) len[i]=1;//if i is not in the sequence, len[i]=0
        for(int j=1;j<i;j++){
            if(seq[i]>seq[j]&&len[j]+1>len[i]){
                len[i]=len[j]+1;
            }
        }
    }
    for(int i=1;i<=L;++i){
        if(len[i]>length)
            length=len[i];
    }
    cout<<length;
    
    return 0;
}
