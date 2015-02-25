//
//  main.cpp
//  PAT1065
//
//  Created by Myh on 2/23/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin>>N;
    int flag;
    for(int ri=0;ri<N;++ri){
        flag=0;
        int minus[4]={};
        unsigned long long num[4];
        for(int i=0;i<3;i++){
            string str;
            cin>>str;
            if(str[0]=='-'){
                minus[i]=1;
                num[i]=stoull(str.substr(1));
            }
            else{
                num[i]=stoull(str.substr(0));
            }
        }
    
        if(num[0]>num[1]){
            minus[3]=minus[0];
            if(minus[0]==minus[1]){
                num[3]=num[0]+num[1];
            }
            else{
                num[3]=num[0]-num[1];
            }
        }
        else{
            minus[3]=minus[1];
            if(minus[0]==minus[1]){
                num[3]=num[0]+num[1];
            }
            else{
                num[3]=num[1]-num[0];
            }
        }
        if(minus[3]<minus[2]){
            flag=1;
        }
        else if(minus[3]==minus[2]&&minus[3]==0){
            flag=num[3]>num[2];
        }
        else if(minus[3]==minus[2]&&minus[3]==1){
            flag=num[3]<num[2];
        }
        if(num[0]==9223372036854775808&&num[1]==9223372036854775808){
            if(minus[0]==0&&minus[1]==0){
                flag=true;
            }
            else if(minus[0]==1&&minus[1]==1){
                flag=false;
            }
            else{
                flag=minus[2];
            }
        }
        cout<<"Case #"<<ri+1<<": ";
        if(flag==1){
            cout<<"true"<<endl;
        }
        else cout<<"false"<<endl;
    }
    return 0;
}
