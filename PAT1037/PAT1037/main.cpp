//
//  main.cpp
//  PAT1037
//
//  Created by Myh on 2/12/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int compare(int x,int y){
    return x>y;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    deque<int> c1, c2, p1, p2;
    int NC, NP;
    cin>>NC;
    for(int i=0;i<NC;++i){
        int x;
        cin>>x;
        if(x>0)
            c1.push_back(x);
        else
            c2.push_back(-x);
    }
    cin>>NP;
    for(int i=0;i<NP;++i){
        int x;
        cin>>x;
        if(x>0)
            p1.push_back(x);
        else
            p2.push_back(-x);
    }
    sort(c1.begin(),c1.end(),compare);
    sort(c2.begin(),c2.end(),compare);
    sort(p1.begin(),p1.end(),compare);
    sort(p2.begin(),p2.end(),compare);
    long long sum=0;
    for(int i=0;i<min(c1.size(),p1.size());++i){
        sum+=c1[i]*p1[i];
    }
    for(int i=0;i<min(c2.size(),p2.size());++i){
        sum+=c2[i]*p2[i];
    }
    cout<<sum<<endl;
    return 0;
}
