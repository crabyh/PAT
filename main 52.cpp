//
//  main.cpp
//  PAT1040
//
//  Created by Myh on 2/12/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    string s;
    getline(std::cin,s);
    int max_l=1;
    for(int i=1;i<s.length()-1;i++){
        if(s[i-1]==s[i+1]){
            int k=0;
            while(i-k>=0&&i+k<s.length()){
                if(s[i-k]==s[i+k]){
                    k++;
                }
                else break;
            }
            if(2*k-1>max_l){
                max_l=2*k-1;
            }
        }
        if(s[i-1]==s[i]){
            int k=0;
            while(i-k-1>=0&&i+k<s.length()){
                if(s[i-k-1]==s[i+k]){
                    k++;
                }
                else break;
            }
            if(2*k>max_l){
                max_l=2*k;
            }
        }
    }
    if(s[s.length()-2]==s[s.length()-1]){
        if(max_l<2)
            max_l=2;
    }
    cout<<max_l;
    return 0;
}
