//
//  main.cpp
//  PAT1038
//
//  Created by Myh on 2/12/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;
int compare(string x, string y){
//    for(int i=0;i<min(x.length(),y.length());++i){
//        if (x[i]!=y[i])
//            return x[i]<y[i];
//    }
    return x+y<y+x;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin>>N;
    deque<string> q;
    for(int i=0;i<N;++i){
        string s;
        cin>>s;
        q.push_back(s);
    }
    sort(q.begin(),q.end(),compare);
    int i=0;
    while(q[i].find_first_not_of('0')==-1&&q[i].find('0')!=-1&&i<q.size()){
        ++i;
        if(i==q.size()){
            cout<<"0";
            return 0;
        }
    }
    if(q[i].find_first_not_of('0')!=-1){
        cout<<q[i].substr(q[i].find_first_not_of('0'));
        ++i;
    }
    for(;i<q.size();i++){
//        cout<<"-";
        cout<<q[i];
    }
    return 0;
}
