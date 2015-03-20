//
//  main.cpp
//  PAT1011
//
//  Created by Myh on 10/5/14.
//  Copyright (c) 2014 myh. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main(int argc, const char * argv[])
{
    string s="WTL";
    double a[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> a[i][j];
        }
    }
    int flag[3]={0};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i][j]>a[i][flag[i]]){
                flag[i]=j;
            }
        }
    }
    cout<<s[flag[0]]<<" "<<s[flag[1]]<<" "<<s[flag[2]]<<" ";
    cout.setf(ios::fixed);
    cout<<setprecision(2)<<(a[0][flag[0]]*a[1][flag[1]]*a[2][flag[2]]*.65-1)*2;
    // insert code here...
    return 0;
}

