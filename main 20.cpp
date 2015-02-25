//
//  main.cpp
//  PAT1019
//
//  Created by Myh on 2/6/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
int main(int argc, const char * argv[]) {
    long N, b;
    cin >> N >> b;
    deque<long> q;
    while(N/b!=0){
        q.push_front(N%b);
        N/=b;
    }
    q.push_front(N);
    bool flag=1;
    for(int i=0;i<q.size()/2;i++){
        if(q[i]!=q[q.size()-1-i]){
            flag=0;
            break;
        }
    }
    if(flag==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    cout<<q[0];
    for(int i=1;i<q.size();i++) cout<<" "<<q[i];
    return 0;
}
