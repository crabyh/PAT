//
//  main.cpp
//  PAT1023
//
//  Created by Myh on 2/7/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[10]={};
    int b[10]={};
    deque<int> x,y;
    char ch;
    int num;
    ch=getchar();
    while(ch!='\n'){
        num=ch-'0';
        x.push_back(num);
        a[num]++;
        ch=getchar();
    }
    int carrier=0;
    for(int i=(int)x.size()-1;i>=0;i--){
        num=x[i]*2+carrier;
        if(num>=10){
            carrier=1;
            num-=10;
        }
        else
            carrier=0;
        y.push_front(num);
        b[num]++;
    }
    if(carrier==1)
        y.push_front(carrier);
    bool flag=1;
    for(int i=0;i<10;i++){
        if(a[i]!=b[i]){
            flag=0;
            break;
        }
    }
    if(flag==0)
        cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    for(int i=0;i<y.size();i++){
        cout<<y[i];
    }
    return 0;
}
