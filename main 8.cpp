//
//  main.cpp
//  PAT1069
//
//  Created by Myh on 2/24/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dec(int x){
    vector<int> v;
    while(x!=0){
        v.push_back(x%10);
        x/=10;
    }
    while(v.size()<4) v.push_back(0);
    sort(v.begin(),v.end());
    int y=0;
    for(int i=0;i<v.size();++i){
        y=y*10+v[i];
    }
    return y;
}
int inc(int x){
    vector<int> v;
    while(x!=0){
        v.push_back(x%10);
        x/=10;
    }
    while(v.size()<4) v.push_back(0);
    sort(v.begin(),v.end());
    int y=0;
    for(int i=(int)v.size()-1;i>=0;--i){
        y=y*10+v[i];
    }
    return y;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int x;
    cin>>x;
    int d=0;
    int xx=x;
    while(xx!=0){
        xx/=10;
        ++d;
    }
    xx=x;
    vector<int> v;
    while(xx!=0){
        v.push_back(xx%10);
        xx/=10;
    }
    while(v.size()<4) v.push_back(0);
    int flag=1;
    for(int i=1;i<v.size();++i){
        if(v[i]!=v[i-1])
            flag=0;
    }
    int a=inc(x);
    int b=dec(x);
    int c=a-b;
    if(flag==1){
        printf("%04d - %04d = %04d\n",a,b,c);
        return 0;
    }
    while(c!=6174){
        printf("%04d - %04d = %04d\n",a,b,c);
        a=inc(c);
        b=dec(c);
        c=a-b;
    }
    printf("%04d - %04d = %04d\n",a,b,c);
    return 0;
}
