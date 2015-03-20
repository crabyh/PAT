//
//  main.cpp
//  PAT1042
//
//  Created by Myh on 2/12/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin>>N;
    string a[55];
    for(int i=1;i<=13;++i){
        a[i]="S"+to_string(i);
    }
    for(int i=14;i<=26;++i){
        a[i]="H"+to_string(i-13);
    }
    for(int i=27;i<=39;++i){
        a[i]="C"+to_string(i-26);
    }
    for(int i=40;i<=52;++i){
        a[i]="D"+to_string(i-39);
    }
    a[53]="J1";
    a[54]="J2";
    int b[55]={};
    int x[55]={};
    for(int i=1;i<=54;++i){
        x[i]=i;
        cin>>b[i];
    }
    int y[55]={};
    for(int i=0;i<N;++i){
        for(int j=1;j<=54;++j){
            y[b[j]]=x[j];
        }
        for(int j=1;j<=54;++j){
            x[j]=y[j];
        }
    }
    cout<<a[x[1]];
    for(int j=2;j<=54;++j){
        cout<<" "<<a[x[j]];
    }
    
        
        
        
        
        
        
        
        
        
        
        
        
        
    return 0;
}
