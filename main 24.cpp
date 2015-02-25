//
//  main.cpp
//  PAT1024
//
//  Created by Myh on 2/8/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
deque<int> x,y;

void f(){
    int digit,carrier=0;
    for(int i=0;i<x.size();i++){
        digit=x[i]+x[x.size()-1-i]+carrier;
        if(digit>=10){
            digit-=10;
            carrier=1;
        }
        else carrier=0;
        y.push_front(digit);
    }
    if(carrier==1)
        y.push_front(carrier);
    x=y;
    y.clear();
}

bool is(){
    for(int i=0;i<x.size()/2;i++){
        if(x[i]!=x[x.size()-1-i])
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    long N;
    int K;
    cin>>N>>K;
    if(N==0){
        cout<<0<<endl<<0;
        return 0;
    }
    while(N!=0){
        x.push_front(N%10);
        N/=10;
    }
    int k;
    for(k=0;k<K;k++){
        if(is()==true){
            break;
        }
        f();
    }
    if(k>K)k=K;
    for(int i=0;i<x.size();i++)
        cout<<x[i];
    cout<<endl<<k<<endl;
    
    return 0;
}













