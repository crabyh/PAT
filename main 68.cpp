//
//  main.cpp
//  PAT1015
//
//  Created by Myh on 10/15/14.
//  Copyright (c) 2014 Myh. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int reverse(int num, int radix){
    string s="";
    int n=1;
    while(num>0){
        s+=num%radix;
        num/=radix;
        n++;
    }
    int new_num=0;
    for(int i=0;i<n;i++){
        new_num+=s[i]*(int)pow(radix,n-i-2);
    }
    return new_num;
}

bool is_prime(int num){
    if (num==1||num==0) return false;
    else if(num==2) return true;
    int flag=true;
    for(int i=2;i<=sqrt(num);i++)
        if(num%i==0){
            flag=false;
            break;
        }
    return flag;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int num, radix;
    cin>>num;
    while(num>=0){
        cin>>radix;
        if(is_prime(reverse(num, radix))&&is_prime(num))
            cout<<"Yes\n";
        else
            cout<<"No\n";
        cin>>num;
    }
    return 0;
}
