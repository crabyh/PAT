//
//  main.cpp
//  PAT1077
//
//  Created by Myh on 2/25/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
string LCS(string x,string y){
    int a[300]={};
    string res;
    for(int i=0;i<x.length();++i){
        for(int j=(int)y.length();j>0;--j){
            if(x[i]==y[j]){
                a[j]=a[j-1]+1;
            }
            else{
                a[j]=0;
            }
        }
        a[0]=x[i]==y[0]?1:0;
    }
    int max=0;
    int i;
    for(i=0;i<y.length();++i){
        if(a[i]>max){
            max=a[i];
        }
    }
    res=y.substr(i-max,max);
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin>>N;
    string lcs;
    int flag=0;
    getline(cin,lcs);
    for(int i=0;i<N;++i){
        string s;
        getline(cin,s);
        if(flag==0){
            flag=1;
            lcs=s;
        }
        else{
            lcs=LCS(s,lcs);
        }
    }
    if(lcs.length()>0){
        cout<<lcs;
    }
    else{
        cout<<"nai";
    }
    return 0;
}
