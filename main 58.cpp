//
//  main.cpp
//  PAT1005
//
//  Created by Myh on 9/28/14.
//  Copyright (c) 2014 myh. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
string num_to_eng[11]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main(int argc, const char * argv[])
{
    deque<int> Q;
    int sum=0;
    char ch=getchar();
    if(ch=='0'){
        cout << num_to_eng[0];
        return 0;
    }
    while(ch!='\n'){
       sum+=ch-'0';
        ch=getchar();
    }
    while(sum!=0){
        Q.push_back(sum%10);
        sum/=10;
    }
    cout << num_to_eng[Q.back()];
    Q.pop_back();
    while(Q.size()>0){
        cout << " " << num_to_eng[Q.back()];
        Q.pop_back();
    }
    return 0;
}

