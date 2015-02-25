//
//  main.cpp
//  PAT1073
//
//  Created by Myh on 2/25/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    char ch1,ch2,ch;
    int digit,exp=0;
    string s;
    cin>>ch1>>digit>>ch>>s;
    if(s.find('-')!=-1){
        ch2='-';
        exp=stoi(s.substr(s.find('-')+1));
    }
    else if(s.find('+')!=-1){
        ch2='+';
        exp=stoi(s.substr(s.find('+')+1));
    }
    s=s.substr(0,s.find('E'));
    if(ch1=='-'){
        cout<<"-";
    }
    if(ch2=='-'){
        cout<<"0.";
        for(int i=0;i<exp-1;++i){
            cout<<"0";
        }
        cout<<digit<<s;
    }
    else if(s.length()>exp){
        cout<<digit<<s.substr(0,exp)<<"."<<s.substr(exp);
    }
    else{
        cout<<digit<<s;
        for(int i=(int)s.length();i<exp;++i){
            cout<<"0";
        }
    }
    return 0;
}
