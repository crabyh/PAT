//
//  main.cpp
//  PAT1060
//
//  Created by Myh on 2/17/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    string s1,s2;
    string res1,res2;
    int index1,index2;
    int n;
    cin>>n>>s1>>s2;
    if(s1.find('.')){
        index1=(int)s1.find('.');
        if(s1[0]=='0')
            index1--;
        res1=s1.substr(0,s1.find('.'))+s1.substr(s1.find('.')+1);
        res1=res1.substr()
    }
    return 0;
}
