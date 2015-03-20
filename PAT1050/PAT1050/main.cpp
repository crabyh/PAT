//
//  main.cpp
//  PAT1050
//
//  Created by Myh on 2/13/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
using namespace std;
char output[11000]={};
bool c[1100]={};
int main(int argc, const char * argv[]) {
    // insert code here...
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    for(int i=0;i<str2.length();i++){
        c[str2[i]]=1;
    }
    int j=0;
    for(int i=0;i<str1.length();i++){
        if(c[str1[i]]==0){
            output[j]=str1[i];
            ++j;
        }
    }
    output[j]='\0';
    printf("%s",output);
    return 0;
}
