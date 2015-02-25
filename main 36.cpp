//
//  main.cpp
//  PAT1049
//
//  Created by Myh on 2/13/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    long long count[15]={};
    long long N;
    cin>>N;
    long long M=1;
    count[0]=0;
    int i=1;
    while(M<=N){
        count[i]=10*count[i-1]+M;
        i++;
        M*=10;
    }
    M/=10;
    i--;
    int total=0;
    while(N>0){
        long long n=N/M;
        if(n==1)
            total+=N%M+1+n*count[i-1];
        else
            total+=M+n*count[i-1];
        while(M>=10&&N%M/(M/10)==0){
            i--;
            N=N%M;
            M/=10;
        }
        i--;
        N=N%M;
        M/=10;
    }
    cout<<total;
    return 0;
}
