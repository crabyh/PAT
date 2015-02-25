//
//  main.cpp
//  PAT1031
//
//  Created by Myh on 2/10/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    string s;
    cin>>s;
    int N=s.length();
    int n1,n2,n3;
    n1=n3=(N-1)/3;
    n2=N-n1-n3;
    for(int i=0;i<n1;i++){
        cout<<s[i];
        for(int j=0;j<n2-2;j++){
            cout<<" ";
        }
        cout<<s[N-1-i]<<endl;
    }
    cout<<s.substr(n1,n2)<<endl;
    return 0;
}
