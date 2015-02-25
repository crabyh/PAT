//
//  main.cpp
//  PAT1063
//
//  Created by Myh on 2/23/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<map<int,int>> v;
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        int n;
        scanf("%d",&n);
        map<int,int> m;
        for(int j=0;j<n;++j){
            int x;
            scanf("%d",&x);
            m[x]=1;
        }
        v.push_back(m);
    }
    int K;
    cin>>K;
    for(int i=0;i<K;++i){
        int x,y;
        cin>>x>>y;
        x-=1;
        y-=1;
        map<int,int> m, mm;
        int same=0 ,diff=0;
        map<int,int>::iterator it;
        diff=(int)v[x].size();
        for(it=v[y].begin();it!=v[y].end();++it){
            if(!v[x].count(it->first)){
                ++diff;
            }
            else if(!mm.count(it->first)){
                ++same;
                mm[it->first]=it->second;
            }
        }
        printf("%.1lf%%\n",same/(double)diff*100);
//        cout<<setiosflags(ios::fixed)<<setprecision(1)<<same/(double)diff*100<<"%"<<endl;
    }
    return 0;
}
