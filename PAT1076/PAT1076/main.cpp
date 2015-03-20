//
//  main.cpp
//  PAT1076
//
//  Created by Myh on 2/25/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
#include <vector>
#include <map>
using namespace std;
map<int,vector<int>> m;
int main(int argc, const char * argv[]) {
    // insert code here...
    int N,L;
    cin>>N>>L;
    for(int i=1;i<=N;++i){
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;++j){
            int x;
            scanf("%d",&x);
            if(x!=i){
                m[x].push_back(i);
            }
        }
    }
    int K;
    cin>>K;
    for(int ri=0;ri<K;++ri){
        int known[1100]={};
        int x;
        scanf("%d",&x);
        deque<int> q1,q2;
        int forward=0;
        q1.push_back(x);
        known[x]=1;
        for(int i=0;i<L;++i){
            if(q1.empty()){
                break;
            }
            while(!q1.empty()){
                int cur=q1.front();
                q1.pop_front();
                for(int i=0;i<m[cur].size();++i){
                    if(known[m[cur][i]]==0){
                        q2.push_back(m[cur][i]);
                        ++forward;
                        known[m[cur][i]]=1;
                    }
                }
            }
            q1=q2;
            q2.clear();
        }
        cout<<forward<<endl;
    }
    return 0;
}
