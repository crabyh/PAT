//
//  main.cpp
//  PAT1032
//
//  Created by Myh on 2/10/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
int a[100000][2];
int main(int argc, const char * argv[]) {
    // insert code here...
    for(int i=0;i<100000;i++){
        a[i][0]=a[i][1]=-1;
    }
    int a1,a2,N;
    cin>>a1>>a2>>N;
    for(int i=0;i<N;i++){
        int x,y;
        char ch;
        cin>>x>>ch>>y;
        a[x][0]=y;
    }
    while(a1!=-1){
        a[a1][1]=1;
        a1=a[a1][0];
    }
    while(a2!=-1){
        if(a[a2][1]==1){
            break;
        }
        a2=a[a2][0];
    }
    if(a2!=-1){
        cout.fill('0');//设置填充字符
        cout.width(5);//设置域宽
    }
    cout<<a2<<endl;
    return 0;
}
