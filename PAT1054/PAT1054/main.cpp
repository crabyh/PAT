//
//  main.cpp
//  PAT1054
//
//  Created by Myh on 2/15/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int M,N;
    cin>>M>>N;
    map<int,int> m;
    for(int i=0;i<M;++i){
        for(int j=0;j<N;++j){
            int x;
            scanf("%d",&x);
            if(m.count(x)){
                m[x]++;
                if(m[x]>M*N/2){
                    cout<<x;
                    return 0;
                }
            }
            else{
                m[x]=1;
                if(m[x]>M*N/2){
                    cout<<x;
                    return 0;
                }
            }
        }
    }
    return 0;
}
