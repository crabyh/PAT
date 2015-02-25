//
//  main.cpp
//  PAT1056
//
//  Created by Myh on 2/15/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
class M{
public:
    int no;
    int weight;
    int order;
    int rank;
};
int compare1(M x,M y){
    return x.no<y.no;
}
int compare2(M* x,M* y){
    return x->weight>y->weight;
}
int compare3(M x,M y){
    return x.order<y.order;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int N,n;
    cin>>N>>n;
    vector<M> v;
    for(int i=0;i<N;++i){
        M m;
        m.no=i;
        cin>>m.weight;
        v.push_back(m);
    }
    for(int i=0;i<N;++i){
        int x;
        cin>>x;
        v[x].order=i;
    }
    sort(v.begin(), v.end(), compare3);
    deque<M*> q1,q2,tmp;
    for(int i=0;i<v.size();i++){
        q1.push_back(&v[i]);
    }
    while(q1.size()>1){
        for(int i=0;i<q1.size();i++){
            tmp.push_back(q1[i]);
            if(tmp.size()==n||i==q1.size()-1){
                sort(tmp.begin(),tmp.end(),compare2);
                q2.push_back(tmp[0]);
                tmp.clear();
            }
        }
        for(int i=0;i<q1.size();i++){
            q1[i]->rank=(int)q2.size()+1;
        }
        q1=q2;
        q2.clear();
    }
    q1[0]->rank=1;
    sort(v.begin(), v.end(), compare1);
    cout<<v[0].rank;
    for(int i=1;i<v.size();++i){
        cout<<" "<<v[i].rank;
    }

    
    
    
    
    
    return 0;
    
    
    
}
