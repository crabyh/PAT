//
//  main.cpp
//  PAT1078
//
//  Created by Myh on 2/25/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int prime(int x){
    if(x<=2)
        return 2;
    int flag=1;
    for(int i=2;i<=(int)sqrt(x)+1;++i){
        if(x%i==0){
            flag=0;
            break;
        }
    }
    if(flag==0)
        return prime(x+1);
    else return x;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int size, N;
    int a[10010]={};
    cin>>size>>N;
    size=prime(size);
    int x;
    cin>>x;
    cout<<x%size;
    a[x%size]=1;
    for(int i=1;i<N;++i){
        int x;
        cin>>x;
        int flag=0;
        for(int j=0;j<size;++j){
            if(a[(x+j*j)%size]==0){
                cout<<" "<<(x+j*j)%size;
                a[(x+j*j)%size]=1;
                flag=1;
                break;
            }
        }
        if(flag==1) continue;
        cout<<" -";
    }
    
    return 0;
}
