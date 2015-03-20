//
//  main.cpp
//  PAT1067
//
//  Created by Myh on 2/24/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[100000]={};
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        int x;
        scanf("%d",&x);
        a[x]=i;
    }
    int res=0;
    if(a[0]!=0){
        a[0]=0;
        int x=a[0];
        while (x!=0){
            int y=x;
            x=a[x];
            a[y]=y;
            res++;
        }
    }
    for(int i=1;i<N;++i){
        if(a[i]!=i){
            res++;
            int z=a[i];
            int x=a[i];
            int y=x;
            x=a[x];
            a[y]=y;
            res++;
            while (x!=z){
                int y=x;
                x=a[x];
                a[y]=y;
                res++;
            }
        }
    }
    printf("%d",res);
    return 0;
}
