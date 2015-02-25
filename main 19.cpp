//
//  main.cpp
//  PAT1064
//
//  Created by Myh on 2/23/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <math.h>
using namespace std;
vector<int> v;
int l_c[2000],r_c[2000];
int tree(int left,int right){
    if(left==right){
        return left;
    }
    if(left+1==right){
        l_c[right]=left;
        return right;
    }
    int hight=(int)(log(right-left+1)/log(2));
    int bottom=right-left+1-(int)pow(2,hight)+1;
    int num_l;
    if(bottom<=(int)pow(2,hight-1)){
        num_l=bottom+(int)pow(2, hight-1)-1;
    }
    else{
        num_l=(int)pow(2,hight)-1;
    }
    int root=num_l+left;
    if(left!=root)
        l_c[root]=tree(left, num_l+left-1);
    if(right!=root)
        r_c[root]=tree(num_l+left+1, right);
    return num_l+left;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    for(int i=0;i<2000;++i){
        l_c[i]=r_c[i]=-1;
    }
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    deque<int>q;
    int root=tree(0,(int)v.size()-1);
    q.push_back(root);
    cout<<v[root];
    while(!q.empty()){
        int x=q.front();
        q.pop_front();
        if(l_c[x]!=-1){
            q.push_back(l_c[x]);
        }
        if(r_c[x]!=-1){
            q.push_back(r_c[x]);
        }
        if(x!=root)
            cout<<" "<<v[x];
    }
    return 0;
}
