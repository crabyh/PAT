//
//  main.cpp
//  PAT1071
//
//  Created by Myh on 2/24/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
inline int is_alpha(char ch){
    if((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
        return 1;
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string str;
    map<string, int> m;
    getline(cin,str);
//    str=str.substr(str.find_first_of('"')+1,str.find_last_of('"')-str.find_first_of('"')-1);
    int i=0;
    while(i<str.length()){
        while(is_alpha(str[i])!=1){
            i++;
        }
        string word;
        while (is_alpha(str[i])==1) {
            if(str[i]>='A'&&str[i]<='Z')
                word+=str[i]-'A'+'a';
            else
                word+=str[i];
            i++;
        }
        m[word]++;
    }
    int max=0;
    map<string,int>::iterator it;
    for(it=m.begin();it!=m.end();++it){
        if (it->second>max){
            max=it->second;
        }
    }
    vector<string> v;
    for(it=m.begin();it!=m.end();++it){
        if (it->second==max){
            v.push_back(it->first);
        }
    }
    sort(v.begin(),v.end());
    cout<<v[0]<<" "<<max;
    return 0;
}
