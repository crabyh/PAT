//
//  main.cpp
//  PAT1006
//
//  Created by Myh on 9/28/14.
//  Copyright (c) 2014 myh. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
class C{
public:
    string s;
    int in, out;
};
int main(int argc, const char * argv[])
{
    deque<C> SQ;
    deque<int> sign_in, sign_out;
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        C c;
        c.s=s;
        int hour,min,sec;
        char ch;
        cin>>hour>>ch>>min>>ch>>sec;
        c.in=(hour*3600+min*60+sec);
        cin>>hour>>ch>>min>>ch>>sec;
        c.out=(hour*3600+min*60+sec);
        SQ.push_back(c);
    }
    C c=SQ.front();
    int time=c.in;
    int flag=0;
    for(int i=0;i<N;i++){
        if(SQ[i].in<time){
            time=SQ[i].in;
            flag=i;
        }
    }
    cout<<SQ[flag].s<<" ";
    time=c.out;
    flag=0;
    for(int i=0;i<N;i++){
        if(SQ[i].out>time){
            time=SQ[i].out;
            flag=i;
        }
    }
    cout<<SQ[flag].s;
    
    return 0;
}

