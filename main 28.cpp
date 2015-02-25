//
//  main.cpp
//  PAT1027
//
//  Created by Myh on 2/9/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
string f(int num){
    string s="";
    while(num!=0){
        if(num%13<10){
            char ch='0'+num%13;
            s=ch+s;
            num/=13;
        }
        if(num%13>=10){
            char ch='A'+num%13-10;
            s=ch+s;
            num/=13;
        }
    }
    while(s.length()<2)
        s="0"+s;
    return s;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int red, green, blue;
    cin>>red>>green>>blue;
    cout<<"#"<<f(red)<<f(green)<<f(blue);
    return 0;
}
