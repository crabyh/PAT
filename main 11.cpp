//
//  main.cpp
//  PAT1061
//
//  Created by Myh on 2/23/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    string s1, s2, s3, s4;
    cin>>s1>>s2>>s3>>s4;
    int count=0;
    for(int i=0;i<min(s1.length(),s2.length());++i){
        if(s1[i]==s2[i]&&s1[i]<='G'&&s1[i]>='A'&&count==0){
            int k=s1[i]-'A';
            switch (k) {
                case 0:
                    cout<<"MON ";
                    break;
                case 1:
                    cout<<"TUE ";
                    break;
                case 2:
                    cout<<"WED ";
                    break;
                case 3:
                    cout<<"THU ";
                    break;
                case 4:
                    cout<<"FRI ";
                    break;
                case 5:
                    cout<<"SAT ";
                    break;
                case 6:
                    cout<<"SUN ";
                    break;
            }
            count++;
        }
        else if(s1[i]==s2[i]&&count==1&&((s1[i]<='N'&&s1[i]>='A')||(s1[i]<='9'&&s1[i]>='0'))){
            if(s1[i]>='A'&&s1[i]<='N'){
                cout<<s1[i]-'A'+10<<":";
            }
            else{
                cout<<"0"<<s1[i]-'0'<<":";
            }
            break;
        }
    }
    for(int i=0;i<min(s3.length(),s4.length());++i){
        if(s3[i]==s4[i]&&((s3[i]<='Z'&&s3[i]>='A')||(s3[i]<='z'&&s3[i]>='a'))){
            if(i<=9){
                cout<<"0"<<i;
            }
            else{
                cout<<i;
            }
            break;
        }
    }
    return 0;
}
