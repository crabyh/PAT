//
//  main.cpp
//  PAT1010
//
//  Created by Myh on 10/2/14.
//  Copyright (c) 2014 myh. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
int main(int argc, const char * argv[])
{
    deque<char> Q1, Q2, Q3;
    char ch;
    ch=getchar();
    while(ch!=' '){
        Q1.push_back(ch);
        ch=getchar();
    }
    ch=getchar();
    while(ch!=' '){
        Q2.push_back(ch);
        ch=getchar();
    }
    int tag, radix;
    cin >> tag >> radix;
    if(tag==2){
        Q3=Q2;
        Q2=Q1;
        Q1=Q3;
    }
//    if(Q2==Q1){
//        if(Q1[0]=='1'&&Q1.size()==1){
//            cout << 2 << endl;
//        }
//        else cout << radix << endl;
//        return 0;
//    }
    long long sum=0, mul=1;
    int num;
    while(!Q1.empty()){
        num=Q1.back();
        if(num<='9')
            num-='0';
        else
            num-='a'-10;
        Q1.pop_back();
        sum+=num*mul;
        mul*=radix;
    }
    int max_digit=0;
    for(int i=(int)Q2.size()-1;i>=0;i--){
        num=Q2[i];
        if(num<='9')
            num-='0';
        else
            num-='a'-10;
        if (num>max_digit)
            max_digit=num;
    }
    if(max_digit>=36){
        cout << "Impossible" << endl;
        return 0;
    }
    if(Q2.size()==1){
        num=Q2[0];
        if(num<='9')
            num-='0';
        else
            num-='a'-10;
        if(num==sum){
            cout<<num+1<<endl;
            return 0;
        }
    }
    long long a=max_digit;
    long long b=100;
    long long c;
    for(;;){
        c=(a+b)/2;
        mul=1;
        long long new_sum=0;
        for(int i=(int)Q2.size()-1;i>=0;i--){
            num=Q2[i];
            if(num<='9')
                num-='0';
            else
                num-='a'-10;
            new_sum+=num*mul;
            mul*=c;
            if(new_sum>sum){
                b=c;
                break;
            }
        }
        if(new_sum==sum){
            cout << c << endl;
            return 0;
        }
        else if(new_sum<sum){
            a=c;
        }
        if(a==b-1||a==b){
            break;
        }
    }

    a=max_digit;
    b=1000000000000000000;
    c;
    for(;;){
        c=(a+b)/2;
        mul=1;
        long long new_sum=0;
        for(int i=(int)Q2.size()-1;i>=0;i--){
            num=Q2[i];
            if(num<='9')
                num-='0';
            else
                num-='a'-10;
            new_sum+=num*mul;
            mul*=c;
            if(new_sum>sum){
                b=c;
                break;
            }
        }
        if(new_sum==sum){
            cout << c << endl;
            return 0;
        }
        else if(new_sum<sum){
            a=c;
        }
        if(a==b-1||a==b){
            break;
        }
    }
    cout << "Impossible" << endl;
    // insert code here...
    return 0;
}

