//
//  main.cpp
//  PAT1068
//
//  Created by Myh on 2/24/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a[200]={};
vector<int> res;
vector<int> v;
int N, M;
int compare(vector<int> x,vector<int> y){
    for(int i=0;i<min(x.size(),y.size());++i){
        if(x[i]!=y[i]){
            return x[i]<y[i];
        }
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cin>>N>>M;
    for(int i=0;i<N;++i){
        int x;
        scanf("%d",&x);
        if(x<=M)
            v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i){
        for(int j=M;j>=0;--j){
            if(a[j].size()!=0&&j+v[i]<=M){
                vector<int> vec;
                for(int k=0;k<a[j].size();++k){
                    vec.push_back(a[j][k]);
                }
                vec.push_back(v[i]);
                if(compare(vec,a[j+v[i]])==1){
                    a[j+v[i]]=vec;
                }
            }
        }
        if(a[v[i]].size()==0){
            a[v[i]].push_back(v[i]);
        }
    }
    if(a[M].size()==0){
        cout<<"No Solution";
    }
    else{
        cout<<a[M][0];
        for(int i=1;i<a[M].size();++i){
            cout<<" "<<a[M][i];
        }
    }
    return 0;
}
