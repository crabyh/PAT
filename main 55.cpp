//
//  main.cpp
//  PAT1035
//
//  Created by Myh on 2/12/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
#include <string>
using namespace std;
class C{
public:
    string user;
    string pwd;
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin>>N;
    deque <C> q;
    for(int i=0;i<N;++i){
        C c;
        cin>>c.user>>c.pwd;
        q.push_back(c);
    }
    deque<C> res;
    for(int i=0;i<q.size();++i){
        C c=q[i];
        int flag=0;
        for(int j=0;j<c.pwd.length();j++){
            if(c.pwd[j]=='1'){
                c.pwd[j]='@';
                flag=1;
            }
            else if(c.pwd[j]=='0'){
                c.pwd[j]='%';
                flag=1;
            }
            else if(c.pwd[j]=='l'){
                c.pwd[j]='L';
                flag=1;
            }
            else if(c.pwd[j]=='O'){
                c.pwd[j]='o';
                flag=1;
            }
        }
        if (flag==1){
            res.push_back(c);
        }
    }
    if(res.size()==0){
        if(N==1){
            cout<<"There is 1 account and no account is modified"<<endl;
        }
        else{
            cout<<"There are "<<N<<" accounts and no account is modified"<<endl;
        }
    }
    else{
        cout<<res.size()<<endl;
        for(int i=0;i<res.size();i++){
            cout<<res[i].user<<" "<<res[i].pwd<<endl;
        }
    }
    
    
    
    
    
    return 0;
}
