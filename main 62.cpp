//
//  main.cpp
//  PAT1009
//
//  Created by Myh on 10/1/14.
//  Copyright (c) 2014 myh. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, const char * argv[])
{
    double a[1001]={0}, b[1001]={0}, c[2002]={0};
    int N, index;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> index;
        cin >> a[index];
    }
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> index;
        cin >> b[index];
    }
    for(int i=0;i<1001;i++){
        if(a[i]!=0){
            for(int j=0;j<1001;j++){
                if(b[j]!=0){
                    c[i+j]+=a[i]*b[j];
                }
            }
        }
    }
    int count=0;
    for(int i=2001;i>=0;i--){
        if (c[i]!=0){
            count++;
        }
    }
    cout << count;
    cout.setf(ios::fixed);
    for(int i=2001;i>=0;i--){
        if (c[i]!=0){
            cout << setprecision(1) << " " << i << " " << c[i];
        }
    }
    // insert code here...
    return 0;
}

