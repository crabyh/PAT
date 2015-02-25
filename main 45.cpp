//
//  main.cpp
//  PAT1041
//
//  Created by Myh on 2/12/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin>>N;
    deque<int> q;
    map<int,int> m;
    for(int i=0;i<N;++i){
        int num;
        cin>>num;
        q.push_back(num);
        m[num]++;
    }
    for(int i=0;i<q.size();++i){
        if(m[q[i]]==1){
            cout<<q[i];
            return 0;
        }
    }
    cout<<"None";
    return 0;
}
